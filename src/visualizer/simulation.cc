//
// Created by Kaleigh Spitzer on 11/1/20.
//

#include <visualizer/simulation.h>
#include <core/particle.h>

namespace idealgas {
    /**
    float x = cos(getElapsedSeconds() + getWindowWidth() / 2);
    float y = sin(getElapsedSeconds() + getWindowHeight() / 2);
    gl::drawSolidCircle(Vec2f(x, y), 50.0f);
    */
    float x1 = 2;
    float y1 = 5;
    glm::vec2 particle1Coords = {x1, y1};
    Particle particle1(particle1Coords);

    glm::vec2 oneParticleWallCollision(Particle particle, float xCoord, float yCoord) {
        float velocityXCoord = particle.velocity.operator[](0);
        float velocityYCoord = particle.velocity.operator[](1);
        glm::vec2 newVelocity;
        if (xCoord > Simulation::maxXWidth || xCoord < Simulation::minXWidth) {
            velocityXCoord = - velocityXCoord;
        }
        if (yCoord > Simulation::maxYHeight || yCoord < Simulation::minYHeight) {
            velocityYCoord = - velocityYCoord;
        }
        newVelocity = {velocityXCoord, velocityYCoord};
        return newVelocity;
    }

}  // namespace idealgas
