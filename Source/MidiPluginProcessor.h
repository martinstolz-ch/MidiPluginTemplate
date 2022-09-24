/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include "MidiPluginEditor.h"

#include <JuceHeader.h>

class MidiPluginProcessor : public juce::AudioProcessor {
public:

    MidiPluginProcessor() = default;

    void prepareToPlay (double, int) override {}
    void releaseResources() override {}

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer&) override {}

    juce::AudioProcessorEditor* createEditor() override          { return new MidiPluginEditor (*this); }
    bool hasEditor() const override                              { return true; }

    const String getName() const override                  { return JucePlugin_Name; }
    bool acceptsMidi() const override                            { return false; }
    bool producesMidi() const override                           { return false; }
    double getTailLengthSeconds() const override                 { return 0; }

    int getNumPrograms() override                                { return 1; }
    int getCurrentProgram() override                             { return 0; }
    void setCurrentProgram (int) override                        {}
    const String getProgramName (int) override             { return {}; }
    void changeProgramName (int, const String&) override   {}

    void getStateInformation (MemoryBlock& destData) override {}

    void setStateInformation (const void* data, int sizeInBytes) override {}

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiPluginProcessor)
};
