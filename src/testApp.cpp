#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    snapCounter = 0;
	
    
    fondo.loadImage("imgs/textura_0.jpg");
    
    textura1.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); 
    
    iniciar();
    
    
    filtro.setup(ofGetWidth(),ofGetHeight());
    filterMode = 1;

    
}

//--------------------------------------------------------------
void testApp::update(){
   
    
    
    filtro.begin();
    
    final.draw(0,0);
    
    filtro.end();

    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    filtro.draw(fondo.getTextureReference(), filterMode);


}

//--------------------------------------------------------------
void testApp::iniciar(){
    
    
    
    valor = false;
    cantidad = int( ofRandom( 5, 11 ) );
    
    circle = new ChromaticCircle[ cantidad ];
    
    for ( int i=0; i<cantidad; i++ ) {
        
        circle[i].init(ofRandomWidth(), ofRandomHeight());
        
        circle[i].setTranslate( valor );
        circle[i].setStroke( valor );
        
        valor = !valor;
        
    }
    
    //-----------------------
    
    textura1.begin();
    
    ofClear(0, 0);
    
    for ( int i=0; i<cantidad; i++ ) {
        
        circle[i].draw();
        
    }
    
    textura1.end();
    
    //--------------------------

    
    textura1.readToPixels( pixel );
	
    for(int y = 0; y < pixel.getHeight(); y++){
		for(int x = 0; x < pixel.getWidth(); x++){
			
			ofColor color = pixel.getColor(x+int(ofRandom(-2,2)), y+int(ofRandom(-2,2)));
            pixel.setColor(x, y, color);
		}
	}
    
    final.setFromPixels(pixel);
    
    
    
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' '){
        string fileName = "kandinsky_"+ofToString(10000+snapCounter)+".png";
        ofSaveScreen(fileName);
        snapCounter++;
        
 	}
    
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
    
    iniciar();
    
    
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