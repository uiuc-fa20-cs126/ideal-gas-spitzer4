//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/blue_particle.h"

namespace idealgas {
    BlueParticle::BlueParticle() {
        mass_ = 1;
        velocity_ = {5, 5};
        radius_ = 10.0f;
        position_ = {rand() % 500 + 120, rand() % 500 + 120};
    }

    void BlueParticle::Draw() {
        ci::gl::color(0, 0, 1);
        ci::gl::drawSolidCircle(position_, radius_);
    }
}