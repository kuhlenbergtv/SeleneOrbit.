cmake_minimum_required(VERSION 3.22)

project(SeleneOrbit VERSION 1.0.0)

add_subdirectory(JUCE)

juce_add_plugin(SeleneOrbit
    COMPANY_NAME Selene
    BUNDLE_ID com.selene.orbit
    PLUGIN_MANUFACTURER_CODE Seln
    PLUGIN_CODE SlOr
    FORMATS VST3 Standalone
    PRODUCT_NAME "Selene Orbit"
)

juce_generate_juce_header(SeleneOrbit)

target_sources(SeleneOrbit PRIVATE
    src/PluginProcessor.cpp
    src/PluginEditor.cpp
)

target_compile_definitions(SeleneOrbit
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0

  target_link_libraries(SeleneOrbit
    PRIVATE
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)      
