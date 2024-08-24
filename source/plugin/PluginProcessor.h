/**
 * (c) martin.stolz@noizplay.com
 */

#pragma once

#include <plugin_helpers/plugin_helpers.h>

#include <JuceHeader.h>

class PluginProcessor: public AudioProcessorBase {
public:
    PluginProcessor();

    void prepareToPlay (double, int) override;

    void processBlock (juce::AudioSampleBuffer&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;

    void getStateInformation (juce::MemoryBlock&) override;
    void setStateInformation (const void*, int) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginProcessor)
};
