#include "PluginEditor.h"

SeleneOrbitAudioProcessorEditor::SeleneOrbitAudioProcessorEditor(
    SeleneOrbitAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    addAndMakeVisible(frontButton);
    addAndMakeVisible(backButton);

    frontButton.onClick = [this] {
        showingBack = false;
        repaint();
    };

    backButton.onClick = [this] {
        showingBack = true;
        repaint();
    };

    setSize(800, 400);
}

void SeleneOrbitAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour::fromRGB(35, 12, 55));

    g.setColour(juce::Colour::fromRGB(125, 55, 180));
    g.fillRoundedRectangle(
        getLocalBounds().toFloat().reduced(15), 15.0f);

    g.setColour(juce::Colours::white);

    g.setFont(juce::Font(42.0f));
    g.drawText("Selene", 40, 30, 250, 60,
               juce::Justification::centredLeft);

    g.setFont(juce::Font(30.0f));
    g.drawText("ORBIT", 290, 35, 200, 50,
               juce::Justification::centredLeft);

    g.setFont(juce::Font(20.0f));

    if (showingBack)
        g.drawText("BACK PANEL - CLIPPER / MONO BASS",
                   50, 160, 700, 60,
                   juce::Justification::centred);
    else
        g.drawText("FRONT PANEL - STEREO SUMMING",
                   50, 160, 700, 60,
                   juce::Justification::centred);
}

void SeleneOrbitAudioProcessorEditor::resized()
{
    frontButton.setBounds(550, 40, 100, 35);
    backButton.setBounds(660, 40, 100, 35);
}
