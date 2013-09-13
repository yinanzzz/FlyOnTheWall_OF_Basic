#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetVerticalSync(TRUE);
    ofEnableAlphaBlending();
    ofBackground(255);

    ofSetRectMode(OF_RECTMODE_CENTER);    
    fly.loadImage("Fly1.png");
    
    for (int i = 0; i < NUM; i++){
        time[i]=ofRandom(0.0001, 0.0002);        
    }

}

//--------------------------------------------------------------
void testApp::update(){
    

    for (int i = 0; i < NUM; i++){
  
        time[i]+= ofRandom(-0.008,0.008);
  
    pos[i].x = (1-time[i]) * pos[i].x + (time[i]) * mouseX+ofRandom(-10,10);
    pos[i].y = (1-time[i]) * pos[i].y + (time[i]) * mouseY+ofRandom(-10,10);
    
    
    // set up the angle
    float dx = pos[i].x - prevPos[i].x;
    float dy = pos[i].y - prevPos[i].y;
    angle[i] = atan2(dy, dx);
    prevPos[i]=pos[i];
  }
}

//--------------------------------------------------------------
void testApp::draw(){

    
    for (int i = 0; i < NUM; i++){
    ofPushMatrix();
    ofTranslate(pos[i].x, pos[i].y);
    ofRotateZ(angle[i] * RAD_TO_DEG);  
    fly.draw( 0,0);         
    ofPopMatrix();
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