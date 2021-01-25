//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include <numeric>

#include "../../include/visualizer/ideal_gas_app.h"

size_t idealgas::visualizer::ideal_gas_app::kBoundaryMin = 100;
size_t idealgas::visualizer::ideal_gas_app::kBoundaryMax = 700;

std::vector<particle> particles;

idealgas::visualizer::ideal_gas_app::ideal_gas_app() {
    setWindowSize(kWindowSize, kWindowSize);
}

void idealgas::visualizer::ideal_gas_app::setup() {
    for (size_t particle_index = 0; particle_index < kNumParticles; particle_index++) {
        particles.push_back(particle());
    }

    for (particle& particle : particles) {
        particle.position = {rand() % 500 + 120, rand() % 500 + 120};
        particle.velocity = {2, 2};
    }
}

void idealgas::visualizer::ideal_gas_app::update() {
    for (size_t i = 0; i < particles.size(); i++) {
        particle particle1 = particles.at(i);
        particle1.Update();
        for (size_t i2 = 0; i2 < particles.size(); i2++) {
            if (i != i2) {
                particle particle2 = particles.at(i2);
                if (particle1.IsParticleCollision(particle2)) {
                    particle1.ChangeVelocity(particle2);
                    particle2.ChangeVelocity(particle1);
                }
            }
        }
        particle1.WallCollision();
        particle1.Update();
        particles.at(i) = particle1;
    }
}


void idealgas::visualizer::ideal_gas_app::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(kBoundaryMin, kBoundaryMin, kBoundaryMax, kBoundaryMax);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
    for (particle particle : particles) {
        particle.Draw();
    }
}
