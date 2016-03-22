#include "ofApp.h"
#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup(){
    w = 1024;
    h = 768;
    
    ofSetWindowShape(w, h);
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    
    shader.load("shaders/repos");
    textFile = "out.txt";
    
    total = 10;
    
    
    path = "images";
    ofDirectory dir(path);
    dir.listDir();
    cout<<ofToString(dir.size())<<endl;
    
    for(int i = dir.size()-1; i>=dir.size()-total; i--){
        string f = dir.getPath(i);
        cout<<f<<endl;
        lines.push_back(f);
        oldLines.push_back(f);
        
        ofImage img;
        img.load(f);
        images.push_back(img);
    }
    
    cam.setNearClip(1);
    cam.setFarClip(10000000);
    cam.setFov(90);
    
    ofSetBackgroundColor(255);
    
    fbo.allocate(w, h, GL_RGB);
    
    for(int i = 0; i<images.size(); i++){
        ofPlanePrimitive plane;
        plane.set(images[i].getWidth(), images[i].getHeight());
        plane.mapTexCoords(0, 0, images[i].getWidth(), images[i].getHeight());
        planes.push_back(plane);
    }
}
//--------------------------------------------------------------
void ofApp::updateFileList(){
//    ofBuffer buffer = ofBufferFromFile(tf);
    lines.clear();
    ofDirectory dir(path);
    dir.listDir();
    
    for(int i = dir.size()-1; i>=dir.size()-total; i--){
        string f = dir.getPath(i);
        lines.push_back(f);
    }

    if(lines != oldLines){
        images.clear();
        for(int i = dir.size()-1; i>=dir.size()-total; i--){
            string f = dir.getPath(i);
            ofImage img;
            img.load(f);
            planes[i].mapTexCoords(0, 0, images[i].getWidth(), images[i].getHeight());
            images.push_back(img);
        }
        oldLines = lines;
    }
    
    
    
}
//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum() % 90 == 0){
        updateFileList();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    fbo.begin();
    ofClear(255);
    shader.begin();
    glEnable(GL_DEPTH_TEST);
    cam.begin();
    for(int i = 0; i< (int)images.size(); i++){
        shader.setUniformTexture("tex0", images[i].getTexture(), 0);
        int x = (i%8);
		int y = (i/8);
        if(images[i].isAllocated()){
            ofPushMatrix();
            ofTranslate(0,0, 500*i);
//            images[i].bind();
                planes[i].draw();
//            images[i].unbind();
            ofPopMatrix();
//            images[i].draw(-images[i].getWidth()/2,-images[i].getHeight()/2, 500*i);
        }
    }
    cam.end();
    glDisable(GL_DEPTH_TEST);
    shader.end();
    fbo.end();
    
    fbo.draw(0,0);
}
//--------------------------------------------------------------
void ofApp::exit(){
	loader.stopThread();
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
