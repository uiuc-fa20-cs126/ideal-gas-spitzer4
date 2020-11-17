//
// Created by Kaleigh Spitzer on 11/14/20.
//

#ifndef IDEAL_GAS_IDEALGASAPP_H
#define IDEAL_GAS_IDEALGASAPP_H

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/app/App.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/app/RendererGl.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/gl/gl.h"

#include <core/particle_controller.h>
#include <visualizer/simulation.h>

class IdealGasApp : public ci::app::App {
public:
    void setup();
    void update();
    void draw();
};

#endif //IDEAL_GAS_IDEALGASAPP_H
