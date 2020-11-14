//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle_controller.h"

ParticleController::ParticleController() {

}
void ParticleController::update() {
    for (std::vector<Particle>::iterator i = particles.begin(); I != particles.end(); ++i) {
        i->update();
    }
}
void ParticleController::draw() {

}
void ParticleController::addParticles(int x, int y) {
    particles.push_back(Particle({x, y}));
}
void ParticleController::removeParticles() {
    particles.pop_back();
}