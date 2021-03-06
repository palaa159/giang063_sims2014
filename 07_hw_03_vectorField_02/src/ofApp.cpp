/*--------------------------------------------------------------
 Based on Charlie Whitney's Flow Field.
 Added interaction with camera.
 --------------------------------------------------------------*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
//    ofSetFullscreen(true);
    ofSetWindowShape(640, 480);
    
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    for(int i = 0; i < NUM_PARTICLES; i++){
        Particle newParticle;
        newParticle.setup(ofRandomWidth(), ofRandomHeight());
        myParticles.push_back(newParticle);
    }
    
    cam.initGrabber(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i = 0; i < myParticles.size(); i++ ){
        ofVec2f forceAtPos = myField.getForceAtPosition(myParticles[i].pos) * 0.005;
        myParticles[i].addForce( forceAtPos );
        myParticles[i].update();
    }
    
    myField.update();
//    ofHideCursor();
    
    cam.update();
    
    //Drawing each 4 pixels. Makes it run faster.
    for(int y = 0; y < cam.getHeight(); y += myField.resolution){
        
        int spacing = myField.resolution;
        
        for(int x = 0; x < cam.getWidth(); x += myField.resolution){
            
            //This is different from getting the pixels of a static image!
            //You need to add .getPixelsRef()
            ofColor myColor = cam.getPixelsRef().getColor(x, y);
            float brightness = myColor.getBrightness();

//            cout << brightness << endl;
            ofVec2f force = ofVec2f(1, ofMap(brightness, 0, 255, -1, 1));
            myField.addForceAtPosition(force, ofVec2f(x, y));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1, color2;
    color1.set(40, 50, 150);
    color2.set(40, 50, 115);
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    
        ofSetColor(255, 50);
        myField.draw();
    
//    for( int i = 0; i < myParticles.size(); i++ ){
//        myParticles[i].draw();
//    }
    
    ofSetColor(255, 50);
    cam.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    ofVec2f dir = ofVec2f(x, 0) - ofVec2f(ofGetPreviousMouseX(), 0);
//    myField.addDirection(dir);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
