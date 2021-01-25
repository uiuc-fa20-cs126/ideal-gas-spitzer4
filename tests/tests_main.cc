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
        particle.Update();
        particle.WallCollision();
        double x_coord_velocity = particle.velocity.x;
        double y_coord_velocity = particle.velocity.y;
        REQUIRE(x_coord_velocity == 2.0);
        REQUIRE(y_coord_velocity == 2.0);
    }
}

TEST_CASE("Particle collision") {
    SECTION("Collision is detected if particles are moving towards each other") {
        particle particle1;
        particle1.position = {235, 235};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {250, 250};
        particle2.velocity = {-2, -2};
        particle1.Update();
        particle2.Update();
        REQUIRE(particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are not moving towards each other") {
        particle particle1;
        particle1.position = {200, 200};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {250, 250};
        particle2.velocity = {2, 2};
        particle1.Update();
        particle2.Update();
        REQUIRE(!particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are at the same position") {
        particle particle1;
        particle1.position = {200, 200};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {200, 200};
        particle2.velocity = {2, 2};
        particle1.Update();
        particle2.Update();
        REQUIRE(!particle1.IsParticleCollision(particle2));
    }
}

TEST_CASE("Changing velocity") {
    SECTION("Calculation is correct ") {
        particle particle1;
        particle1.position = {235, 235};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {250, 250};
        particle2.velocity = {-2, -2};
        particle1.Update();
        particle2.Update();
        SECTION("Particle 1") {
            particle1.ChangeVelocity(particle2);
            REQUIRE(particle1.velocity.x == -2);
            REQUIRE(particle1.velocity.y == -2);
        }
        SECTION("Particle 2") {
            particle2.ChangeVelocity(particle1);
            REQUIRE(particle2.velocity.x == 2);
            REQUIRE(particle2.velocity.y == 2);
        }
    }

    SECTION("Velocity does NOT change if the distance between particles is 0") {
        particle particle1;
        particle1.position = {200, 235};
        particle1.velocity = {2, 2};
        particle particle2;
        particle2.position = {200, 235};
        particle2.velocity = {-2, -2};
        particle1.ChangeVelocity(particle2);
        REQUIRE(particle1.velocity.x == 2);
        REQUIRE(particle1.velocity.y == 2);
        REQUIRE(particle2.velocity.x == -2);
        REQUIRE(particle2.velocity.y == -2);
    }
}