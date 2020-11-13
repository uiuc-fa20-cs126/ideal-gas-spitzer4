//
// Created by Kaleigh Spitzer on 11/1/20.
//

#include <visualizer/sketchpad.h>

namespace idealgas {
    namespace visualizer {
        float x = cos(getElapsedSeconds() + getWindowWidth() / 2);
        float y = sin(getElapsedSeconds() + getWindowHeight() / 2);
        gl::drawSolidCircle(Vec2f(x, y), 50.0f);



    }  // namespace visualizer

}  // namespace idealgas
