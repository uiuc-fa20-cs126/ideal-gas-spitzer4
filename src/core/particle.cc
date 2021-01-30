//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include "../../include/core/particle.h"
#include "../../include/visualizer/ideal_gas_app.h"

Particle::Particle() {
    position = {rand() % 500 + 120, rand() % 500 + 120};
    direction = static_cast<float>(rand());
    velocity = glm::vec2(static_cast<float>(rand()), static_cast<float>(rand()));
}

void Particle::Update() {
    position += velocity;
    time = time + 1;
}

//void Particle::Draw() {
//    ci::gl::color(0, 0, 1);
//    ci::gl::drawSolidCircle(position, radius);
//}

bool Particle::IsParticleCollision(const Particle &particle2) {
    glm::vec2 position_diff = position - particle2.position;
    glm::vec2 velocity_diff = velocity - particle2.velocity;
    double dot_product = glm::dot(position_diff, velocity_diff);
    double dist = sqrt(pow(position.x - particle2.position.x, 2) + pow(position.y - particle2.position.y, 2));
    if (dist <= (radius + particle2.radius) && dot_product < 0) {
        return true;
    }
    return false;
}

void Particle::WallCollision() {
    double P1positionXCoord = position.operator[](0);
    double P1positionYCoord = position.operator[](1);
    double P1velocityXCoord = velocity.operator[](0);
    double P1velocityYCoord = velocity.operator[](1);
    if (P1positionXCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius) || P1positionXCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius)) {
        // Check for corner collision
        if (P1positionYCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius) || P1positionYCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius)) {
            P1velocityXCoord = - P1velocityXCoord;
            P1velocityYCoord = - P1velocityYCoord;
        } else {
            P1velocityXCoord = -P1velocityXCoord;
        }
    } else if (P1positionYCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius) || P1positionYCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius)) {
        // Check for corner collision
        if (P1positionXCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius) || P1positionXCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius)) {
            P1velocityXCoord = - P1velocityXCoord;
            P1velocityYCoord = - P1velocityYCoord;
        } else {
            P1velocityYCoord = -P1velocityYCoord;
        }
    }
    velocity = {P1velocityXCoord, P1velocityYCoord};
}

void Particle::ChangeVelocity(const Particle &particle2) {
    double dot_product = glm::dot((velocity - particle2.velocity), (position - particle2.position));
    double length = glm::length(position - particle2.position);
    // If particles have the same position, no collision is detected
    if (glm::pow(length, 2) == 0) {
        return;
    }
    glm::vec2 dist = position - particle2.position;
    velocity -= (dist *= (dot_product / (glm::pow(length, 2))));
}
