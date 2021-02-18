//
// Created by Kaleigh Spitzer on 1/31/21.
//

#ifndef IDEAL_GAS_HISTOGRAM_H
#define IDEAL_GAS_HISTOGRAM_H

#include "cinder/gl/gl.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/ideal-gas-spitzer4-2/include/core/particle.h"

namespace idealgas {
    namespace visualizer {
        class Histogram {
        public:
            Histogram();
            Histogram(glm::vec2, size_t);
            std::map<double, double> GetSpeedFreqMap();
            void Draw();
            void SetParticleVector(const std::vector<Particle>&);
            void AddToSpeedFreqMap();
        private:
            glm::vec2 position_;
            size_t size_;
            std::vector<Particle> particle_vector_;
            std::map<double, double> speed_freq_map_;
        };
    }
}

#endif //IDEAL_GAS_HISTOGRAM_H
