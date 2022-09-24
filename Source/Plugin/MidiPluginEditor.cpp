/**
 * created by Martin Stolz on 24.09.22
 *
 * (c) 2022 by noizplay.com
 */

#include "../Common/CMakeVars.h"
#include "../Common/Config.h"

#include "MidiPluginEditor.h"

MidiPluginEditor::MidiPluginEditor(AudioProcessor& audioProcessor): AudioProcessorEditor{audioProcessor} {
    setSize(400, 200);
}

void MidiPluginEditor::paint (Graphics& gContext) {
    gContext.setColour(Config::MAIN_COLOUR);
    gContext.setFont(
            {Config::DEFAULT_TEXT_SIZE, juce::Font::FontStyleFlags::plain }
    );
    gContext.drawFittedText(
            CMakeVars::JUCE_COMPANY_WEBSITE,
            getLocalBounds(),
            juce::Justification::bottomLeft,
            1);
}

void MidiPluginEditor::resized() {}
