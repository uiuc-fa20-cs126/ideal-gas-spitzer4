//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/red_particle.h"

namespace idealgas {
    RedParticle::RedParticle() {
        mass_ = 3;
        velocity_ = {3, 3};
        radius_ = 15.0f;
        position_ = {rand() % 500 + 120, rand() % 500 + 120};
    }

    void RedParticle::Draw() {
        ci::gl::color(1, 0, 0);
        ci::gl::drawSolidCircle(position_, radius_);
    }
}