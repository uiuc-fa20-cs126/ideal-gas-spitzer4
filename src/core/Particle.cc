//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include "../../include/core/Particle.h"

//namespace idealgas {
    Particle::Particle() {
        position = {rand() % 500 + 120, rand() % 500 + 120};
        direction = static_cast<float>(rand());
        velocity = glm::vec2(static_cast<float>(rand()), static_cast<float>(rand()));
        radius = 15.0f;
    }

    void Particle::Update() {
        position += velocity;
        time = time + 1;
    }

    void Particle::Draw() {
        ci::gl::color(0, 0, 1);
        ci::gl::drawSolidCircle(position, radius);
    }

    bool Particle::IsCollision(const Particle &particle2) {
        glm::vec2 position_diff = position - particle2.position;
        glm::vec2 velocity_diff = velocity - particle2.velocity;
        double dot_product = glm::dot(position_diff, velocity_diff);
        double dist = sqrt(pow(position.x - particle2.position.x, 2) + pow(position.y - particle2.position.y, 2));
        if (dist <= (radius + particle2.radius) && dot_product < 0) {
            return true;
        }
        return false;
    }
//}