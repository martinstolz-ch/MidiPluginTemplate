/**
 * (c) martin.stolz@noizplay.com
 */

#pragma once

#include <JuceHeader.h>

namespace cmakeVar {

    static const String
        buildYear {"@buildYear@"},

        companyName {"@companyName@"},
        companyURL {"@companyURL@"},

        projectVersion {"@PROJECT_VERSION@"},
        projectName {"@PROJECT_NAME@"};

}
