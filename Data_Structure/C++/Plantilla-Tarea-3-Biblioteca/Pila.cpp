#include "Pila.h"

Pila::Pila(): _ultimo(NULL)
{
}


void Pila::Agregar(Elemento* elementum)
{
    
    if(_ultimo == NULL){
        _ultimo = elementum;
        _ultimo->SetSiguiente(NULL);
        return;
    }

    
    elementum->SetSiguiente(_ultimo);
    
    _ultimo = elementum;

}

Elemento* Pila::Extraer()
{
    
    if(_ultimo == NULL){
        return NULL;
    }else{

        Elemento* helperElement = _ultimo;
        _ultimo = _ultimo->GetSiguiente();

        return helperElement;
    }
}