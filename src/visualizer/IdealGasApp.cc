//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include <numeric>

#include "../../include/visualizer/IdealGasApp.h"

size_t idealgas::visualizer::IdealGasApp::kBoundaryMin = 100;
size_t idealgas::visualizer::IdealGasApp::kBoundaryMax = 700;

std::vector<Particle> particles;

idealgas::visualizer::IdealGasApp::IdealGasApp() {
    setWindowSize(kWindowSize, kWindowSize);
}

void idealgas::visualizer::IdealGasApp::setup() {
    for (size_t particle_index = 0; particle_index < kNumParticles; particle_index++) {
        particles.push_back(Particle());
    }

    for (Particle& particle : particles) {
        particle.position = {rand() % 500 + 120, rand() % 500 + 120};
        particle.velocity = {2, 2};
    }
}

void idealgas::visualizer::IdealGasApp::update() {
    for (size_t i = 0; i < particles.size(); i++) {
        Particle particle1 = particles.at(i);
        particle1.Update();
        for (size_t i2 = 0; i2 < particles.size(); i2++) {
            if (i != i2) {
                Particle particle2 = particles.at(i2);
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


void idealgas::visualizer::IdealGasApp::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(kBoundaryMin, kBoundaryMin, kBoundaryMax, kBoundaryMax);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
    for (Particle particle : particles) {
        particle.Draw();
    }
}
