#include "PluginProcessor.h"
#include "PluginEditor.h"

SeleneOrbitAudioProcessor::SeleneOrbitAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

void SeleneOrbitAudioProcessor::prepareToPlay(double, int)
{
}

void SeleneOrbitAudioProcessor::releaseResources()
{
}

void SeleneOrbitAudioProcessor::processBlock(
    juce::AudioBuffer<float>& buffer,
    juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;

    for (int channel = getTotalNumInputChannels();
         channel < getTotalNumOutputChannels(); ++channel)
        buffer.clear(channel, 0, buffer.getNumSamples());
}

juce::AudioProcessorEditor*
SeleneOrbitAudioProcessor::createEditor()
{
    return new SeleneOrbitAudioProcessorEditor(*this);
}

bool SeleneOrbitAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String SeleneOrbitAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SeleneOrbitAudioProcessor::acceptsMidi() const { return false; }
bool SeleneOrbitAudioProcessor::producesMidi() const { return false; }
bool SeleneOrbitAudioProcessor::isMidiEffect() const { return false; }
double SeleneOrbitAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int SeleneOrbitAudioProcessor::getNumPrograms() { return 1; }
int SeleneOrbitAudioProcessor::getCurrentProgram() { return 0; }
void SeleneOrbitAudioProcessor::setCurrentProgram(int) {}
const juce::String SeleneOrbitAudioProcessor::getProgramName(int)
{
    return {};
}
void SeleneOrbitAudioProcessor::changeProgramName(
    int, const juce::String&) {}

void SeleneOrbitAudioProcessor::getStateInformation(
    juce::MemoryBlock&) {}

void SeleneOrbitAudioProcessor::setStateInformation(
    const void*, int) {}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SeleneOrbitAudioProcessor();
}
