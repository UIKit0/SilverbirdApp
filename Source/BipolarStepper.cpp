/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "BipolarStepper.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
BipolarStepper::BipolarStepper (Controller* controller, int trackId, bool isModulationTrack)
    : Stepper(controller, trackId, isModulationTrack), controller(controller)
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 60);


    //[Constructor] You can add your own custom stuff here..

    //[/Constructor]
}

BipolarStepper::~BipolarStepper()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..

    // HINT: doesnt need to remove from clockListeners, because parent is taking care of it.

    //[/Destructor]
}

//==============================================================================
void BipolarStepper::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xe51f1f1f));

    //[UserPaint] Add your own custom painting code here..
    Stepper::paint(g);
    //[/UserPaint]
}

void BipolarStepper::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool BipolarStepper::isBipolar()
{
    return true;
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="BipolarStepper" componentName=""
                 parentClasses="public Stepper" constructorParams="Controller* controller, int trackId, bool isModulationTrack"
                 variableInitialisers="Stepper(controller, trackId, isModulationTrack), controller(controller)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="400" initialHeight="60">
  <BACKGROUND backgroundColour="e51f1f1f"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
