//
// Created by Kaleigh Spitzer on 12/18/20.
//

#ifndef IDEAL_GAS_SPITZER4_2_PARTICLE_H
#define IDEAL_GAS_SPITZER4_2_PARTICLE_H

#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/gl/gl.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/Vector.h"

class Particle {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius = 15.0f;
    float direction;
    float time;

    Particle();

    void Update();

    void Draw();

    /**
     * Checks for a collision between two particles.
     * @return true if a collision was detected, false otherwise.
     */
    bool IsParticleCollision(const Particle&);

    /**
     * Detects a wall collision and changes the particle's velocity as needed.
     */
    void WallCollision();

    /**
     * Used for collisions between particles. Performs calculations for new velocities.
     */
    void ChangeVelocity(const Particle&);
private:
//    glm::vec2 position_;
//    glm::vec2 velocity_;
//    float radius_;
//    float direction_;
};

#endif //IDEAL_GAS_SPITZER4_2_PARTICLE_H