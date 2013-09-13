
#include "testApp.h"

//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

/**
 * using the Addon "ofxImageSequence" created by James George in collaboration with FlightPhase
 * to download the Addon here: https://github.com/Flightphase/ofxImageSequence
 */

//A simple demo of loading and playing image sequence. Press mouse or key to start the sequence playback


//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255);
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetVerticalSync(true);

	//prefix is frame, file type is png, from frame 1 to 11, 2 digits in the number
	sequence.loadSequence("0/wakeup", "png", 0, 113, 3);
	sequence.preloadAllFrames();	//this way there is no stutter when loading frames
	sequence.setFrameRate(16); //set to ten frames per second
	
	playing = false; //controls if starts to play the sequence
    
    time=0.41;  //where to pause
    percent=0;  //the playback percentage
}

//--------------------------------------------------------------
void testApp::update(){

   
    if (playing && percent<time) {
        percent+=0.003;
        if (percent>time) {
             playing=false; 
        }
    }
    
    
    if (playing && percent>time) {
        percent+=0.003;
        if (percent>1) {
            playing=false; 
            percent=0;
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

	
    sequence.getFrameAtPercent(percent)->draw(500, 500);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    playing = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	playing = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

