//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/blue_particle.h"

namespace idealgas {
    BlueParticle::BlueParticle() : Particle() {
        mass_ = 1;
        SetMass(mass_);
        radius_ = 10.0f;
        SetRadius(radius_);
        velocity_ = {5, 5};
        SetVelocity(velocity_);
        color_ = {0, 0, 1};
        SetColor(color_);
    }
}