//
// Created by Kaleigh Spitzer on 11/14/20.
//

#include <numeric>
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"

using namespace idealgas;

//idealgas::Particle particle1({60, 60});
//idealgas::Particle particle2({100, 100});
size_t numParticles = 5;
std::vector<Particle> particles;

size_t minWidth = 115;
size_t maxWidth = 685;
size_t minHeight = 115;
size_t maxHeight = 685;

//idealgas::Particle particle1({rand() % 600 + 1, rand() % 600 + 1});
//idealgas::Particle particle2({rand() % 600 + 1, rand() % 600 + 1});

IdealGasApp::IdealGasApp() {
    setWindowSize(800, 800);
}

void IdealGasApp::setup() {
//    particle1.position = {rand() % 601, rand() % 601};
//    particle1.velocity = {2.0, 2.0};
//    particle2.position = {rand() % 601, rand() % 601};
//    particle2.velocity = {2.0, 3.0};

    for (size_t i = 0; i < numParticles; i++) {
        particles.push_back(Particle({rand() % 680 + 110, rand() % 680 + 110}));
    }

    for (Particle& particle : particles) {
        particle.position = {rand() % 680 + 110, rand() % 680 + 110};
        particle.velocity = {2, 2};
    }
}

void IdealGasApp::changeVelocity(idealgas::Particle& particle1, idealgas::Particle& particle2, bool isWallCollision) {
    glm::vec2 newP1Velocity;
    glm::vec2 newP2Velocity;
    if (isWallCollision) {
        float velocityXCoord = particle1.velocity.operator[](0);
        float velocityYCoord = particle1.velocity.operator[](1);
        float positionXCoord = particle1.position.operator[](0);
        float positionYCoord = particle1.position.operator[](1);
        if (positionXCoord > maxWidth || positionXCoord < minWidth) {
            velocityXCoord = -velocityXCoord;
        }
        if (positionYCoord > maxHeight || positionYCoord < minHeight) {
            velocityYCoord = -velocityYCoord;
        }
        particle1.velocity = {velocityXCoord, velocityYCoord};
    } else {
        float P1positionXCoord = particle1.position.operator[](0);
        float P1positionYCoord = particle1.position.operator[](1);
        float P2positionXCoord = particle2.position.operator[](0);
        float P2positionYCoord = particle2.position.operator[](1);
        float radiusSum = (particle1.radius + particle2.radius);
//        std::cout << particle1.velocity - ((glm::dot((particle1.velocity - particle2.velocity),
//                                                             (particle1.position - particle2.position)) /
//                                                    ((glm::length2(particle1.position - particle2.position)))) *
//                                                   (particle1.position - particle2.position)) << std::endl;
        if ((abs(P1positionXCoord - P2positionXCoord) <= (radiusSum)) || (abs(P1positionYCoord - P2positionYCoord) <= (radiusSum))) {
            newP1Velocity = particle1.velocity - ((glm::dot((particle1.velocity - particle2.velocity),
                                                             (particle1.position - particle2.position)) /
                                                    ((glm::length2(particle1.position - particle2.position)))) *
                                                   (particle1.position - particle2.position));
            newP2Velocity = particle2.velocity - ((glm::dot((particle2.velocity - particle1.velocity),
                                                             (particle2.position - particle1.position)) /
                                                    ((glm::length2(particle2.position - particle1.position)))) *
                                                   (particle2.position - particle1.position));
            particle1.velocity = newP1Velocity;
            particle2.velocity = newP2Velocity;
         }
     }
}

void IdealGasApp::update() {
    for (Particle& particle : particles) {
        //
        particle.update();
        changeVelocity(particle, particle, true);


    }

//    for (std::vector<Particle>::iterator it = particles.begin(); it < particles.end() - 1; ++it) {
//        for (std::vector<Particle>::iterator it2 = it + 1; it2 < particles.end(); ++it2) {
//            it->update();
//            it2->update();
//            changeVelocity(*it, *it, true);
//            changeVelocity(*it2, *it2, true);
//            changeVelocity(*it, *it2, false);
//        }
//    }
    for (Particle particle1 : particles) {
        for (Particle particle2 : particles) {
            if (particle1 == particle2) {

            }
            particle1.update();
            particle2.update();
//            float P1positionXCoord = particle1.position.operator[](0);
//            float P1positionYCoord = particle1.position.operator[](1);
//            float P2positionXCoord = particle2.position.operator[](0);
//            float P2positionYCoord = particle2.position.operator[](1);
//            float radiusSum = (particle1.radius + particle2.radius) / 2;
//            if ((abs(P1positionXCoord - P2positionXCoord) <= (radiusSum)) ||
//                (abs(P1positionYCoord - P2positionYCoord) <= (radiusSum))) {
            changeVelocity(particle1, particle2, false);
                //                particle1.update();
                //                particle2.update();
//            }
            particle1.update();
            particle2.update();
        }
    }

//        changeVelocity(particle, particle, true);
//        particle.update();

//        // Added
//        for (Particle particle2 : particles) {
//            particle2.update();
//            changeVelocity(particle, particle2, false);
//        }



//    for (size_t i = 0; i < particles.size(); i++) {
//        for (size_t j = 0; j < particles.size(); j++) {
//            changeVelocity(particles.at(i), particles.at(j), false);
//        }
//    }

//    particle1.update();
//    particle2.update();
//    changeVelocity(particle1, particle1, true);
//    changeVelocity(particle2, particle2, true);
}

void IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(100, 100, 700, 700);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
//    ci::gl::clear(ci::Color(0, 0, 0));
//    ci::gl::color(ci::Color(0, 0, 0));
//    particle1.draw();
//    particle2.draw();
    ci::gl::color(ci::Color(0, 0, 1));
    for (Particle particle : particles) {
        particle.draw();
    }
}

CINDER_APP(IdealGasApp, ci::app::RendererGl)
