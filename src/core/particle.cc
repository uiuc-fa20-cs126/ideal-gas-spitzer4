//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../../include/core/particle.h"

Particle::Particle(glm::vec2 new_position) {
    position = new_position;
    direction = Rand::randFloat();
    velocity = glm::vec2(rand(), rand());
    radius = 5.0f;
}
void Particle::update() {
    position += velocity;
    time = time + 1;
}
void Particle::draw() {
    cinder::gl::drawSolidCircle(position, radius);
}
