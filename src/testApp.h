#pragma once

#include "ofMain.h"
#include "ChromaticCircle.h"
#include "ofxPSBlend.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void iniciar();
    
    
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage fondo,final;
    ofFbo textura1;
    
    ofPixels pixel;
    
    ofxPSBlend filtro;
    int filterMode;

    
    
    
    bool valor;
    
    ChromaticCircle *circle;
    int cantidad;
    int snapCounter;
    
    
		
};
