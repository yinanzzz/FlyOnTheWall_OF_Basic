#include "testApp.h"
//made by Yinan Zhang for the class "FLy on the wall" with Parsons and Tongji University

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetVerticalSync(TRUE);
    
    ofEnableAlphaBlending();
    ofBackground(255);
    

    a1.loadImage("layer01.png");
    a2.setFromPixels(a1);
    
    b1.loadImage("layer02.png");
    b2.setFromPixels(b1);
  
    c1.loadImage("layer03.png");
    c2.setFromPixels(c1);
    
    d1.loadImage("layer04.png");
    d2.setFromPixels(d1);
    
    
    x1=x2=x3=x4=0;
    y1=-50;
    y2=20;
    y3=79;
    y4=50;
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    //set up different speed for layers
    //"fmod" is to set modulo for two floating numbers, so the x position will return to 0 when it reachs the border of the window

    x1+=0.2;
    x1=fmod(x1, ofGetWidth());      
    x2+=0.5;
    x2=fmod(x2, ofGetWidth());
    
    x3+=1;
    x3=fmod(x3, ofGetWidth());

    x4+=4;
    x4=fmod(x4, ofGetWidth());
    
    


}

//--------------------------------------------------------------
void testApp::draw(){


    a1.draw(x1, y1);
    a2.draw(x1-a1.getWidth(), y1);
    
    b1.draw(x2, y2);
    b2.draw(x2-b1.getWidth(), y2);
    
    c1.draw(x3, y3);
    c2.draw(x3-c1.getWidth(), y3);
    
    d1.draw(x4, y4);
    d2.draw(x4-d1.getWidth(), y4);
    
    
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