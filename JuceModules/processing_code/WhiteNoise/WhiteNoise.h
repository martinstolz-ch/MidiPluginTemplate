/**
 * created by Martin Stolz on 28.09.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include <JuceHeader.h>

//A very simple white noise oscillator
namespace WhiteNoise {
    class Oscillator {
    public:
        Oscillator();
        void process(juce::AudioBuffer<float>& buffer) noexcept;
        float getNextSample();

    private:
        int samplePos = 0;

        juce::Random rand;
        std::vector<float> samples;
    };
}