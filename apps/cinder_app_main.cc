#include <visualizer/ideal_gas_app.h>

using idealgas::visualizer::ideal_gas_app;

void prepareSettings(ideal_gas_app::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(ideal_gas_app, ci::app::RendererGl, prepareSettings);
