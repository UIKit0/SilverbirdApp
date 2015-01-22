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

#include "Stepper.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Stepper::Stepper (Controller* controller)
    : controller(controller)
{
    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Stepper")));
    label->setFont (Font (10.00f, Font::plain));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xffddd8d2));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 60);


    //[Constructor] You can add your own custom stuff here..
    controller->addClockListener(this);
    //[/Constructor]
}

Stepper::~Stepper()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Stepper::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xe5000000));

    //[UserPaint] Add your own custom painting code here..
    
    int trackId = controller->mixer.getTrackByName(getComponentID());
    int numCells = controller->sequencer->getNumCells();
    
    Array<float> cells = controller->sequencer->getCells(trackId);

    float cellWidth = (float) getWidth() / (float) numCells;

    for (int i=0; i<numCells; i++) {

        // default value color
        g.setColour (Colour (0xffffeb86));
        
        if (cursor == i) {
            // active background colour
            g.setColour (Colour (0xe5333333));
            
            // painting active background
            g.fillRect(
                       (float) i * cellWidth,
                       (float) 0,
                       (float) cellWidth,
                       (float) getHeight()
                       );
            
            // active value colour
            g.setColour (Colour (0xffbfab46));
        }
        
        g.fillRect(
           (float) i * cellWidth,
           (float) getHeight() - cells.getUnchecked(i) * getHeight(),
           (float) cellWidth,
           (float) cells.getUnchecked(i) * getHeight()
        );

        if(i==0) continue;
        g.setColour (Colour (0x55666666));
        g.drawLine(i * cellWidth, 0, i * cellWidth, getHeight());
    }

    g.setColour (Colour (0xff777777));
    g.drawRect(0, 0, getWidth(), getHeight());

    //[/UserPaint]
}

void Stepper::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (-2, 0, 42, 11);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Stepper::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    
    int numCells = controller->sequencer->getNumCells();

    float cellWidth = getWidth() / numCells;
    int cellId = fmax(0, fmin(numCells, floor(e.getPosition().getX() / cellWidth)));

    float value = fmin(1, fmax(0, ((float) getHeight() - (float) e.getPosition().getY()) / (float) getHeight()));
    
    controller->sequencer->setCell(controller->mixer.getTrackByName(getComponentID()), cellId, value);

    repaint();

    //[/UserCode_mouseDown]
}

void Stepper::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    mouseDown(e);
    //[/UserCode_mouseDrag]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Stepper::clockStep(int cursor)
{
    this->cursor = cursor;
    repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Stepper" componentName=""
                 parentClasses="public Component, public ClockListener" constructorParams="Controller* controller"
                 variableInitialisers="controller(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="400" initialHeight="60">
  <METHODS>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="e5000000"/>
  <LABEL name="new label" id="d5d914557b2ab44f" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="-2 0 42 11" textCol="ffddd8d2" edTextCol="ff000000"
         edBkgCol="0" labelText="Stepper" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="10"
         bold="0" italic="0" justification="9"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
