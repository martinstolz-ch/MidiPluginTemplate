/**
 * (c) martin.stolz@noizplay.com
 */

#pragma once

#include "../etc/cmakeVar.h"
#include "../etc/appConfig.h"

#include "PluginProcessor.h"

class PluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PluginEditor(PluginProcessor& processorToUse): AudioProcessorEditor{processorToUse} {
        setSize(400, 200);
    }

    void paint (juce::Graphics& gContext) override {
        gContext.setColour(appConfig::mainColor);
        gContext.setFont (FontOptions().withStyle ("light"));
        gContext.drawFittedText(
            cmakeVar::companyURL,
            getLocalBounds(),
            juce::Justification::centredBottom,
            1);
    }

    void resized() override {}
};
