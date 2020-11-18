#include <climits>
//
// Created by Kaleigh Spitzer on 11/1/20.
//

#include <visualizer/simulation.h>
#include <core/particle.h>

namespace idealgas {

    void Simulation::changeVelocity(Particle particle1) {
        float velocityXCoord = particle1.velocity.operator[](0);
        float velocityYCoord = particle1.velocity.operator[](1);
        float positionXCoord = particle1.position.operator[](0);
        float positionYCoord = particle1.position.operator[](1);
        glm::vec2 newVelocity;
        if (positionXCoord > Simulation::maxXWidth || positionXCoord < Simulation::minXWidth) {
            velocityXCoord = - velocityXCoord;
        }
        if (positionYCoord > Simulation::maxYHeight || positionYCoord < Simulation::minYHeight) {
            velocityYCoord = - velocityYCoord;
        }
        newVelocity = {velocityXCoord, velocityYCoord};
        particle1.velocity = newVelocity;
    }

}  // namespace idealgas
