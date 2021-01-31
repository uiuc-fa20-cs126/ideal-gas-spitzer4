//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include "../../include/core/particle.h"
#include "../../include/visualizer/ideal_gas_app.h"

Particle::Particle() {
    time = 0;
    position_ = {rand() % 500 + 120, rand() % 500 + 120};
    direction_ = static_cast<float>(rand());
}

float Particle::GetRadius() {
    return radius_;
}

glm::vec2 Particle::GetPosition() {
    return position_;
}

glm::vec2 Particle::GetVelocity() {
    return velocity_;
}

double Particle::GetMass() {
    return mass_;
}

void Particle::SetPosition(glm::vec2 position) {
    position_ = position;
}

void Particle::SetVelocity(glm::vec2 velocity) {
    velocity_ = velocity;
}

void Particle::SetRadius(float radius) {
    radius_ = radius;
}

void Particle::SetMass(double mass) {
    mass_ = mass;
}

void Particle::SetColor(glm::vec3 color) {
    color_ = color;
}

void Particle::Update() {
    position_ += velocity_;
    SetPosition(position_);
    time = time + 1;
}

void Particle::Draw() {
    ci::gl::color(color_[0], color_[1], color_[2]);
    ci::gl::drawSolidCircle(position_, radius_);
}

bool Particle::IsParticleCollision(const Particle &particle2) {
//    glm::vec2 position_diff = position_ - particle2.position_;
    position_ = GetPosition();
    velocity_ = GetVelocity();
    radius_ = GetRadius();
    glm::vec2 position_diff = position_ - particle2.position_;
    glm::vec2 velocity_diff = velocity_ - particle2.velocity_;
    double dot_product = glm::dot(position_diff, velocity_diff);
    double dist = sqrt(pow(position_.x - particle2.position_.x, 2) + pow(position_.y - particle2.position_.y, 2));
    if (dist <= (radius_ + particle2.radius_) && dot_product < 0) {
        return true;
    }
    return false;
}

void Particle::WallCollision() {
    position_ = GetPosition();
    velocity_ = GetVelocity();
    radius_ = GetRadius();
    double P1positionXCoord = position_.operator[](0);
    double P1positionYCoord = position_.operator[](1);
    double P1velocityXCoord = velocity_.operator[](0);
    double P1velocityYCoord = velocity_.operator[](1);
    if (P1positionXCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius_) || P1positionXCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius_)) {
        // Check for corner collision
        if (P1positionYCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius_) || P1positionYCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius_)) {
            P1velocityXCoord = - P1velocityXCoord;
            P1velocityYCoord = - P1velocityYCoord;
        } else {
            P1velocityXCoord = -P1velocityXCoord;
        }
    } else if (P1positionYCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius_) || P1positionYCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius_)) {
        // Check for corner collision
        if (P1positionXCoord >= (idealgas::visualizer::ideal_gas_app::kBoundaryMax - radius_) || P1positionXCoord <= (idealgas::visualizer::ideal_gas_app::kBoundaryMin + radius_)) {
            P1velocityXCoord = - P1velocityXCoord;
            P1velocityYCoord = - P1velocityYCoord;
        } else {
            P1velocityYCoord = -P1velocityYCoord;
        }
    }
    velocity_ = {P1velocityXCoord, P1velocityYCoord};
    SetVelocity(velocity_);
}

void Particle::ChangeVelocity(const Particle &particle2) {
    position_ = GetPosition();
    velocity_ = GetVelocity();
    mass_ = GetMass();
    double mass_multiplier = ((double) (2 * particle2.mass_)) / (mass_ + particle2.mass_);
    double dot_product = glm::dot((velocity_ - particle2.velocity_), (position_ - particle2.position_));
    double length = glm::length(position_ - particle2.position_);
    // If particles have the same position, no collision is detected
    if (glm::pow(length, 2) == 0) {
        return;
    }
    glm::vec2 dist = position_ - particle2.position_;
    dist *= mass_multiplier;
    dist *= (dot_product / glm::pow(length, 2));
    velocity_ -= dist;
    SetVelocity(velocity_);
}
