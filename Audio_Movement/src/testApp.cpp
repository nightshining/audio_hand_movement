#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    move.setup();
    handPos.set(0, 0, 0);
    sound.setup();
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    move.update();
    handPos.x = ofMap(move.getCentroid.x, 0, 100, 25, 255);
    handPos.y = ofMap(move.getCentroid.y, 0, 100, 25, 255);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor::whiteSmoke, ofColor::gray);
    
    //title
    ofDrawBitmapString("Floating Hand Audio Manipulation", 25, 25);

    
    //slider 1 
    ofSetColor(255);
    ofNoFill();
    ofRect(0, ofGetHeight() - 100, handPos.x, 25);
    ofDrawBitmapString("Effect Parameter 1", 0, ofGetHeight() - 103);
    ofSetColor(100, 0, 0, 90);
    ofFill();
    ofRect(0, ofGetHeight() - 100, handPos.x, 25);

    
    //slider 2
    ofSetColor(255);
    ofNoFill();
    ofRect(0, ofGetHeight() - 50, handPos.y, 25);
    ofDrawBitmapString("Effect Parameter 1", 0, ofGetHeight() - 53);
    ofSetColor(100, 100, 100, 90);
    ofFill();
    ofRect(0, ofGetHeight() - 50, handPos.y, 25);
    
    //target
    ofPushMatrix();
    ofTranslate(200, 100);
    //fill rect
    ofSetColor(100, 0, 0, 80);
    ofFill();
    ofRect(0, 0, 400, 400);
    //rect border
    ofSetColor(255);
    ofNoFill();
    ofRect(0, 0, 400, 400);
    //lines
    ofLine(0 + ofClamp(handPos.x, 0, 400), 0, 0 + ofClamp(handPos.x, 0, 400), 400);
    ofLine(0, 0 + ofClamp(handPos.y, 0, 400), 400, 0 + ofClamp(handPos.y, 0, 400));
    


    ofPopMatrix();
    
    move.draw();

    sound.parameters(handPos.x, handPos.y);
    
    //cout << move.getCentroid.x << endl;
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

    move.keyPressed(key);
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){


}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    move.cvPos.x = x;
    move.cvPos.y = y;
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    move.cvPos.x = x;
    move.cvPos.y = y;
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
