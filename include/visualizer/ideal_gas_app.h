//
// Created by Kaleigh Spitzer on 12/18/20.
//
#pragma once
#ifndef IDEAL_GAS_SPITZER4_1_IDEALGASAPP_H
#define IDEAL_GAS_SPITZER4_1_IDEALGASAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/core/particle.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/core/red_particle.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/core/yellow_particle.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/core/blue_particle.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/visualizer/histogram.h"

namespace idealgas {
    namespace visualizer {
        class ideal_gas_app : public ci::app::App {
        public:
            size_t kWindowSize = 1000;
            size_t kNumParticles = 10;
            static size_t kBoundaryMin;
            static size_t kBoundaryMax;
            std::vector<Particle> particles;
            std::vector<RedParticle> red_particles;
            std::vector<BlueParticle> blue_particles;
            std::vector<YellowParticle> yellow_particles;

            std::vector<Particle> red_particle_list;
            std::vector<Particle> blue_particle_list;
            std::vector<Particle> yellow_particle_list;

            ideal_gas_app();
            void setup();
            void update();
            void draw();
            Histogram red_histogram;
            Histogram blue_histogram;
            Histogram yellow_histogram;
        };
    }
}
#endif //IDEAL_GAS_SPITZER4_1_IDEALGASAPP_H
