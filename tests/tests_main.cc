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
            SECTION("Red particle") {
                idealgas::RedParticle();
                idealgas::RedParticle redParticle;
                size_t min_particle_limit = boundary_min + redParticle.GetRadius();
                redParticle.SetPosition({min_particle_limit, 300});
                redParticle.SetVelocity({-3, -3});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == 3.0);
                REQUIRE(y_coord_velocity == -3.0);
            }
        }

        SECTION("Collision with right wall") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t max_particle_limit = boundary_max - redParticle.GetRadius();
                redParticle.SetPosition({max_particle_limit, 300});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == -3.0);
                REQUIRE(y_coord_velocity == 3.0);
            }
        }

        SECTION("Collision with top wall") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t max_particle_limit = boundary_max - redParticle.GetRadius();
                redParticle.SetPosition({300, max_particle_limit});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == 3.0);
                REQUIRE(y_coord_velocity == -3.0);
            }
        }

        SECTION("Collision with bottom wall") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t min_particle_limit = boundary_min + redParticle.GetRadius();
                redParticle.SetPosition({300, min_particle_limit});
                redParticle.SetVelocity({3, -3});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == 3.0);
                REQUIRE(y_coord_velocity == 3.0);
            }
        }

        SECTION("Top left corner collision") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t min_particle_limit = boundary_min + redParticle.GetRadius();
                size_t max_particle_limit = boundary_max - redParticle.GetRadius();
                redParticle.SetPosition({min_particle_limit, max_particle_limit});
                redParticle.SetVelocity({-3, 3});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == 3.0);
                REQUIRE(y_coord_velocity == -3.0);
            }
        }

        SECTION("Top right corner collision") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t max_particle_limit = boundary_max - redParticle.GetRadius();
                redParticle.SetPosition({max_particle_limit, max_particle_limit});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == -3.0);
                REQUIRE(y_coord_velocity == -3.0);
            }
        }

        SECTION("Bottom left corner collision") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t min_particle_limit = boundary_min + redParticle.GetRadius();
                redParticle.SetPosition({min_particle_limit, min_particle_limit});
                redParticle.SetVelocity({-3, -3});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == 3.0);
                REQUIRE(y_coord_velocity == 3.0);
            }
        }

        SECTION("Bottom right corner collision") {
            SECTION("Red particle") {
                idealgas::RedParticle redParticle;
                size_t min_particle_limit = boundary_min + redParticle.GetRadius();
                size_t max_particle_limit = boundary_max - redParticle.GetRadius();
                redParticle.SetPosition({max_particle_limit, min_particle_limit});
                redParticle.SetVelocity({-3, 3});
                redParticle.Update();
                redParticle.WallCollision();
                double x_coord_velocity = redParticle.GetVelocity().x;
                double y_coord_velocity = redParticle.GetVelocity().y;
                REQUIRE(x_coord_velocity == -3.0);
                REQUIRE(y_coord_velocity == 3.0);
            }
        }
    }

    SECTION("The particle's velocity does NOT update if it does not collide with a wall") {
        SECTION("Red particle") {
            idealgas::RedParticle redParticle;
            redParticle.SetPosition({300, 300});
            redParticle.Update();
            redParticle.WallCollision();
            double x_coord_velocity = redParticle.GetVelocity().x;
            double y_coord_velocity = redParticle.GetVelocity().y;
            REQUIRE(x_coord_velocity == 3.0);
            REQUIRE(y_coord_velocity == 3.0);
        }
    }
}

TEST_CASE("Particle collision") {
    SECTION("Collision is detected if particles are moving towards each other") {
        idealgas::RedParticle particle1;
        particle1.SetPosition({235, 235});
        idealgas::RedParticle particle2;
        particle2.SetPosition({250, 250});
        particle1.Update();
        particle2.Update();
        REQUIRE(particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are not moving towards each other") {
        idealgas::RedParticle particle1;
        particle1.SetPosition({200, 200});
        idealgas::RedParticle particle2;
        particle2.SetPosition({250, 250});
        particle1.Update();
        particle2.Update();
        REQUIRE(!particle1.IsParticleCollision(particle2));
    }

    SECTION("Collision is NOT detected if particles are at the same position") {
        idealgas::RedParticle particle1;
        particle1.SetPosition({200, 200});
        idealgas::RedParticle particle2;
        particle2.SetPosition({200, 200});
        particle1.Update();
        particle2.Update();
        REQUIRE(!particle1.IsParticleCollision(particle2));
    }
}

TEST_CASE("Changing velocity") {
    SECTION("Calculation is correct ") {
        idealgas::RedParticle particle1;
        particle1.SetPosition({235, 235});
        particle1.SetVelocity({3, 3});
        idealgas::RedParticle particle2;
        particle2.SetPosition({250, 250});
        particle2.SetVelocity({-3,-3});
        particle1.Update();
        particle2.Update();
        SECTION("Particle 1") {
            particle1.ChangeVelocity(particle2);
            REQUIRE(particle1.GetVelocity().x == -3.0f);
            REQUIRE(particle1.GetVelocity().y == -3);
        }
        SECTION("Particle 2") {
            particle2.ChangeVelocity(particle1);
            REQUIRE(particle2.GetVelocity().x == 3.0f);
            REQUIRE(particle2.GetVelocity().y == 3);
        }
    }

    SECTION("Velocity does NOT change if the distance between particles is 0") {
        idealgas::RedParticle particle1;
        particle1.SetPosition({200, 235});
        idealgas::RedParticle particle2;
        particle2.SetPosition({200, 235});
        particle1.ChangeVelocity(particle2);
        REQUIRE(particle1.GetVelocity().x == 3);
        REQUIRE(particle1.GetVelocity().y == 3);
        REQUIRE(particle2.GetVelocity().x == -3);
        REQUIRE(particle2.GetVelocity().y == -3);
    }
}