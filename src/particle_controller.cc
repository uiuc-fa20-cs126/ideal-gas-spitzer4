//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../include/particle_controller.h"

ParticleController::ParticleController() {

}
void ParticleController::update() {
    for (std::list<particle>::iterator i = particles.begin(); p != particles.end(); ++p) {
        i->update();
    }
}
void ParticleController::draw() {

}
void ParticleController::addParticles() {

}
void ParticleController::removeParticles() {

}