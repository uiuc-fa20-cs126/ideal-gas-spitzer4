//
// Created by Kaleigh Spitzer on 11/13/20.
//

#include "../include/particle.h"

Particle::Particle(Vec2f loc) {
    location = loc;
    direction = Rand::randVec2f();
    velocity = Rand::randFloat(5.0f);
    radius = 5.0f;
}
void Particle::update() {
    location += direction * velocity;
}
void Particle::draw() {
    gl::drawSolidCircle(location, radius);
}
