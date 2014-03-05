/*
  ==============================================================================

    Voice.h
    Created: 7 Feb 2014 12:59:57am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef SILVERSAMPLERVOICE_H_INCLUDED
#define SILVERSAMPLERVOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sound.h"


class Voice : public SynthesiserVoice
{
public:
    //==============================================================================
    /** Creates a SamplerVoice. */
    Voice();
    
    /** Destructor. */
    ~Voice();
    
    //==============================================================================
    bool canPlaySound (SynthesiserSound*) override;
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound*, int pitchWheel) override;
    void stopNote (bool allowTailOff) override;
    
    void pitchWheelMoved (int newValue);
    void controllerMoved (int controllerNumber, int newValue) override;
    
    void renderNextBlock (AudioSampleBuffer&, int startSample, int numSamples) override;
    
    
private:
    //==============================================================================
    double pitchRatio;
    double sourceSamplePosition;
    float lgain, rgain, attackReleaseLevel, attackDelta, releaseDelta;
    bool isInAttack, isInRelease;
    
    JUCE_LEAK_DETECTOR (Voice)
};


#endif  // SILVERSAMPLERVOICE_H_INCLUDED
