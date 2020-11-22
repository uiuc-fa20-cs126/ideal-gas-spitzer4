//
// Created by Kaleigh Spitzer on 11/14/20.
//

#include <numeric>
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"

using namespace idealgas;

//idealgas::Particle particle1({60, 60});
//idealgas::Particle particle2({100, 100});
idealgas::Particle particle1({rand() % 601, rand() % 601});
idealgas::Particle particle2({rand() % 601, rand() % 601});

size_t minWidth = 115;
size_t maxWidth = 685;
size_t minHeight = 115;
size_t maxHeight = 685;

IdealGasApp::IdealGasApp() {
    setWindowSize(800, 800);
}

void IdealGasApp::setup() {
//    particle1.position = {60, 60};
    particle1.position = {rand() % 601, rand() % 601};
    particle1.velocity = {2.0, 2.0};
//    particle2.position = {100, 100};
    particle2.position = {rand() % 601, rand() % 601};
    particle2.velocity = {2.0, 3.0};
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
         if ((abs(P1positionXCoord - P2positionXCoord) <= (particle1.radius + particle2.radius)) || (abs(P1positionYCoord - P2positionYCoord) <= (particle1.radius + particle2.radius))) {
             newP1Velocity = particle1.velocity - ((glm::dot((particle1.velocity - particle2.velocity),
                                                             (particle1.position - particle2.position)) /
                                                    (glm::length2(particle1.position - particle2.position))) *
                                                   (particle1.position - particle2.position));
             newP2Velocity = particle2.velocity - ((glm::dot((particle2.velocity - particle1.velocity),
                                                             (particle2.position - particle1.position)) /
                                                    (glm::length2(particle2.position - particle1.position))) *
                                                   (particle2.position - particle1.position));
             particle1.velocity = newP1Velocity;
             particle2.velocity = newP2Velocity;
         }
     }
}

void IdealGasApp::update() {
    particle1.update();
    particle2.update();
    changeVelocity(particle1, particle1, true);
    changeVelocity(particle2, particle2, true);
}

void IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(100, 100, 700, 700);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
//    ci::gl::clear(ci::Color(0, 0, 0));
//    ci::gl::color(ci::Color(0, 0, 0));
    particle1.draw();
    particle2.draw();
}

CINDER_APP(IdealGasApp, ci::app::RendererGl)
