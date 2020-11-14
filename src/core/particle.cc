//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle.h"

namespace idealgas {
    Particle::Particle(glm::vec2 new_position) {
        position = new_position;
        direction = static_cast <float>(rand());
        velocity = glm::vec2(static_cast<float>(rand()), static_cast<float>(rand()));
        radius = 5.0f;
    }

    void Particle::update() {
        position += velocity;
        time = time + 1;
    }

    void Particle::draw() {
        cinder::gl::drawSolidCircle(position, radius);
    }
} // namespace idealgas