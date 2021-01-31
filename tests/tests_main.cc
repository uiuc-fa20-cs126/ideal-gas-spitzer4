//
// Created by Kaleigh Spitzer on 12/18/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/visualizer/ideal_gas_app.h"

size_t boundary_min = idealgas::visualizer::ideal_gas_app::kBoundaryMin;
size_t boundary_max = idealgas::visualizer::ideal_gas_app::kBoundaryMax;

TEST_CASE("Wall collision") {
    SECTION("The particle's velocity changes when it collides with a wall") {
        SECTION("Collision with left wall") {
            Particle particle;
            size_t min_particle_limit = boundary_min + particle.GetRadius();
            particle.position_ = {min_particle_limit, 300};
            particle.SetVelocity({-2, 2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Collision with right wall") {
            Particle particle;
            size_t max_particle_limit = boundary_max - particle.GetRadius();
            particle.position_ = {max_particle_limit, 300};
            particle.SetVelocity({2, 2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == -2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Collision with top wall") {
            Particle particle;
            size_t max_particle_limit = boundary_max - particle.GetRadius();
            particle.position_ = {300, max_particle_limit};
            particle.SetVelocity({2, 2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == -2.0);
        }

        SECTION("Collision with bottom wall") {
            Particle particle;
            size_t min_particle_limit = boundary_min + particle.GetRadius();
            particle.position_ = {300, min_particle_limit};
            particle.SetVelocity({2, -2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Top left corner collision") {
            Particle particle;
            size_t min_particle_limit = boundary_min + particle.GetRadius();
            size_t max_particle_limit = boundary_max - particle.GetRadius();
            particle.position_ = {min_particle_limit, max_particle_limit};
            particle.SetVelocity({-2, 2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == -2.0);
        }

        SECTION("Top right corner collision") {
            Particle particle;
            size_t max_particle_limit = boundary_max - particle.GetRadius();
            particle.position_ = {max_particle_limit, max_particle_limit};
            particle.SetVelocity({2, 2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == -2.0);
            REQUIRE(y_coord_velocity == -2.0);
        }

        SECTION("Bottom left corner collision") {
            Particle particle;
            size_t min_particle_limit = boundary_min + particle.GetRadius();
            particle.position_ = {min_particle_limit, min_particle_limit};
            particle.SetVelocity({-2, -2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == 2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }

        SECTION("Bottom right corner collision") {
            Particle particle;
            size_t min_particle_limit = boundary_min + particle.GetRadius();
            size_t max_particle_limit = boundary_max - particle.GetRadius();
            particle.position_ = {max_particle_limit, min_particle_limit};
            particle.SetVelocity({2, -2});
            particle.Update();
            particle.WallCollision();
            double x_coord_velocity = particle.GetVelocity().x;
            double y_coord_velocity = particle.GetVelocity().y;
            REQUIRE(x_coord_velocity == -2.0);
            REQUIRE(y_coord_velocity == 2.0);
        }
    }

    SECTION("The particle's velocity does NOT update if it does not collide with a wall") {
        Particle particle;
        particle.position_ = {300, 300};
        particle.SetVelocity({2, 2});
        particle.Update();
        particle.WallCollision();
        double x_coord_velocity = particle.GetVelocity().x;
        double y_coord_velocity = particle.GetVelocity().y;
        REQUIRE(x_coord_velocity == 2.0);
        REQUIRE(y_coord_velocity == 2.0);
    }
}

TEST_CASE("Particle collision") {
    SECTION("Collision is detected if particles are moving towards each other") {
        Particle particle1;
        particle1.position_ = {235, 235};
        particle1.SetVelocity({2, 2});
        Particle particle2;
        particle2.position_ = {250, 250};
        particle2.SetVelocity({-2, -2});
        particle1.Update();
        particle2.Update();
        REQUIRE(particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are not moving towards each other") {
        Particle particle1;
        particle1.position_ = {200, 200};
        particle1.SetVelocity({2, 2});
        Particle particle2;
        particle2.position_ = {250, 250};
        particle2.SetVelocity({2, 2});
        particle1.Update();
        particle2.Update();
        REQUIRE(!particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are at the same position") {
        Particle particle1;
        particle1.position_ = {200, 200};
        particle1.SetVelocity({2, 2});
        Particle particle2;
        particle2.position_ = {200, 200};
        particle2.SetVelocity({2, 2});
        particle1.Update();
        particle2.Update();
        REQUIRE(!particle1.IsParticleCollision(particle2));
    }
}

TEST_CASE("Changing velocity") {
    SECTION("Calculation is correct ") {
        Particle particle1;
        particle1.position_ = {235, 235};
        particle1.SetVelocity({2, 2});
        Particle particle2;
        particle2.position_ = {250, 250};
        particle2.SetVelocity({-2, -2});
        particle1.Update();
        particle2.Update();
        SECTION("Particle 1") {
            particle1.ChangeVelocity(particle2);
            REQUIRE(particle1.GetVelocity().x == -2);
            REQUIRE(particle1.GetVelocity().y == -2);
        }
        SECTION("Particle 2") {
            particle2.ChangeVelocity(particle1);
            REQUIRE(particle2.GetVelocity().x == 2);
            REQUIRE(particle2.GetVelocity().y == 2);
        }
    }

    SECTION("Velocity does NOT change if the distance between particles is 0") {
        Particle particle1;
        particle1.position_ = {200, 235};
        particle1.SetVelocity({2, 2});
        Particle particle2;
        particle2.position_ = {200, 235};
        particle2.SetVelocity({-2, -2});
        particle1.ChangeVelocity(particle2);
        REQUIRE(particle1.GetVelocity().x == 2);
        REQUIRE(particle1.GetVelocity().y == 2);
        REQUIRE(particle2.GetVelocity().x == -2);
        REQUIRE(particle2.GetVelocity().y == -2);
    }
}