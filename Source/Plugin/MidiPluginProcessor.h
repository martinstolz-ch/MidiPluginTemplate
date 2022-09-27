/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include <plugin_helpers/plugin_helpers.h>
#include "MidiPluginEditor.h"

#include <JuceHeader.h>

class MidiPluginProcessor: public AudioProcessorBase {
public:
    MidiPluginProcessor();

    void prepareToPlay (double, int) override;

    void processBlock (juce::AudioSampleBuffer&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;

    void getStateInformation (juce::MemoryBlock&) override;
    void setStateInformation (const void*, int) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiPluginProcessor)
};
