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

    juce::ColourGradient metallic(
        juce::Colour::fromRGB(190, 125, 225), 0.0f, 0.0f,
        juce::Colour::fromRGB(65, 25, 110), 0.0f, (float)getHeight(),
        false);
    metallic.addColour(0.45, juce::Colour::fromRGB(130, 65, 185));
    g.setGradientFill(metallic);
    g.fillRoundedRectangle(
        getLocalBounds().toFloat().reduced(15), 15.0f);

    g.setColour(juce::Colours::white);

    g.setFont(juce::Font(42.0f));
    g.drawText("Selene", 40, 30, 250, 60,
               juce::Justification::centredLeft);

    g.setFont(juce::Font(30.0f));
    g.drawText("ORBIT", 290, 35, 200, 50,
               juce::Justification::centredLeft);


    // Selene Orbit - eight summing channel controls
    if (!showingBack)
    {
        for (int i = 0; i < 8; ++i)
        {
            const float x = 85.0f + i * 90.0f;
            const float y = 270.0f;

            g.setColour(juce::Colour::fromRGB(55, 25, 75));
            g.fillEllipse(x - 30.0f, y - 30.0f, 60.0f, 60.0f);

            g.setColour(juce::Colour::fromRGB(190, 115, 240));
            g.drawEllipse(x - 30.0f, y - 30.0f, 60.0f, 60.0f, 3.0f);
            g.drawLine(x, y, x, y - 23.0f, 3.0f);

            g.setColour(juce::Colours::white);
            g.setFont(14.0f);
            g.drawText(juce::String(i + 1),
                       juce::Rectangle<int>((int)x - 20, 315, 40, 25),
                       juce::Justification::centred);
        }
    }

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
