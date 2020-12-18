//
// Created by Kaleigh Spitzer on 11/14/20.
//

#include <numeric>
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"

using namespace idealgas;

size_t numParticles = 15;
std::vector<Particle> particles;

size_t minWidth = 115;
size_t maxWidth = 685;
size_t minHeight = 115;
size_t maxHeight = 685;


IdealGasApp::IdealGasApp() {
    setWindowSize(800, 800);
}

void IdealGasApp::setup() {

    for (size_t i = 0; i < numParticles; i++) {
        particles.push_back(Particle({rand() % 500 + 120, rand() % 500 + 120}));
        std::cout << particles.at(i).position << std::endl;
    }

    for (Particle& particle : particles) {
        particle.velocity = {2, 2};
        std::cout << particle.position << std::endl;
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
        if (glm::distance(particle1.position, particle2.position) <= radiusSum) {
            float mag = (glm::length2(particle1.position - particle2.position));
            float mag2 = (glm::length2(particle2.position - particle1.position));
            if (P1positionXCoord == P2positionXCoord && P1positionYCoord == P2positionYCoord) {
                mag = 1;
                mag2 = 1;
            }
            newP1Velocity = particle1.velocity - ((glm::dot((particle1.velocity - particle2.velocity), (particle1.position - particle2.position))) / (mag) * (particle1.position - particle2.position));
            newP2Velocity = particle2.velocity - ((glm::dot((particle2.velocity - particle1.velocity),
                                                             (particle2.position - particle1.position)) /
                                                    (mag2)) *
                                                   (particle2.position - particle1.position));
            particle1.velocity = newP1Velocity;
            particle2.velocity = newP2Velocity;

        }
    }
}

void IdealGasApp::update() {
    for (Particle& particle : particles) {
        particle.update();
        changeVelocity(particle, particle, true);


    }

    for (Particle particle1 : particles) {
        for (Particle particle2 : particles) {

            if (particle1.Compare(particle2) == 0) {
                continue;
            }

            changeVelocity(particle1, particle2, false);

        }
    }


}

void IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(100, 100, 700, 700);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
    for (Particle particle : particles) {
        particle.draw();
    }
}

CINDER_APP(IdealGasApp, ci::app::RendererGl)
