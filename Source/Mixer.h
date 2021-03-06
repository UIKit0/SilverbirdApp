/*
  ==============================================================================

    Mixer.h
    Created: 16 Jan 2015 11:11:23am
    Author:  Karl

  ==============================================================================
*/

#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

#include "JuceHeader.h"
#include "Source.h"
#include "Parameter.h"

class Mixer : public MixerAudioSource {
public:
    Mixer(OwnedArray<Parameter>* parameters);
    ~Mixer();
    
    // FIXME : create struct and refactor project accordingly
    struct tracks {
        enum {
            kick,
            snare,
            hihat,
            perc1,
            perc2,
            tones,
            max
        };
    };
    
    struct mods {
        enum {
            sample,
            pitch,
            decay,
            cutoff,
            max
        };
    };
    
    static const int SelectAllOffset = 21;
    static String getNameByTrackId(int trackId, bool isModulationTrack = false);
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;
    
    void playNote(int note, float velocity);
    
    int getNumberOfSoundsByTrack(int track);
    
    void setColumnModulations(Array<float>* currentModulations);
    
    OwnedArray<Source> sources;
    MidiMessageCollector midiCollector;
    OwnedArray<Parameter>* parameters;
    
protected:
    
    void createAndAddTrack(int trackId);
    
    Source* getTrackById(int trackId);
    
    MidiKeyboardState keyboardState;
    
    float lastLevel = 1;
};

#endif  // MIXER_H_INCLUDED
