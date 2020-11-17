//
// Created by Kaleigh Spitzer on 11/14/20.
//

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/simulation.h"

using namespace idealgas;

idealgas::Particle particle1({60, 60});

IdealGasApp::IdealGasApp() {
    setWindowSize(600, 600);
}

void IdealGasApp::setup() {
    particle1.position = {60, 60};
    particle1.velocity = {2.0, 2.0};
}
void IdealGasApp::update() {
    idealgas::Simulation::changeVelocity(particle1);
    particle1.update();
}

void IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    particle1.draw();
}

CINDER_APP(IdealGasApp, ci::app::RendererGl)
