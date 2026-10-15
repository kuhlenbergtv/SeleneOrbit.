#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class SeleneOrbitAudioProcessorEditor
    : public juce::AudioProcessorEditor
{
public:
    explicit SeleneOrbitAudioProcessorEditor(
        SeleneOrbitAudioProcessor&);

    ~SeleneOrbitAudioProcessorEditor() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    SeleneOrbitAudioProcessor& processor;

    juce::TextButton frontButton {"FRONT"};
    juce::TextButton backButton {"BACK"};

    bool showingBack = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
        SeleneOrbitAudioProcessorEditor)
};
