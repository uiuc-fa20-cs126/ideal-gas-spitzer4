//
// Created by Kaleigh Spitzer on 11/13/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <../include/visualizer/simulation.h>

TEST_CASE("Test updating velocity on wall collision") {
    SECTION("Test hitting vertical walls") {
        float x = idealgas::Simulation::maxXWidth;
        float y = 5;
        idealgas::Particle particle({x, y});
        glm::vec2 newVelocity = idealgas::Simulation::oneParticleWallCollision(particle, x, y);
        REQUIRE(0 == newVelocity.operator[](0));
    }
}
