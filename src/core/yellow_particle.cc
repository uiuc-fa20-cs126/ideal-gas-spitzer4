//
// Created by Kaleigh Spitzer on 1/28/21.
//

#include "core/yellow_particle.h"

namespace idealgas {
    YellowParticle::YellowParticle() {
        mass_ = 5;
        velocity_ = {1, 1};
        radius_ = 20.0f;
        position_ = {rand() % 500 + 120, rand() % 500 + 120};
    }

    void YellowParticle::Draw() {
        ci::gl::color(1, 1, 0);
        ci::gl::drawSolidCircle(position_, radius_);
    }
}