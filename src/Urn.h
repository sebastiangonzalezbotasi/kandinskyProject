//
//  Urn.h
//  kandinskyProject
//
//  Created by Sebastian Gonzalez Botasi on 30/05/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#include "ofMain.h"

class Urn{

    public:

    Urn();
    
    void init( int _cant );
    void increase( int _valor );
    void reset();
    
    int  get();
    bool empty();
    

    int  cantidad;
    
    bool urna[ 12 ];
  
    int  sacados;
    int  cont;
    
    int resultado;
    int tirada;
    
};