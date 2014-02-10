
#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "move.h"

class Audio : public ofBaseApp{
    
public:
    void setup();
    void parameters(float handX, float handY);
   
    ofxAudioUnit varispeed;
    ofxAudioUnit dist;
    ofxAudioUnit verb;
    ofxAudioUnitFilePlayer audioFile; 
    ofxAudioUnitOutput output;
    
    move blobs;
    
};

