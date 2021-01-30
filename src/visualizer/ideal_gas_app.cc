//
// Created by Kaleigh Spitzer on 12/18/20.
//

#include <numeric>

#include "../../include/visualizer/ideal_gas_app.h"

size_t idealgas::visualizer::ideal_gas_app::kBoundaryMin = 100;
size_t idealgas::visualizer::ideal_gas_app::kBoundaryMax = 700;

idealgas::visualizer::ideal_gas_app::ideal_gas_app() {
    setWindowSize(kWindowSize, kWindowSize);
}

void idealgas::visualizer::ideal_gas_app::setup() {
    red_particles.clear();
    blue_particles.clear();
    yellow_particles.clear();
    particles.clear();
    for (size_t particle_index = 0; particle_index < kNumParticles; particle_index++) {
//        particles.push_back(Particle());
        red_particles.push_back(RedParticle());
        blue_particles.push_back(BlueParticle());
        yellow_particles.push_back(YellowParticle());
    }
    for (Particle red_particle : red_particles) {
        particles.push_back(red_particle);
    }
    for (Particle blue_particle : blue_particles) {
        particles.push_back(blue_particle);
    }
    for (Particle yellow_particle : yellow_particles) {
        particles.push_back(yellow_particle);
    }

//    for (Particle& particle : particles) {
//        particle.position = {rand() % 500 + 120, rand() % 500 + 120};
//        particle.velocity = {2, 2};
//    }
}

void idealgas::visualizer::ideal_gas_app::update() {
//    for (Particle& p : particles) {
//        p.Update();
//    }
    for (size_t p_iterator = 0; p_iterator < particles.size(); p_iterator++) {
        Particle particle1 = particles.at(p_iterator);

        particle1.Update();
        for (size_t p_iterator2 = 0; p_iterator2 < particles.size(); p_iterator2++) {
            if (p_iterator != p_iterator2) {
                Particle particle2 = particles.at(p_iterator2);
                if (particle1.IsParticleCollision(particle2)) {
                    particle1.ChangeVelocity(particle2);
                    particle2.ChangeVelocity(particle1);
                }
            }
        }
        particle1.WallCollision();
        particle1.Update();
        particles.at(p_iterator) = particle1;
    }
}

void idealgas::visualizer::ideal_gas_app::draw() {
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(kBoundaryMin, kBoundaryMin, kBoundaryMax, kBoundaryMax);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);
//    for (Particle particle : particles) {
//        particle.Draw();
//    }
    for (RedParticle redParticle : red_particles) {
        redParticle.Draw();
    }
    for (BlueParticle blueParticle : blue_particles) {
        blueParticle.Draw();
    }
    for (YellowParticle yellowParticle : yellow_particles) {
        yellowParticle.Draw();
    }
}
