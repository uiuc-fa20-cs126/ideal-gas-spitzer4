//
// Created by Kaleigh Spitzer on 1/31/21.
//

#include "visualizer/histogram.h"

idealgas::visualizer::Histogram::Histogram() {
}

idealgas::visualizer::Histogram::Histogram(glm::vec2 position, size_t size) {
    position_ = position;
    size_ = size;
    for (int i = 0; i <= 3; i++) {
        speed_freq_map_.insert(std::pair<double, double>(i, 0));
    }
}

std::map<double, double> idealgas::visualizer::Histogram::GetSpeedFreqMap() {
    return speed_freq_map_;
}

void idealgas::visualizer::Histogram::Draw() {
    glm::vec2 bottom_left = {position_.x, position_.y};
    ci::gl::color(ci::Color(1, 1, 1));
//    ci::Rectf rectf(position_, {position_.x + size_, position_.y - size_});
    ci::Rectf rectf(glm::vec2(position_.x, position_.y - size_), glm::vec2(position_.x + size_, position_.y));
    ci::gl::drawStrokedRect(rectf);
    ci::gl::drawStringCentered("Speed", {position_.x + 50, position_.y - 120}, ci::Color(1, 1, 1), ci::Font("Arial", 20));
    ci::gl::drawStringCentered("Frequency", {position_.x - 50, position_.y - 50}, ci::Color(1, 1, 1), ci::Font("Arial", 20));

    double width;
    if (speed_freq_map_.empty()) {
        width = 0;
    } else {
        width = (double) size_ / speed_freq_map_.size();
    }

    for (auto &i : speed_freq_map_) {
        double num_particles = speed_freq_map_[i.first];

//        ci::Rectf rectf1(bottom_left.x, bottom_left.y, bottom_left.x + width, bottom_left.y - ((num_particles / 20) * 100));
        double x1 = bottom_left.x;
        double y1 = bottom_left.y;
        double x2 = bottom_left.x + width;
        double y2 = bottom_left.y - ((num_particles / 20) * 80);

        ci::Rectf rectf1(x1, y1, x2, y2);

        ci::gl::drawSolidRect(rectf1);

        bottom_left = {bottom_left.x + width, bottom_left.y};
        if (bottom_left.x >= position_.x + size_) {
            bottom_left.x = position_.x;
        }
    }
}

void idealgas::visualizer::Histogram::SetParticleVector(const std::vector<Particle> &particle_vector) {
    particle_vector_ = particle_vector;
}

void idealgas::visualizer::Histogram::AddToSpeedFreqMap() {
    speed_freq_map_.clear();
    for (Particle particle : particle_vector_) {
        double speed = glm::length(particle.GetVelocity());
        if (speed < 2) {
            speed_freq_map_[0]++;
        } else if (speed >= 2 && speed < 4) {
            speed_freq_map_[1]++;
        } else if (speed >= 4 && speed < 6) {
            speed_freq_map_[2]++;
        } else if (speed >= 6) {
            speed_freq_map_[3]++;
        }
//        speed_freq_map_[speed]++;
    }
}