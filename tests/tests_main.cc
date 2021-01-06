//
// Created by Kaleigh Spitzer on 12/18/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4-2/include/visualizer/IdealGasApp.h"

TEST_CASE("Wall collision") {
    SECTION("The particle's velocity changes when it collides with a wall") {
        SECTION("Collision with left wall") {
            Particle particle;
            particle.position = {115, 300};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.operator[](0);
            REQUIRE(x_coord_velocity == -2);
        }

        SECTION("Collision with right wall") {
            Particle particle;
            particle.position = {685, 300};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.operator[](0);
            REQUIRE(x_coord_velocity == -2);
        }

        SECTION("Collision with top wall") {
            Particle particle;
            particle.position = {300, 685};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double y_coord_velocity = particle.velocity.operator[](1);
            REQUIRE(y_coord_velocity == -2);
        }

        SECTION("Collision with bottom wall") {
            Particle particle;
            particle.position = {300, 115};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double y_coord_velocity = particle.velocity.operator[](1);
            REQUIRE(y_coord_velocity == -2);
        }

        SECTION("Top left corner collision") {
            Particle particle;
            particle.position = {115, 685};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.operator[](0);
            double y_coord_velocity = particle.velocity.operator[](1);
            REQUIRE(x_coord_velocity == -2);
            REQUIRE(y_coord_velocity == -2);
        }

        SECTION("Top right corner collision") {
            Particle particle;
            particle.position = {685, 685};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.operator[](0);
            double y_coord_velocity = particle.velocity.operator[](1);
            REQUIRE(x_coord_velocity == -2);
            REQUIRE(y_coord_velocity == -2);
        }

        SECTION("Bottom left corner collision") {
            Particle particle;
            particle.position = {115, 115};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.operator[](0);
            double y_coord_velocity = particle.velocity.operator[](1);
            REQUIRE(x_coord_velocity == -2);
            REQUIRE(y_coord_velocity == -2);
        }

        SECTION("Bottom right corner collision") {
            Particle particle;
            particle.position = {685, 115};
            particle.velocity = {2, 2};
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.operator[](0);
            double y_coord_velocity = particle.velocity.operator[](1);
            REQUIRE(x_coord_velocity == -2);
            REQUIRE(y_coord_velocity == -2);
        }
    }

    SECTION("The particle's velocity does NOT update if it does not collide with a wall") {
        Particle particle;
        particle.position = {300, 300};
        particle.velocity = {2, 2};
        particle.WallCollision();
        double x_coord_velocity = particle.velocity.operator[](0);
        REQUIRE(x_coord_velocity == 2);
    }
}