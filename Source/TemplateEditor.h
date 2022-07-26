/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include "Config.h"

class TemplateEditor : public juce::AudioProcessorEditor {
public:

    explicit TemplateEditor (juce::AudioProcessor& parent) : AudioProcessorEditor (parent) {
        setSize (400, 200);
    }

    void paint (juce::Graphics& graphicsContext) override {}
    void resized() override {}

private:

};
