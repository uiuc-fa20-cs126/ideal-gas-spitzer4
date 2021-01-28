//
// Created by Kaleigh Spitzer on 1/28/21.
//

#ifndef IDEAL_GAS_BLUE_PARTICLE_H
#define IDEAL_GAS_BLUE_PARTICLE_H

#include "particle.h"

namespace idealgas {
    class BlueParticle : public Particle {
    public:
        BlueParticle();
    private:
        double mass_;
        float radius_;
        glm::vec2 velocity_;
    };
}

#endif //IDEAL_GAS_BLUE_PARTICLE_H
