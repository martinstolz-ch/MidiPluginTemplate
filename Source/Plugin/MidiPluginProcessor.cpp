/**
 * created by Martin Stolz on 24.09.22
 *
 * (c) 2022 by noizplay.com
 */

#include "MidiPluginProcessor.h"

MidiPluginProcessor::MidiPluginProcessor() = default;

void MidiPluginProcessor::prepareToPlay (double, int) {}
void MidiPluginProcessor::releaseResources() {}

void MidiPluginProcessor::processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer& midiMessages) {
    juce::ignoreUnused(buffer, midiMessages);
}

juce::AudioProcessorEditor* MidiPluginProcessor::createEditor() {
    return new MidiPluginEditor (*this);
}
bool MidiPluginProcessor::hasEditor() const {
    return true;
}

const juce::String MidiPluginProcessor::getName() const {
    return JucePlugin_Name;
}
bool MidiPluginProcessor::acceptsMidi() const {
    return false;
}
bool MidiPluginProcessor::producesMidi() const {
    return false;
}
double MidiPluginProcessor::getTailLengthSeconds() const {
    return 0;
}

int MidiPluginProcessor::getNumPrograms() {
    return 1;
}
int MidiPluginProcessor::getCurrentProgram() {
    return 0;
}
void MidiPluginProcessor::setCurrentProgram (int) {}
const juce::String MidiPluginProcessor::getProgramName (int) {
    return {};
}
void MidiPluginProcessor::changeProgramName (int, const juce::String&) {}

void MidiPluginProcessor::getStateInformation (juce::MemoryBlock& destData) {
    juce::ignoreUnused(destData);
}

void MidiPluginProcessor::setStateInformation (const void* data, int sizeInBytes) {
    juce::ignoreUnused(data, sizeInBytes);
}

