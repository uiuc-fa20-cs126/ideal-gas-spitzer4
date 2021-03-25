//
// Created by Kaleigh Spitzer on 3/25/21.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <visualizer/histogram.h>
//#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/visualizer/histogram.h"


TEST_CASE("Constructor functions properly") {
    idealgas::visualizer::Histogram test(glm::vec2(0, 0), 30);
//    REQUIRE();
}

TEST_CASE("Update frequency map") {
    SECTION("One particle") {
        idealgas::visualizer::Histogram histogram(glm::vec2(0, 0), 30);
        Particle particle;
        std::vector<Particle> particle_vec;
        particle_vec.push_back(particle);
        histogram.SetParticleVector(particle_vec);
        histogram.AddToSpeedFreqMap();
        std::map<double, double> speed_freq_map = histogram.GetSpeedFreqMap();
        REQUIRE(speed_freq_map.size() == 1);
        // REQUIRE(speed_freq_map[0] == 1);
    }

    SECTION("Multiple particles - different velocities") {
        idealgas::visualizer::Histogram histogram(glm::vec2(0, 0), 30);
        Particle particle1;
        particle1.SetVelocity(glm::vec2(-1, 1));
        Particle particle2;
        particle2.SetVelocity(glm::vec2(-2, 1));
        Particle particle3;
        particle3.SetVelocity(glm::vec2(-5, -3));
        std::vector<Particle> particle_vec;
        particle_vec.push_back(particle1);
        particle_vec.push_back(particle2);
        particle_vec.push_back(particle3);
        histogram.SetParticleVector(particle_vec);
        histogram.AddToSpeedFreqMap();
        std::map<double, double> speed_freq_map = histogram.GetSpeedFreqMap();
        REQUIRE(speed_freq_map.size() == 3);
//        for (auto& p : speed_freq_map) {
//            std::cout << p.first << std::endl;
//        }
    }
}