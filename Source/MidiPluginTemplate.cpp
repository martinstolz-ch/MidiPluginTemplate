/**
 * created by Martin Stolz on 04.06.22
 *
 * (c) 2022 by noizplay.com
 */

#include <JuceHeader.h>
#include "TemplateProcessor.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new TemplateProcessor();
}
