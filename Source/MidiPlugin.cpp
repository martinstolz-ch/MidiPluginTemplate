/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#include "Plugin/MidiPluginProcessor.h"

#include <JuceHeader.h>

AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new MidiPluginProcessor();
}
