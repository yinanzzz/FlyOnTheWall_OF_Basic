#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

//this is a demo of movement shifting from point a to point b
//The Xeno principle was inspired by the Xeno(or Zeno)Paradox (Dichotomy paradox) by Greek philospher Zeno of Elea.
//This argument is called the Dichotomy because it involves repeatedly splitting a distance into two parts. 

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetVerticalSync(TRUE);
    ofEnableAlphaBlending();
    ofBackground(255);
    
    fly.loadImage("Fly1.png");
    
    time=0;   // time value decides the percentage of movement
    speed=0;  // moving speed
    accel=0.00007; 
    
    //set up the positions of oint a and b
    posa.set(100,380);
    posb.set(800,380);
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    time+=speed;
    speed+=accel;
    
    // just between 0 and 1 (0% and 100%)
    if (time > 1 || time<0) {
		speed = -speed;   	}	
    
    
    //Xeno movement, the fly travels between point a and point b
    pos.x = (1-time) * posa.x + (time) * posb.x;
    pos.y = (1-time) * posa.y + (time) * posb.y;
    
    
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