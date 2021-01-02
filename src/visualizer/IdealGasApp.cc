//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include <numeric>

#include "../../include/visualizer/IdealGasApp.h"

using namespace idealgas;

size_t num_particles = 5;
size_t boundary_min = 100;
size_t boundary_max = 700;
std::vector<Particle> particles;

IdealGasApp::IdealGasApp() {
    setWindowSize(800, 800);
}

void IdealGasApp::setup() {
    for (size_t particle_index = 0; particle_index < num_particles; particle_index++) {
        particles.push_back(Particle());
    }

    for (Particle& particle : particles) {
        particle.position = {rand() % 500 + 120, rand() % 500 + 120};
        particle.velocity = {2, 2};
    }
}

void IdealGasApp::update() {
    for (Particle& particle : particles) {
        particle.update();
        changeVelocity(particle, particle, true);
    }

    for (Particle particle1 : particles) {
        for (Particle particle2 : particles) {
//            if (particle1 == particle2) {
//                continue;
//            }
            particle1.update();
            particle2.update();
            changeVelocity(particle1, particle2, false);
        }
    }
}

void IdealGasApp::changeVelocity(idealgas::Particle& particle1, idealgas::Particle& particle2, bool isWallCollision) {
    float P1positionXCoord = particle1.position.operator[](0);
    float P1positionYCoord = particle1.position.operator[](1);
    float P1velocityXCoord = particle1.velocity.operator[](0);
    float P1velocityYCoord = particle1.velocity.operator[](1);
    float P2positionXCoord = particle2.position.operator[](0);
    float P2positionYCoord = particle2.position.operator[](1);
    float radius_sum = particle1.radius + particle2.radius;

    glm::vec2 newP1Velocity;
    glm::vec2 newP2Velocity;

    if (isWallCollision) {
        if (P1positionXCoord > (boundary_max - particle1.radius) || P1positionXCoord < (boundary_min + particle1.radius)) {
            P1velocityXCoord = - P1velocityXCoord;
        }
        if (P1positionYCoord > (boundary_max - particle1.radius) || P1positionYCoord < (boundary_min + particle1.radius)) {
            P1velocityYCoord = - P1velocityYCoord;
        }
        particle1.velocity = {P1velocityXCoord, P1velocityYCoord};
    } else {
        if (glm::distance(particle1.position, particle2.position) <= radius_sum) {
            float p1_mag = (glm::length2(particle1.position - particle2.position));
            float p2_mag = (glm::length2(particle2.position - particle1.position));
            if (P1positionXCoord == P2positionXCoord && P1positionYCoord == P2positionYCoord) {
                p1_mag = 1;
                p2_mag = 1;
            }
            newP1Velocity = particle1.velocity - ((glm::dot((particle1.velocity - particle2.velocity),
                                                            (particle1.position - particle2.position))) / (p1_mag) *
                                                  (particle1.position - particle2.position));
            newP2Velocity = particle2.velocity - ((glm::dot((particle2.velocity - particle1.velocity),
                                                            (particle2.position - particle1.position))) / (p2_mag) *
                                                  (particle2.position - particle2.position));
            particle1.velocity = newP1Velocity;
            particle2.velocity = newP2Velocity;
        }
    }
}

void IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(boundary_min, boundary_min, boundary_max, boundary_max);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
    for (Particle particle : particles) {
        particle.draw();
    }
}

CINDER_APP(IdealGasApp, ci::app::RendererGl)