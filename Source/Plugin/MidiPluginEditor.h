/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include <JuceHeader.h>

class MidiPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit MidiPluginEditor (juce::AudioProcessor&);

    void paint (Graphics&) override;
    void resized() override;
};
