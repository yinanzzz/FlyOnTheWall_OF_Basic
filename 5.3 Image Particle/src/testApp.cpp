
#include "testApp.h"

//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

// This demo was inspired by the particle vector example by Jeff Crouse in his "Code for Art" tutorials:
// https://github.com/jefftimesten/CodeForArt/tree/master/Chapter003-particles/003-vectors


/**
 * using the Addon "ofxImageSequence" created by James George in collaboration with FlightPhase
 * to download the Addon here: https://github.com/Flightphase/ofxImageSequence
 */



//--------------------------------------------------------------
void testApp::setup(){

    //ofBackground(255);
    ofEnableAlphaBlending();
    //ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetFrameRate(50);
    ofSetVerticalSync(true);

	//prefix is frame, file type is png, from frame 1 to 11, 2 digits in the number
	sequence.loadSequence("1/leaf", "png", 1, 241, 3);
	sequence.preloadAllFrames();	//this way there is no stutter when loading frames
	sequence.setFrameRate(16); //set sequence to 16 frames per second
	    
    
    background.loadImage("sky.jpg");
    
    speed=0.1;
    
}

//--------------------------------------------------------------
void testApp::update(){


    
    
    for(int i=0; i<pos.size(); i++)
    {
        time[i]+=speed;
        pos[i] += vel[i];
        
        float age = ofGetElapsedTimef() - born[i];
        color[i].a = ofMap(age, 0, 10, 255, 0);
        
        if(color[i].a < 10)
        {
            radius.erase(radius.begin() + i);
            pos.erase(pos.begin()+i);
            vel.erase(vel.begin()+i);
            color.erase(color.begin()+i);
            born.erase(born.begin()+i);
            time.erase(time.begin()+i);
        }
    }

    
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){


	ofSetColor(255);
    background.draw(0, 0);
    
    for(int i=0; i<pos.size(); i++){
       ofSetColor(color[i]);
       sequence.getFrameForTime(time[i])->draw(pos[i].x,pos[i].y ,radius[i],radius[i]);
    }
  
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    radius.push_back( ofRandom(5, 50) );
    pos.push_back( ofPoint(x, y) );
    vel.push_back( ofPoint(ofRandom(-2, 2), ofRandom(0, 5)) );
    color.push_back( ofColor(ofRandom(50,255)) );
    born.push_back( ofGetElapsedTimef() );
    time.push_back( ofRandom(240) );
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

