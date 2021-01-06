//
// Created by Kaleigh Spitzer on 12/18/20.
//
#pragma once
#ifndef IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H
#define IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
//#include "cinder/gl/gl.h"

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/ideal-gas-spitzer4-2/include/core/Particle.h"

class IdealGasApp : public ci::app::App {
public:
    size_t kWindowSize = 1000;
    size_t kNumParticles = 5;
    size_t kBoundaryMin = 100;
    size_t kBoundaryMax = 700;

    IdealGasApp();
    void setup();
    void update();
    void draw();
};

#endif //IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H
