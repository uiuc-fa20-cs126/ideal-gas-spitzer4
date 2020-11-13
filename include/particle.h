//
// Created by Kaleigh Spitzer on 11/13/20.
//

#ifndef IDEAL_GAS_SPITZER4_PARTICLE_H
#define IDEAL_GAS_SPITZER4_PARTICLE_H

#include "cinder/gl/gl.h"
#include "cinder/Vector.h"

class Particle {
    ci::Vec2f position;
    float radius;
    float direction;
    ci::Vec2f velocity;
    Particle(Vec2f location);
    void Particle::update();
    void Particle::draw();
};

#endif //IDEAL_GAS_SPITZER4_PARTICLE_H
