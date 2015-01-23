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

#ifndef __JUCE_HEADER_1B7D314A9B5D26__
#define __JUCE_HEADER_1B7D314A9B5D26__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Controller.h"
//[/Headers]

#include "Stepper.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Gui  : public Component,
             public SliderListener,
             public ButtonListener
{
public:
    //==============================================================================
    Gui (Controller* controller);
    ~Gui();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* background_png;
    static const int background_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Controller* controller;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;
    ScopedPointer<Slider> masterSlider;
    ScopedPointer<ToggleButton> kickMuteButton;
    ScopedPointer<ToggleButton> snareMuteButton;
    ScopedPointer<ToggleButton> HihatMuteButton;
    ScopedPointer<Slider> kickVolumeSlider;
    ScopedPointer<Slider> snareVolumeSlider;
    ScopedPointer<Slider> hihatVolumeSlider;
    ScopedPointer<Label> label7;
    ScopedPointer<Label> label8;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label11;
    ScopedPointer<TabbedComponent> tabbedComponent;
    ScopedPointer<Slider> sampleAllSlider;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> pitchSlider;
    ScopedPointer<Label> label3;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Label> label4;
    ScopedPointer<Slider> distortSlider;
    ScopedPointer<Label> label5;
    ScopedPointer<Slider> cutoffSlider;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> shuffleSlider;
    ScopedPointer<Label> label10;
    ScopedPointer<Stepper> kickStepper;
    ScopedPointer<Stepper> snareStepper;
    ScopedPointer<Stepper> hihatStepper;
    Image cachedImage_background_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1B7D314A9B5D26__
