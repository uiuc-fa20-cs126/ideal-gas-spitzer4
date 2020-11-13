//
// Created by Kaleigh Spitzer on 11/13/20.
//

#ifndef IDEAL_GAS_SPITZER4_PARTICLE_CONTROLLER_H
#define IDEAL_GAS_SPITZER4_PARTICLE_CONTROLLER_H

#include "particle.h"
#include <list>

class ParticleController {
public:
    ParticleController();
    void update();
    void draw();
    void addParticles();
    void removeParticles();
    std::list<Particle> particles;
};

#endif //IDEAL_GAS_SPITZER4_PARTICLE_CONTROLLER_H
