//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/red_particle.h"

namespace idealgas {
    RedParticle::RedParticle() : Particle() {
        mass_ = 3;
        SetMass(mass_);
        radius_ = 15.0f;
        SetRadius(radius_);
        velocity_ = {3, 3};
        SetVelocity(velocity_);
    }

    void RedParticle::Draw() {
        ci::gl::color(1, 0, 0);
        position_ = GetPosition();
        ci::gl::drawSolidCircle(position_, radius_);
    }
}