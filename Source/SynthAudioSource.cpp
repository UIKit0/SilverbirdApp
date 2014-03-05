/*
 ==============================================================================
 
 SynthAudioSource.cpp
 Created: 30 Jan 2014 2:31:23am
 Author:  Pannek Karl
 
 ==============================================================================
 */

#include "SynthAudioSource.h"


SynthAudioSource::SynthAudioSource (MidiKeyboardState& keyState)
: keyboardState (keyState)
{
}

void SynthAudioSource::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    midiCollector.reset (sampleRate);
    
    synth.updateSampleRate(sampleRate);
}

void SynthAudioSource::releaseResources()
{
}

void SynthAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // the synth always adds its output to the audio buffer, so we have to clear it
    // first..
    bufferToFill.clearActiveBufferRegion();
    
    // fill a midi buffer with incoming messages from the midi input.
    MidiBuffer incomingMidi;
    midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);
    
    // pass these messages to the keyboard state so that it can update the component
    // to show on-screen which keys are being pressed on the physical midi keyboard.
    // This call will also add midi messages to the buffer which were generated by
    // the mouse-clicking on the on-screen keyboard.
    keyboardState.processNextMidiBuffer (incomingMidi, 0, bufferToFill.numSamples, true);
    
    // and now get the synth to process the midi events and generate its output.
    synth.renderNextBlock (*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);

    bufferToFill.buffer->applyGain(gain);
}

void SynthAudioSource::setGain (float value) {
    gain = value;
}

