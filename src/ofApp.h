#pragma once

#include "ofMain.h"
#include "ofxThreadedImageLoader.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void updateFileList();
        ofxThreadedImageLoader loader;
        vector<ofImage> images;
        vector<string> lines;
        vector<string> oldLines;
        int total;
        int w, h;
        string textFile, path;
    
        vector<ofPlanePrimitive> planes;
        ofEasyCam cam;
        ofFbo fbo;
        ofShader shader;
};