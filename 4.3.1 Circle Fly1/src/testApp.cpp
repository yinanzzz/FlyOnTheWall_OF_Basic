#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

//--------------------------------------------------------------
void testApp::setup(){
    
    
    
    ofSetVerticalSync(TRUE);
    
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(255);
    fly.loadImage("Fly1.png");
    speed=0.05;
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
    float radius = 100;  //circle radius
    
    time+=speed;   // time here decide the radian changing
    
    // "xorig" and "yorig" deside the position of circle center
    pos.x = xorig + radius * cos(time);
	pos.y = yorig + radius * -sin(time);
    
    // set up the angle
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    angle = atan2(dy, dx);
    prevPos=pos;

}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofPushMatrix();
    ofTranslate(pos.x,pos.y);
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