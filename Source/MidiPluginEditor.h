/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include <JuceHeader.h>

class MidiPluginEditor : public AudioProcessorEditor {
public:

    explicit MidiPluginEditor (AudioProcessor& parent) : AudioProcessorEditor (parent) {
        setSize (400, 200);
    }

    void paint (Graphics& graphicsContext) override {}
    void resized() override {}

private:

};
