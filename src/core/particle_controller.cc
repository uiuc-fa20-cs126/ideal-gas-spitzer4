//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle_controller.h"

ParticleController::ParticleController() {

}
void ParticleController::update() {
    for (std::vector<particle>::iterator i = particles.begin(); p != particles.end(); ++p) {
        i->update();
    }
}
void ParticleController::draw() {

}
void ParticleController::addParticles(int x, int y) {
    particles.push_back(particle({x, y}));
}
void ParticleController::removeParticles() {
    particles.pop_back(particle({x, y}));
}