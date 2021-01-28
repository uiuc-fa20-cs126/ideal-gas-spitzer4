//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/red_particle.h"

namespace idealgas {
    RedParticle::RedParticle() {
        mass_ = 3;
        velocity_ = {3, 3};
        radius_ = 15.0f;
    }
}