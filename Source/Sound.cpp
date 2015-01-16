/*
  ==============================================================================

    Sound.cpp
    Created: 7 Feb 2014 12:56:34am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Sound.h"


/*
 ==============================================================================
 
 This file is part of the JUCE library.
 Copyright (c) 2013 - Raw Material Software Ltd.
 
 Permission is granted to use this software under the terms of either:
 a) the GPL v2 (or any later version)
 b) the Affero GPL v3
 
 Details of these licenses can be found at: www.gnu.org/licenses
 
 JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 
 ------------------------------------------------------------------------------
 
 To release a closed-source product which uses JUCE, commercial licenses are
 available: visit www.juce.com for more information.
 
 ==============================================================================
 */

Sound::Sound (const String& soundName,
                                        const int midiNoteForNormalPitch,
                                        const int soundSelection,
                                        AudioFormatReader& source)
: juce::SamplerSound(soundName,
                     source,
                     127,
                     midiNoteForNormalPitch,
                     0,
                     0,
                     10),
name (soundName),
midiRootNote (midiNoteForNormalPitch),
selection (soundSelection)
{
    midiNotes.setBit(midiNoteForNormalPitch);
    double attackTimeSecs = 0.001;
    double releaseTimeSecs = 0.001;
    double maxSampleLengthSeconds = 10;
    
    sourceSampleRate = source.sampleRate;
    
    if (sourceSampleRate <= 0 || source.lengthInSamples <= 0)
    {
        length = 0;
        attackSamples = 0;
        releaseSamples = 0;
    }
    else
    {
        length = jmin ((int) source.lengthInSamples,
                       (int) (maxSampleLengthSeconds * sourceSampleRate));
        
        data = new AudioSampleBuffer (jmin (2, (int) source.numChannels), length + 4);
        
        source.read (data, 0, length + 4, 0, true, true);
        
        attackSamples = roundToInt (attackTimeSecs * sourceSampleRate);
        releaseSamples = roundToInt (releaseTimeSecs * sourceSampleRate);
    }
    
}

Sound::~Sound()
{
}

bool Sound::appliesToNote (const int midiNoteNumber)
{
    return midiNoteNumber == midiRootNote;
}

bool Sound::appliesToChannel (const int /*midiChannel*/)
{
    return true;
}

bool Sound::appliesToSelection (int askedSelection)
{
    return askedSelection == selection;
}
