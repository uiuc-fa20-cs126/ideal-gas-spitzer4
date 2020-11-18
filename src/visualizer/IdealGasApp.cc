//
// Created by Kaleigh Spitzer on 11/14/20.
//

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/simulation.h"

using namespace idealgas;

idealgas::Particle particle1({60, 60});
idealgas::Particle particle2({100, 100});

IdealGasApp::IdealGasApp() {
    setWindowSize(600, 600);
}

void IdealGasApp::setup() {
    particle1.position = {60, 60};
    particle1.velocity = {2.0, 2.0};
}

void IdealGasApp::changeVelocity(idealgas::Particle particle) {
    float velocityXCoord = particle.velocity.operator[](0);
    float velocityYCoord = particle.velocity.operator[](1);
    float positionXCoord = particle.position.operator[](0);
    float positionYCoord = particle.position.operator[](1);
    if (positionXCoord > getWindowWidth() || positionXCoord < 0) {
        velocityXCoord = - velocityXCoord;
    }
    if (positionYCoord > getWindowHeight() || positionYCoord < 0) {
        velocityYCoord = - velocityYCoord;
    }
    particle.velocity = {velocityXCoord, velocityYCoord};
}

void IdealGasApp::update() {
    if (particle1.position.operator[](0) < 0 || particle1.position.operator[](0) > getWindowWidth()) {
        changeVelocity(particle1);
    }
    if (particle1.position.operator[](1) < 0 || particle1.position.operator[](1) > getWindowHeight()) {
        changeVelocity(particle1);
    }
    particle1.update();
    //changeVelocity(particle2);

    float velocityXCoord = particle1.velocity.operator[](0);
    float velocityYCoord = particle1.velocity.operator[](1);
    float positionXCoord = particle1.position.operator[](0);
    float positionYCoord = particle1.position.operator[](1);
    glm::vec2 newVelocity;
    if (positionXCoord > getWindowWidth() || positionXCoord < 0) {
        velocityXCoord = - velocityXCoord;
    }
    if (positionYCoord > getWindowHeight() || positionYCoord < 0) {
        velocityYCoord = - velocityYCoord;
    }
    particle1.velocity = {velocityXCoord, velocityYCoord};
}

void IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    particle1.draw();
    //particle2.draw();
}

CINDER_APP(IdealGasApp, ci::app::RendererGl)
