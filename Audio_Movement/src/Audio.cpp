

#include "Audio.h"

void Audio::setup() {
    
    ofSetVerticalSync(true);
    
    //verb = ofxAudioUnit (kAudioUnitType_FormatConverter, kAudioUnitSub
    
    varispeed = ofxAudioUnit(kAudioUnitType_FormatConverter,
							 kAudioUnitSubType_Varispeed);
    
    dist = ofxAudioUnit(kAudioUnitType_Effect,
						   kAudioUnitSubType_Distortion);
    
    //set initial parameters
    AudioUnitSetParameter(dist.getUnit(), kDistortionParam_RingModMix,
						  kAudioUnitScope_Global, 0, 100, 0);
	

    audioFile.setFile(ofFilePath::getAbsolutePath("arp_loop.aif"));
    
    audioFile.connectTo(varispeed).connectTo(dist).connectTo(output);
    
    audioFile.loop();
    output.start();
    
}


void Audio::parameters(float handX, float handY) {
    
    
    
    float newSpeed = ofMap(handX, 0, 200, 0.01, .75, true);
	
	AudioUnitSetParameter(varispeed.getUnit(),
						  kVarispeedParam_PlaybackRate,
						  kAudioUnitScope_Global,
						  0,
						  newSpeed,
						  0);
	
	float newFreq = ofMap(handY, 0, 200, 10, 6900);
	
	AudioUnitSetParameter(dist.getUnit(),
						  kDistortionParam_RingModFreq1,
						  kAudioUnitScope_Global,
						  0,
						  newFreq,
						  0);
    
}