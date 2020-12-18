//
// Created by Kaleigh Spitzer on 12/18/20.
//

#ifndef IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H
#define IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include ".../core/Particle.h"

class IdealGasApp : public ci::app::App {
public:
    IdealGasApp();
    void setup();
    void update();
    void draw();
    static void changeVelocity(idealgas::Particle&, idealgas::Particle&, bool);
};

#endif //IDEAL_GAS_SPITZER4_2_IDEALGASAPP_H
