//
// Created by Kaleigh Spitzer on 12/18/20.
//
#pragma once
#ifndef IDEAL_GAS_SPITZER4_1_IDEALGASAPP_H
#define IDEAL_GAS_SPITZER4_1_IDEALGASAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

//#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4-2/include/core/particle.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/core/particle.h"

namespace idealgas {
    namespace visualizer {
        class ideal_gas_app : public ci::app::App {
        public:
            size_t kWindowSize = 1000;
            size_t kNumParticles = 5;
            static size_t kBoundaryMin;
            static size_t kBoundaryMax;

            ideal_gas_app();
            void setup();
            void update();
            void draw();
        };
    }
}
#endif //IDEAL_GAS_SPITZER4_1_IDEALGASAPP_H
