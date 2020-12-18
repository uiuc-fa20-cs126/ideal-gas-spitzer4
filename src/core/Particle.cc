//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include "../../include/core/Particle.h"

namespace idealgas {
    Particle::Particle() {
        position = {300, 300}; // TODO: Use rand to initialize position based on boundary
        direction = static_cast<float>(rand());
        velocity = glm::vec2(static_cast<float>(rand()), static_cast<float>(rand()));
        radius = 15.0f;
    }

    void Particle::update() {
        position += velocity;
        time = time + 1;
    }

    void Particle::draw() {
        ci::gl::color(0, 0, 1);
        ci::gl::drawSolidCircle(position, radius);
    }
}