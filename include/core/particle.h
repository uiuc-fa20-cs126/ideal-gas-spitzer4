//
// Created by Kaleigh Spitzer on 12/18/20.
//

#ifndef IDEAL_GAS_SPITZER4_2_PARTICLE_H
#define IDEAL_GAS_SPITZER4_2_PARTICLE_H

#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/gl/gl.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/Vector.h"

class Particle {
public:
//    glm::vec2 position;
//    glm::vec2 velocity;
//    float radius;
//    float mass;
//    float direction;
    float time;
    glm::vec2 position_;
    float direction_;

    Particle(float, glm::vec2);
    Particle();
    float GetRadius();
    glm::vec2 GetPosition();
    glm::vec2 GetVelocity();
    void SetPosition(glm::vec2);
    void SetVelocity(glm::vec2);
    void SetRadius(float);
    void SetMass(float);
    void Update();

//    void Draw();

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
    glm::vec2 velocity_;
    float radius_;
//    float direction_;
    double mass_;
};

#endif //IDEAL_GAS_SPITZER4_2_PARTICLE_H