/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include "../Common/CMakeVars.h"
#include "../Common/Config.h"

#include "PluginProcessor.h"

class PluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PluginEditor(PluginProcessor& processorToUse): AudioProcessorEditor{processorToUse} {
        setSize(400, 200);
    }

    void paint (juce::Graphics& gContext) override {
        gContext.setColour(Config::MAIN_COLOUR);
        gContext.setFont(
                {
                        Config::DEFAULT_TEXT_SIZE,
                        juce::Font::FontStyleFlags::plain }
        );
        gContext.drawFittedText(
                CMakeVars::COMPANY_WEBSITE,
                getLocalBounds(),
                juce::Justification::bottomLeft,
                1);
    }

    void resized() override {}
};
