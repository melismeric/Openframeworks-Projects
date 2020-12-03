#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofBackground(255,255,255);
    gui.setup();
    gui.add(size.setup("size", 0, 0, 8)); //brush size
    gui.add(color.setup("color", ofColor(255,255,255,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(background.setup("background", ofVec3f(0,0,0),ofVec3f(0,0,0),ofVec3f(255,255,255)));
    gui.add(btnClear.setup("clear"));
    
    fbo.allocate(width, height);
    fbo.begin();
    ofClear(0,255);
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(background->x, background->y, background->z);
    
    if(btnClear){
        fbo.begin();
        ofClear(0,255);
        fbo.end();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    fbo.draw(0,0);
    ofNoFill();
    ofDrawRectangle(0,0,width, height);
   

    for (auto line : lines) {
        ofSetLineWidth(size);
        ofSetColor(color);
        ofDrawLine(line.a, line.b);
    }
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    fbo.begin();
    for (auto point : drawnPoints){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < 30){
            Line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines.push_back(lineTemp);
        }
        
    }
    drawnPoints.push_back(ofPoint(x,y));

    fbo.end();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
