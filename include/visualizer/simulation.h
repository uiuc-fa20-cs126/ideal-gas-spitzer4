//
// Created by Kaleigh Spitzer on 11/1/20.
//

#ifndef IDEAL_GAS_SPITZER4_SIMULATION_H
#define IDEAL_GAS_SPITZER4_SIMULATION_H

#include <core/particle.h>
#include "../../../../include/cinder/gl/gl.h"

namespace idealgas {

/**
 * A sketchpad which will be displayed in the Cinder application and respond to
 * mouse events. Furthermore, the sketchpad can output its current state in the
 * same format as the Naive Bayes image data files.
 */
    class Simulation {
    public:
        glm::vec2 particle1Coords;
        Particle particle1;
        const static size_t minXWidth = 0;
        const static size_t maxXWidth = 10;
        const static size_t minYHeight = 0;
        const static size_t maxYHeight = 10;

        static glm::vec2 oneParticleWallCollision(Particle particle, float xCoord, float yCoord);

    private:
    };
}

#endif //IDEAL_GAS_SPITZER4_SIMULATION_H
