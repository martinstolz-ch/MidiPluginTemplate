/**
 * (c) martin.stolz@noizplay.com
 */

#include "Plugin/PluginProcessor.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
