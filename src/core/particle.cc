//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle.h"

Particle::Particle(glm::vec2 new_position) {
    position = new_position;
    direction = Rand::randFloat();
    velocity = Rand::randFloat(5.0f);
    radius = 5.0f;
}
void Particle::update() {

    position += velocity;

}
void Particle::draw() {
    gl::drawSolidCircle(location, radius);
}
