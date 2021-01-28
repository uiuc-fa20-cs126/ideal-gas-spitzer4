//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/yellow_particle.h"

namespace idealgas {
    YellowParticle::YellowParticle() {
        mass_ = 5;
        velocity = {1, 1};
        radius_ = 20.0f;
    }
}