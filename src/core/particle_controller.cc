//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle_controller.h"

ParticleController::ParticleController() {

}
void ParticleController::update() {
    for (std::vector<idealgas::Particle>::iterator i = particles.begin(); i != particles.end(); ++i) {
        i->update();
    }
}
void ParticleController::draw() {
    for (auto&& p : particles) {
        p.draw();
    }
}
void ParticleController::addParticles(int x, int y) {
    particles.push_back(idealgas::Particle({x, y}));
}
void ParticleController::removeParticles() {
    particles.pop_back();
}