/**
 * (c) martin.stolz@noizplay.com
 */

#include "plugin/PluginProcessor.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
