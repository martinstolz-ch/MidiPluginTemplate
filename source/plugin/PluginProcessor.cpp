/**
 * (c) martin.stolz@noizplay.com
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor() = default;

void PluginProcessor::prepareToPlay (double, int) {}

void PluginProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer& midiMessages) {
    juce::ignoreUnused(buffer, midiMessages);
}

juce::AudioProcessorEditor* PluginProcessor::createEditor() {
    return new PluginEditor (*this);
}

void PluginProcessor::getStateInformation (juce::MemoryBlock& destData) {
    juce::ignoreUnused(destData);
}

void PluginProcessor::setStateInformation (const void* data, int sizeInBytes) {
    juce::ignoreUnused(data, sizeInBytes);
}

