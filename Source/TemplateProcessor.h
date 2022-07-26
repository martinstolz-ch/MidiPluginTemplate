/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include "TemplateEditor.h"
#include "Config.h"

class TemplateProcessor : public juce::AudioProcessor {
public:

    TemplateProcessor() = default;

    void prepareToPlay (double, int) override {}
    void releaseResources() override {}

    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override {}

    juce::AudioProcessorEditor* createEditor() override          { return new TemplateEditor (*this); }
    bool hasEditor() const override                              { return true; }

    const juce::String getName() const override                  { return PROJECT_NAME; }
    bool acceptsMidi() const override                            { return false; }
    bool producesMidi() const override                           { return false; }
    double getTailLengthSeconds() const override                 { return 0; }

    int getNumPrograms() override                                { return 1; }
    int getCurrentProgram() override                             { return 0; }
    void setCurrentProgram (int) override                        {}
    const juce::String getProgramName (int) override             { return {}; }
    void changeProgramName (int, const juce::String&) override   {}

    void getStateInformation (juce::MemoryBlock& destData) override {}

    void setStateInformation (const void* data, int sizeInBytes) override {}

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TemplateProcessor)
};
