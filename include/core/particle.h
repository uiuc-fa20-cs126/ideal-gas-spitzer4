//
// Created by Kaleigh Spitzer on 11/13/20.
//

#ifndef IDEAL_GAS_SPITZER4_PARTICLE_H
#define IDEAL_GAS_SPITZER4_PARTICLE_H

#include "cinder/gl/gl.h"
#include "cinder/Vector.h"

class Particle {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
    float direction;
    float time;
    Particle(glm::vec2 start_position);
    void update();
    void draw();
};

#endif //IDEAL_GAS_SPITZER4_PARTICLE_H
