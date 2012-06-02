//
//  ChromaticCircle.cpp
//  kandinskyProject
//
//  Created by Sebastian Gonzalez Botasi on 30/05/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "ChromaticCircle.h"

ChromaticCircle::ChromaticCircle(){
    

}

//----------------------------------

void ChromaticCircle::init( float _x , float _y ){

    x = _x;
    y = _y;
    
    rot = ofRandom(-60, 60);
    
    indice = int(ofRandom(9));
    
    
    radio = ofRandom( 20, 130 );
    pasosTotal = int(ofRandom( 0, 3 ));

    transparencia = ofRandom(120, 170);
    
    rellenos[0].set(123,84,125,transparencia);
    rellenos[1].set(238,192,71,transparencia);
    rellenos[2].set(113,177,185,transparencia);
    rellenos[3].set(184,26,2,transparencia);
    rellenos[4].set(164,173,129,transparencia);
    rellenos[5].set(52,128,165,transparencia);
    rellenos[6].set(234,183,139,transparencia);
    rellenos[7].set(32,26,34,transparencia);
    rellenos[8].set(254,243,243,transparencia);
    rellenos[9].set(208,114,81,transparencia);
    rellenos[10].set(248,192,74,transparencia);
    rellenos[11].set(219,171,71,transparencia);
    
    borde = ofRandom(2, 5);
}


//----------------------------------

void ChromaticCircle::setTranslate( bool _trans ){

    trans = _trans;
    
}

//----------------------------------

void ChromaticCircle::setStroke( bool _stroke ){

    stroke_ = _stroke;

}

//----------------------------------

void ChromaticCircle::draw(){
   
    ofPushMatrix();
    
    ofTranslate( x , y );
    
    circulo( 0, pasosTotal, radio, rot, indice, trans, stroke_);
    
    ofPopMatrix();

}

//----------------------------------

void ChromaticCircle::circulo( int _pasos, int _pasosTotal, float _radio, float _rot, int _id, bool _trans, bool _stroke ){
    
    ofPushStyle();
    if ( _stroke ) {

        ofSetColor( rellenos[  _id  ] );
        ofFill();
        ofCircle(0, 0, _radio);
        
        ofSetColor( 0 );
        ofSetLineWidth( borde );
        ofNoFill();
        ofCircle(0, 0, _radio);
    }
    else {
        ofSetColor( rellenos[  _id  ] );
        ofFill();
        ofCircle(0, 0, _radio);
    }
    
    ofPopStyle();
    
    if (_pasos < _pasosTotal ) {
        if ( _trans ) {
            ofTranslate (20, 0);
            ofRotate(ofDegToRad(_rot));
        }
        circulo ( _pasos+1, _pasosTotal, _radio/2, _rot, _id+1, _trans, _stroke);
    
    }
  

}





