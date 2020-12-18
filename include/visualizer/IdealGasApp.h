//
// Created by Kaleigh Spitzer on 11/14/20.
//

#ifndef IDEAL_GAS_IDEALGASAPP_H
#define IDEAL_GAS_IDEALGASAPP_H

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/app/App.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/app/RendererGl.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/gl/gl.h"

#include <core/particle.h>

class IdealGasApp : public ci::app::App {
public:
    IdealGasApp();
    void setup();
    void update();
    void draw();
    static void changeVelocity(idealgas::Particle&, idealgas::Particle&, bool);
};

#endif //IDEAL_GAS_IDEALGASAPP_H
