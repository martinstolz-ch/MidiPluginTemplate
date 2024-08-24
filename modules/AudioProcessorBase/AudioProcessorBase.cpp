#pragma once

#include "AudioProcessorBase.h"

AudioProcessorBase::AudioProcessorBase() = default;
AudioProcessorBase::AudioProcessorBase(BusesProperties const& ioLayouts): AudioProcessor(ioLayouts) {}

String const AudioProcessorBase::getName() const {
    return JucePlugin_Name;
}

bool AudioProcessorBase::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool AudioProcessorBase::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool AudioProcessorBase::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double AudioProcessorBase::getTailLengthSeconds() const {
    return 0.0;
}

int AudioProcessorBase::getNumPrograms() {
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int AudioProcessorBase::getCurrentProgram() {
    return 0;
}

void AudioProcessorBase::setCurrentProgram(int index) {
    ignoreUnused(index);
}

String const AudioProcessorBase::getProgramName(int index) {
    ignoreUnused(index);
    return {};
}

void AudioProcessorBase::changeProgramName(int index, String const& newName) {
    ignoreUnused(index, newName);
}

void AudioProcessorBase::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    ignoreUnused(sampleRate, samplesPerBlock);
}

void AudioProcessorBase::releaseResources() {}

juce::AudioProcessor::BusesProperties AudioProcessorBase::getDefaultProperties() {
    return BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
        ;
}

AudioProcessorEditor* AudioProcessorBase::createEditor() {
    return new GenericAudioProcessorEditor(*this);
}

bool AudioProcessorBase::hasEditor() const {
    return true;
}

bool AudioProcessorBase::isBusesLayoutSupported(AudioProcessor::BusesLayout const& layouts) const {
    if (isMidiEffect()) {
        return true;
    } else {
        if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
            && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo()) {
            return false;
        }
    }

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet()) {
        return false;
    }
#endif
    return true;
}

void AudioProcessorBase::getStateInformation(MemoryBlock& destData) {
    ignoreUnused(destData);
}

void AudioProcessorBase::setStateInformation(const void* data, int sizeInBytes) {
    ignoreUnused(data, sizeInBytes);
}
