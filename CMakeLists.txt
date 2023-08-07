cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_STANDARD 20)


##########################################################################
project (MIDI_PLUGIN VERSION 0.0.1)
set     (TargetName   MidiPlugin)
set     (ProductName "Midi Plugin")
set     (PluginCode  "Nmp0")     
#        1 fixed upper case char "N" (for my company name "noizplay")
#        + 2 chars (lower case) from product name 
#        + 1 number (main version)
##########################################################################


# use CPM
include(cmake/CPM.cmake)
set(CPM_USE_NAMED_CACHE_DIRECTORIES true)
set(CPM_SOURCE_CACHE ~/.cache/CPM)

# get JUCE
CPMAddPackage("gh:juce-framework/JUCE@7.0.6#master")

# Compile commands, useful for some IDEs like VS-Code
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Minimum MacOS target, set globally
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version" FORCE)

# Universal Binary ?
option(UniversalBinary "Build universal binary for mac" ON)

if (UniversalBinary)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE INTERNAL "")
endif()

# static linking in Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

juce_add_plugin("${TargetName}"
    # VERSION ...                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...
    # ICON_SMALL ...
    COMPANY_NAME "noizplay"
    COMPANY_WEBSITE "www.noizplay.com"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    IS_MIDI_EFFECT TRUE
    # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE    # Does the editor need keyboard focus?
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE Noiz               # A four-character manufacturer id with at least one upper-case character
    PLUGIN_CODE "${PluginCode}"                 # A unique four-character plugin id with exactly one upper-case character
                                                # GarageBand 10.3 requires the first letter to be upper-case, and the remaining letters to be lower-case
    FORMATS AU VST3 Standalone                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    PRODUCT_NAME "${ProductName}")

juce_generate_juce_header("${TargetName}")

add_subdirectory(JuceModules)

target_sources("${TargetName}"
    PRIVATE
        Source/Plugin.cpp
        Source/Plugin/PluginProcessor.cpp
        )

target_compile_definitions("${TargetName}"
    PUBLIC
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_DISPLAY_SPLASH_SCREEN=1
        )

target_link_libraries("${TargetName}"
    PRIVATE
        plugin_helpers
        processing_code

        juce::juce_gui_extra
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_audio_plugin_client

        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        )

# get some JUCE properties
get_target_property(JUCE_COMPANY_WEBSITE ${TargetName} JUCE_COMPANY_WEBSITE)

# export some vars to CMakeVars.h in /Source folder
configure_file(CMakeVars.h.txt "${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/CMakeVars.h" )
