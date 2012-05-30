//
//  Urn.cpp
//  kandinskyProject
//
//  Created by Sebastian Gonzalez Botasi on 30/05/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Urn.h"


Urn::Urn(){

}

//--------------------------

void Urn::init(int _cant){

    cantidad = _cant;
    reset();


}

//--------------------------


void Urn::increase( int _valor ){

    cont = (cont+ _valor) % cantidad;
    
}

//--------------------------


void Urn::reset(){
  
    for(int i=0; i < cantidad; i++){
        urna [i] = false;
    }
    sacados = 0;
    cont = 0;

}

//--------------------------


int Urn::get(){

    resultado = -1;
    if( ! empty() ){
        
        
        tirada = int( ofRandom( cantidad ));
        increase( tirada );    
        
        if ( !urna[ cont ] ){
            
            urna[ cont ] = true;
            sacados ++;
            resultado = cont;
            
        }
        else{
            bool encontro = false;
            
            for(int i=0; i<cantidad && !encontro ; i++){
                
                increase( 1 );
                if( !urna[cont] ){
                    urna[cont] = true;
                    sacados ++;
                    resultado = cont;
                    encontro = true;
                }
            }
        }
    }
    return resultado;
    
}

//--------------------------


bool Urn::empty(){
    return sacados>=cantidad;

}