/**
 * created by Martin Stolz on 24.09.22
 *
 * (c) 2022 by noizplay.com
 */

#include "MidiPluginProcessor.h"

MidiPluginProcessor::MidiPluginProcessor() = default;

void MidiPluginProcessor::prepareToPlay (double, int) {}

void MidiPluginProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer& midiMessages) {
    juce::ignoreUnused(buffer, midiMessages);
}

juce::AudioProcessorEditor* MidiPluginProcessor::createEditor() {
    return new MidiPluginEditor (*this);
}

void MidiPluginProcessor::getStateInformation (juce::MemoryBlock& destData) {
    juce::ignoreUnused(destData);
}

void MidiPluginProcessor::setStateInformation (const void* data, int sizeInBytes) {
    juce::ignoreUnused(data, sizeInBytes);
}

