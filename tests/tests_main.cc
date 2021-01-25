//
// Created by Kaleigh Spitzer on 12/18/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/visualizer/ideal_gas_app.h"

TEST_CASE("Wall collision") {
    SECTION("The particle's velocity changes when it collides with a wall") {
        SECTION("Collision with left wall") {
            particle particle;
            particle.position = {115, 300};
            particle.velocity = {-2, 2};
            particle.Update();
            particle.WallCollision();
//            std::cout << particle.velocity.x << std::endl;
//            std::cout << particle.velocity.y << std::endl;
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Collision with right wall") {
            particle particle;
            particle.position = {685, 300};
            particle.velocity = {2, 2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == -2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Collision with top wall") {
            particle particle;
            particle.position = {300, 685};
            particle.velocity = {2, 2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == -2.0);
        }

        SECTION("Collision with bottom wall") {
            particle particle;
            particle.position = {300, 115};
            particle.velocity = {2, -2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Top left corner collision") {
            particle particle;
            particle.position = {115, 685};
            particle.velocity = {-2, 2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == -2.0);
        }

        SECTION("Top right corner collision") {
            particle particle;
            particle.position = {685, 685};
            particle.velocity = {2, 2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == -2.0);
            REQUIRE(y_coord_velocity == -2.0);
        }

        SECTION("Bottom left corner collision") {
            particle particle;
            particle.position = {115, 115};
            particle.velocity = {-2, -2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Bottom right corner collision") {
            particle particle;
            particle.position = {685, 115};
            particle.velocity = {2, -2};
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.velocity.x;
            double y_coord_velocity = particle.velocity.y;
            REQUIRE(x_coord_velocity == -2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }
    }

    SECTION("The particle's velocity does NOT update if it does not collide with a wall") {
        particle particle;
        particle.position = {300, 300};
        particle.velocity = {2, 2};
        particle.WallCollision();
        double x_coord_velocity = particle.velocity.operator[](0);
        REQUIRE(x_coord_velocity == 2);
    }
}

TEST_CASE("particle collision") {
    SECTION("Collision is detected if particles are moving towards each other") {
        particle particle1;
        particle1.position = {200, 200};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {250, 250};
        particle2.velocity = {-2, -2};
        REQUIRE(particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are not moving towards each other") {
        particle particle1;
        particle1.position = {200, 200};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {250, 250};
        particle2.velocity = {2, 2};
        REQUIRE(particle1.IsParticleCollision(particle2));
    }
}