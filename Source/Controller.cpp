/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"

Controller::Controller() : source(keyboardState)
{
    bootstrap();
}

Controller::~Controller()
{

}

void Controller::bootstrap()
{
    audioDeviceManager.initialise (2, 2, 0, true, String::empty, 0);
    audioSourcePlayer.setSource(&source);
    audioDeviceManager.addAudioCallback(&audioSourcePlayer);
}

/*
int Controller::getSelectedTrack() {
    return selectedTrack;
}
*/
void Controller::playNote(int note) {
    source.noteOn(1, note, 127.0);
}

void Controller::setTrackSample(int selection){
    
    //if(index == -1) {
    //	index = getSelectedTrack();
    //}
    
    Track* trackToApply;
    trackToApply = source.getTrackByIndex(0);
    trackToApply->setSelection(selection);
}

void Controller::setMaster(float value) {
	source.setMaster(value);
}
