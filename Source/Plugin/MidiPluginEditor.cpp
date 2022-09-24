/**
 * created by Martin Stolz on 24.09.22
 *
 * (c) 2022 by noizplay.com
 */

#include "MidiPluginEditor.h"

MidiPluginEditor::MidiPluginEditor(AudioProcessor& audioProcessor): AudioProcessorEditor{audioProcessor} {
    setSize (400, 200);
}

void MidiPluginEditor::paint (Graphics& graphicsContext) {
    juce::ignoreUnused(graphicsContext);
}
void MidiPluginEditor::resized() {}
