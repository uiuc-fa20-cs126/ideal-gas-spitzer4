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
    IdealGasApp();
    void setup();
    void update();
    void draw();
    static void changeVelocity(Particle&, Particle&, bool);
};

#endif //IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H
