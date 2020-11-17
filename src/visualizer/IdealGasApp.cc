//
// Created by Kaleigh Spitzer on 11/14/20.
//

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/simulation.h"

using namespace idealgas;

idealgas::Particle particle1({600, 2});

void IdealGasApp::setup() {
    setWindowSize(600, 600);
}
void IdealGasApp::update() {
    idealgas::Simulation::changeVelocity(particle1);
}

void IdealGasApp::draw() {

}

CINDER_APP(IdealGasApp, ci::app::RendererGl)
