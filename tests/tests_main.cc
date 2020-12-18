//
// Created by Kaleigh Spitzer on 11/13/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/visualizer/IdealGasApp.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4/include/core/particle.h"

using namespace idealgas;
idealgas::Particle particle1({700, 100});
idealgas::Particle particle2({700, 100});

TEST_CASE("Test updating velocity on wall collision") {
    SECTION("Test hitting vertical walls") {
        particle1.position = {700, 100};
        particle1.velocity = {1, 1};
//        IdealGasApp::changeVelocity(particle1, particle1, true);
        glm::vec2 expected_velocity = {2, 2};
        REQUIRE(particle1.velocity == expected_velocity);
    }

    SECTION("Test hitting horizontal walls") {

    }

    SECTION("Velocity does not change if the particle hasn't collided with a wall") {

    }
}

TEST_CASE("Test updating velocity on particle collision") {
    SECTION("Velocities don't change if particles haven't collided") {

    }

    SECTION("Test particle collision") {

    }
}
