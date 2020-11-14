//
// Created by Kaleigh Spitzer on 11/13/20.
//

#ifndef IDEAL_GAS_SPITZER4_PARTICLE_H
#define IDEAL_GAS_SPITZER4_PARTICLE_H

#include "cinder/gl/gl.h"
#include "cinder/Vector.h"

class Particle {
    glm::vec2 position;
    float radius;
    float direction;
    glm::vec2 velocity;
    Particle(glm::vec2 start_location);
    void Particle::update();
    void Particle::draw();
};

#endif //IDEAL_GAS_SPITZER4_PARTICLE_H
