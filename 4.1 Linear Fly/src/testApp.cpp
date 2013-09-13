#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

//--------------------------------------------------------------
void testApp::setup(){
    
    
    
    ofSetVerticalSync(TRUE);
    
    ofEnableAlphaBlending();
    ofBackground(255);
    
    fly.loadImage("Fly1.png");
    
    
    pos.set(0,ofGetHeight()/2);
    velocity.set(0,0);   // set up the speed of x and y location

    
    accel.x=0.01;  // the acceleration
}

//--------------------------------------------------------------
void testApp::update(){
    
    // time=time+velocity // velocity=velocity+acceleration
    velocity.x+=accel.x;
    pos.x+=velocity.x;
    
    
    //set up the noise of y position
    time+=velocity.x*0.004;
    pos.y= 250+ ofNoise(time)*150;
    
    
    
    if (pos.x>ofGetWidth()) {
        pos.x=0;
    } 
    
    // set up the angle
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    angle = atan2(dy, dx);
    prevPos=pos;

}

//--------------------------------------------------------------
void testApp::draw(){


    ofSetRectMode(OF_RECTMODE_CENTER);

    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(angle * RAD_TO_DEG);      
    fly.draw( 0,0);         
    ofPopMatrix();

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}