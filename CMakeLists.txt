cmake_minimum_required(VERSION 3.28)

set (CMAKE_CXX_STANDARD 20)

###############################################################################
# (c) martin.stolz@noizplay.com
###############################################################################
project (MIDI_PLUGIN VERSION 0.0.1)
set     (TargetName    ${PROJECT_NAME})
set     (ProductName  "Midi Plugin")
set     (PluginCode   "Nmp0")
#        1 fixed upper case char "N" (for my brand "noizplay")
#        + 2 chars (lower case) from product name
#        + 1 number (main version)

set (companyName "noizplay")
set (companyURL "noizplay.com")
###############################################################################

# initialise
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property (GLOBAL PROPERTY USE_FOLDERS YES)
option (JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

# we are Mac ?
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set (CMAKE_OSX_DEPLOYMENT_TARGET "13.0" CACHE STRING "Minimum OS X deployment version" FORCE)
    set (CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE INTERNAL "")
    set (MACOSX_BUNDLE TRUE) # create .app bundle for mac
    message (STATUS "Build for Mac")

    # ...or Win ?
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") # static linking in Windows
    message (STATUS "Build for Windows")

    # ...nope :/
else ()
    message (FATAL_ERROR "No viable platform found")
endif ()

# fetch external repos
include(FetchContent)

message (STATUS "Fetch JUCE")
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 8.0.1
)
FetchContent_MakeAvailable(JUCE)

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
        JUCE_DISPLAY_SPLASH_SCREEN=0
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

# create cmakeVars.h
get_target_property (COMPANY_WEBSITE ${TargetName} JUCE_COMPANY_WEBSITE)
string (TIMESTAMP buildYear "%Y")
configure_file (template/cmakeVar.h.tpl "${CMAKE_CURRENT_SOURCE_DIR}/source/etc/cmakeVar.h" )
