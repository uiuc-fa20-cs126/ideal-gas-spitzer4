//
// Created by Kaleigh Spitzer on 12/18/20.
//
#pragma once

#ifndef IDEAL_GAS_SPITZER4_2_PARTICLE_H
#define IDEAL_GAS_SPITZER4_2_PARTICLE_H

#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/gl/gl.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/Vector.h"

class Particle {
public:
    float time;
    glm::vec2 position_;
    float direction_;
    glm::vec3 color_;

    Particle();
    float GetRadius();
    double GetMass();
    glm::vec2 GetPosition();
    glm::vec2 GetVelocity();
    void SetPosition(glm::vec2);
    void SetVelocity(glm::vec2);
    void SetRadius(float);
    void SetMass(double);
    void SetColor(glm::vec3);

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
    void ChangeVelocity(Particle&);
private:
    glm::vec2 velocity_;
    float radius_;
    double mass_;
};

#endif //IDEAL_GAS_SPITZER4_2_PARTICLE_H