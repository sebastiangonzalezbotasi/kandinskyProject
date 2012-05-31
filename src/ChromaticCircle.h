//
//  ChromaticCircle.h
//  kandinskyProject
//
//  Created by Sebastian Gonzalez Botasi on 30/05/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "ofMain.h"

class ChromaticCircle{

    public:
    
    ChromaticCircle();
    void init( float _x , float _y );
    void setColor();
    void setTranslate( bool _trans );
    void setStroke( bool _stroke );
    void draw();
    
    void circulo( int _pasos, int _pasosTotal, float _radio, float _rot, int _id, bool _trans, bool _stroke );

    float  x, y;
    float  radio;
    float  rot;
    
    int     indice;
    int     pasosTotal;
    float   transparencia;
    
    bool  trans, stroke_;
    
    ofColor rellenos[ 12 ];
    

};