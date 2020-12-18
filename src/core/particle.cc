//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle.h"

namespace idealgas {
    Particle::Particle(glm::vec2 new_position) {
        position = new_position;
        direction = static_cast <float>(rand());
        velocity = glm::vec2(static_cast<float>(rand()), static_cast<float>(rand()));
        radius = 15.0f;
    }

    void Particle::update() {
        position += velocity;
        time = time + 1;
    }

    void Particle::draw() {
//        double red = rand() % 2;
//        double green = rand() % 2;
//        double blue = rand() % 2;
//        if (red == 0 && green == 0 && blue == 0) {
//            blue = 1;
//        }
//        ci::gl::color(ci::Color(red, green, blue));
        ci::gl::color(ci::Color(0, 0, 1));
        ci::gl::drawSolidCircle(position, radius);
    }

    size_t Particle::Compare(const Particle& particle) {
        if (position == particle.position && direction == particle.direction && velocity == particle.velocity) {
            return 0;
        } else {
            return 1;
        }
    }

    Particle::Particle() {

    }
} // namespace idealgas
