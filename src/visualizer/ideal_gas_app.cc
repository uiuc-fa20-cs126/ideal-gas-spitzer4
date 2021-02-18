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
    for (size_t particle_index = 0; particle_index < kNumParticles; particle_index++) {
        red_particles.push_back(RedParticle());
        blue_particles.push_back(BlueParticle());
        yellow_particles.push_back(YellowParticle());
    }

    for (RedParticle& red_particle : red_particles) {
        particles.push_back(red_particle);
        red_particle_list.push_back(red_particle);
    }
    for (BlueParticle& blue_particle : blue_particles) {
        particles.push_back(blue_particle);
        blue_particle_list.push_back(blue_particle);
    }
    for (YellowParticle& yellow_particle : yellow_particles) {
        particles.push_back(yellow_particle);
        yellow_particle_list.push_back(yellow_particle);
    }
    Histogram h1({800, 250}, 100);
    Histogram h2({800, 550}, 100);
    Histogram h3({800, 850}, 100);
    red_histogram = h1;
    blue_histogram = h2;
    yellow_histogram = h3;
}

void idealgas::visualizer::ideal_gas_app::update() {
    for (size_t p_iterator = 0; p_iterator < particles.size(); p_iterator++) {
        Particle particle1 = particles.at(p_iterator);
//        std::cout << particle1.GetPosition() << std::endl;
        particle1.Update();
//        if (particle1.GetPosition().x > 700 || particle1.GetPosition().x < 100 || particle1.GetPosition().y > 700 || particle1.GetPosition().y < 100) {
//            std::cout << particle1.GetPosition() << std::endl;
//        }
//        std::cout << particle1.GetPosition() << std::endl;

//        glm::vec2 position = particle1.GetPosition();
//        glm::vec2 velocity = particle1.GetVelocity();

        particle1.WallCollision();
//        std::cout << "Position: " << particle1.GetPosition() << std::endl;
//        std::cout << "Updating velocity:" << particle1.GetVelocity() << std::endl;
        for (size_t p_iterator2 = 0; p_iterator2 < particles.size(); p_iterator2++) {
            if (p_iterator != p_iterator2) {
                Particle particle2 = particles.at(p_iterator2);
                Particle temp = particle1;
                if (particle1.IsParticleCollision(particle2)) {
//                    std::cout << particle1.GetPosition() << std::endl;
//                    std::cout << particle1.GetVelocity() << std::endl;

                    particle1.ChangeVelocity(particle2);
//                    std::cout << particle1.GetPosition() << std::endl;
//                    std::cout << particle1.GetVelocity() << std::endl;

//                    std::cout << "-------------------" << std::endl;

//                    std::cout << particle2.GetPosition() << std::endl;
//                    std::cout << particle2.GetVelocity() << std::endl;

                    particle2.ChangeVelocity(temp);
//                    std::cout << particle2.GetPosition() << std::endl;
//                    std::cout << particle2.GetVelocity() << std::endl;
                    particle1.Update();
                    particle2.Update();

//                    std::cout << "Updating velocity based on particle collision" << std::endl;
                }
            }
        }
//        position += velocity;
//************************8
//        std::cout << "-------------------------" << std::endl;
//        std::cout << particle1.GetPosition() << std::endl;

//        particle1.Update();
//        if (particle1.GetPosition().x > 700 || particle1.GetPosition().x < 100 || particle1.GetPosition().y > 700 || particle1.GetPosition().y < 100) {
//            std::cout << particle1.GetPosition() << std::endl;
//        }
//        std::cout << particle1.GetPosition() << std::endl;


//        particle1.SetPosition(position);
//        particle1.SetVelocity(velocity);
//        particle1.WallCollision();
//        particle1.Update();

//        if (particle1.GetRadius() == 15) {
//            red_particle_list.push_back(particle1);
//        } else if (particle1.GetRadius() == 10) {
//            blue_particle_list.push_back(particle1);
//        } else if (particle1.GetRadius() == 20) {
//            yellow_particle_list.push_back(particle1);
//        }
        particles.at(p_iterator) = particle1;
    }
    red_histogram.SetParticleVector(red_particle_list);
    blue_histogram.SetParticleVector(blue_particle_list);
    yellow_histogram.SetParticleVector(yellow_particle_list);
    red_histogram.AddToSpeedFreqMap();
//    std::cout << red_histogram.GetSpeedFreqMap().size() << std::endl;
    blue_histogram.AddToSpeedFreqMap();
//    std::cout << blue_histogram.GetSpeedFreqMap().size() << std::endl;
    yellow_histogram.AddToSpeedFreqMap();
//    std::cout << yellow_histogram.GetSpeedFreqMap().size() << std::endl;
//    std::cout << "---------------------" << std::endl;
    red_histogram.Draw();
    blue_histogram.Draw();
    yellow_histogram.Draw();
}

void idealgas::visualizer::ideal_gas_app::draw() {
    red_particle_list.clear();
    blue_particle_list.clear();
    yellow_particle_list.clear();
    ci::gl::clear(ci::Color(0, 0, 0));
    ci::Rectf boundary(kBoundaryMin, kBoundaryMin, kBoundaryMax, kBoundaryMax);
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawStrokedRect(boundary);


    for (Particle particle : particles) {
        particle.Draw();
        if (particle.GetRadius() == 15) {
            red_particle_list.push_back(particle);
        } else if (particle.GetRadius() == 10) {
            blue_particle_list.push_back(particle);
        } else if (particle.GetRadius() == 20) {
            yellow_particle_list.push_back(particle);
        }
    }
    red_histogram.Draw();
    blue_histogram.Draw();
    yellow_histogram.Draw();
}

