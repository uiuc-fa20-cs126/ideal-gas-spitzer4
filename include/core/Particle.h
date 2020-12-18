//
// Created by Kaleigh Spitzer on 12/18/20.
//

#ifndef IDEAL_GAS_SPITZER4_2_PARTICLE_H
#define IDEAL_GAS_SPITZER4_2_PARTICLE_H

namespace idealgas {
    class Particle {
    public:
        glm::vec2 position;
        glm::vec2 velocity;
        float radius;
        float time;

        Particle();

        void update();

        void draw();
    };
}

#endif //IDEAL_GAS_SPITZER4_2_PARTICLE_H