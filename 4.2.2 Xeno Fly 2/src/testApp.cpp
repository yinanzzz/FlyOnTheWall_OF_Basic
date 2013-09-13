#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University


//--------------------------------------------------------------
void testApp::setup(){
    
    
    //ofSetFrameRate(80);
    
    ofSetVerticalSync(TRUE);
    ofEnableAlphaBlending();
    ofBackground(255);
    
    fly.loadImage("Fly1.png");
    
    time=0.06; // here the time controls the travel speed toward mouse

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    //Xeno movement, the fly travels between it's current location and mouse position
    pos.x = (1-time) * pos.x + (time) * mouseX;
    pos.y = (1-time) * pos.y + (time) * mouseY;
    
    
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