//
// Created by Kaleigh Spitzer on 1/31/21.
//

#include "visualizer/histogram.h"

idealgas::visualizer::Histogram::Histogram() {
}

idealgas::visualizer::Histogram::Histogram(glm::vec2 position, size_t size) {
    position_ = position;
    size_ = size;
}

void idealgas::visualizer::Histogram::Draw() {
    ci::gl::color(ci::Color(1, 1, 1));
    ci::Rectf rectf(position_, {position_.x + size_, position_.y - size_});
    ci::gl::drawStrokedRect(rectf);
    ci::gl::drawStringCentered("Speed", {position_.x + 50, position_.y - 120}, ci::Color(1, 1, 1), ci::Font("Arial", 20));
    ci::gl::drawStringCentered("Frequency", {position_.x - 50, position_.y - 50}, ci::Color(1, 1, 1), ci::Font("Arial", 20));

    double width;
    if (speed_freq_map_.empty()) {
        width = 0;
    } else {
        width = size_ / speed_freq_map_.size();
    }
    glm::vec2 vec = position_;
    for (auto const &i : speed_freq_map_) {
        double freq = speed_freq_map_[i.first];
        freq *= 4;
        glm::vec2 height = position_ - glm::vec2(0, freq);
//        height *= 5;
        vec += glm::vec2(width, 0);
        ci::Rectf rectf1(height, vec);
        ci::gl::drawSolidRect(rectf1);
    }
}

void idealgas::visualizer::Histogram::SetParticleVector(const std::vector<Particle> &particle_vector) {
    particle_vector_ = particle_vector;
}

void idealgas::visualizer::Histogram::AddToSpeedFreqMap() {
    speed_freq_map_.clear();
    for (Particle particle : particle_vector_) {
        double speed = glm::length(particle.GetVelocity());
        speed_freq_map_[speed]++;
    }
}