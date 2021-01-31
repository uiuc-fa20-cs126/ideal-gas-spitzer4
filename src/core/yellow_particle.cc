//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/yellow_particle.h"

namespace idealgas {
    YellowParticle::YellowParticle() : Particle() {
        mass_ = 5;
        SetMass(mass_);
        radius_ = 20.0f;
        SetRadius(radius_);
        velocity_ = {1, 1};
        SetVelocity(velocity_);
        color_ = {1, 1, 0};
        SetColor(color_);
    }
}