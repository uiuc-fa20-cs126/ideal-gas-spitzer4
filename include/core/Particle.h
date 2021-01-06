//
// Created by Kaleigh Spitzer on 12/18/20.
//

#ifndef IDEAL_GAS_SPITZER4_2_PARTICLE_H
#define IDEAL_GAS_SPITZER4_2_PARTICLE_H

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/gl/gl.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/Vector.h"

//namespace idealgas {
    class Particle {
    public:
        glm::vec2 position;
        glm::vec2 velocity;
        float radius;
        float direction;
        float time;

        Particle();

        void update();

        void draw();
    };
//}

#endif //IDEAL_GAS_SPITZER4_2_PARTICLE_H