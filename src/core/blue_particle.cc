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
    }

    void BlueParticle::Draw() {
        ci::gl::color(0, 0, 1);
        position_ = GetPosition();
        ci::gl::drawSolidCircle(position_, radius_);
    }
}