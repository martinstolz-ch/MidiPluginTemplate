/**
 * created by Martin Stolz on 24.09.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include <JuceHeader.h>

class AudioProcessorBase : public juce::AudioProcessor {
public:
    AudioProcessorBase();
    explicit AudioProcessorBase(BusesProperties const&);

    void prepareToPlay(double, int) override;
    void releaseResources() override;

    bool isBusesLayoutSupported(BusesLayout const&) const override;

    using AudioProcessor::processBlock;

    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(void const*, int) override;

    juce::AudioProcessorEditor* createEditor() override;

    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int) override;
    juce::String const getProgramName(int) override;
    void changeProgramName(int, juce::String const&) override;

    static BusesProperties getDefaultProperties();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioProcessorBase)
};
