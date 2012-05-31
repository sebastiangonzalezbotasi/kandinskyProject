#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    
    fondo.loadImage("imgs/textura_0.jpg");
  
    iniciar();
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    

}

//--------------------------------------------------------------
void testApp::draw(){
   // ofBackground(236,231,202);

    fondo.draw(0,0);
    
    for ( int i=0; i<cantidad; i++ ) {
    
        circle[i].draw();
   
     }

    

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