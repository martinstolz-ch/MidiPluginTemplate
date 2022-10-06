/**
 * created by Martin Stolz on 07.03.22
 *
 * (c) 2022 by noizplay.com
 */

#pragma once

#include <JuceHeader.h>

namespace CMakeVars {

    #define DECLARE_VAR(name, val) const std::string name{val};

    DECLARE_VAR(COMPANY_WEBSITE, "www.noizplay.com")
    DECLARE_VAR(PROJECT_VERSION, "0.0.1")

    #undef DECLARE_VAR

}
