#include "Vellonera.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Vellonera::Vellonera(): _repetir(false), _primera(NULL) , _ultima(NULL),  _actual(NULL)
{
}

void Vellonera::Agregar(Cancion* cancion)
{
    /*IMPLEMENTAR ESTE METODO PARA AGREGAR NUEVA CANCIÓN  LA VELLONERA*/

    if(_primera == NULL ){
        _primera=cancion;
        _ultima = cancion;
        _actual = cancion;
    }else{
        _ultima->SetSiguiente(cancion);
        cancion->SetAnterior(_ultima);
        _ultima = cancion;
        _ultima->SetSiguiente(NULL);
    }

    this->OrdenarCanciones();
}

void Vellonera::OrdenarCanciones()
{    
    /*IMPLEMENTAR ESTE METODO PARA ORDERNAR LAS CANCIONES DE MENOR A MAYOR (SEGUN SU DURACION)*/
    Cancion* temp = _primera;
    tiempo t1;
    tiempo t2;
    /* 
    while (temp != NULL)
    {
        if(temp->GetSiguiente() == NULL)
            break;

        t1 = temp->GetDuracion();
        t2 = temp->GetSiguiente()->GetDuracion();

        if(t1.GetTiempoTotal() > t2.GetTiempoTotal()){
            temp->SetAnterior(temp->GetSiguiente()); 
            temp->GetSiguiente()->SetSiguiente(temp);
        }else{
            temp = temp->GetSiguiente();
        }
      
    }
 */
}

void Vellonera::CancionSiguiente()
{
    /*IMPLEMENTAR ESTE MÉTODO PARA AVANZAR A LA SIGUIENTE CANCION (Ver puntero _actual)*/
    Cancion* temp = _actual->GetSiguiente();
    if(temp == NULL && _repetir){
        _actual = _primera;
        return;
    }

    /* It cant cause issues!!! */
    if(temp == NULL &&  !_repetir){
        std::cout << "No hay cancion proxima!!!" << std::endl;
        return;
    }

    _actual = temp;
}

void Vellonera::CancionAnterior()
{
    /*IMPLEMENTAR ESTE MÉTODO PARA REGRESAR A LA CANCION ANTERIOR (Ver puntero _actual)*/
    _actual = _actual->GetAnterior();
}

bool Vellonera::Eliminar(int indice)
{
    /*ELIMINAR UNA CANCION RETORNA FALSO SI EL INDICE NO ESTABA EN LA LISTA*/
    /*EL INIDICE INICIA EN CERO*/

    int listLength = 0;
    Cancion* tempSong = _primera;

    while (tempSong != NULL)
    {
        tempSong = tempSong->GetSiguiente();
        listLength++;
    };
    
    if(indice > listLength)
        return false;
    
     /* -> */

    int internalIndex = 0; //Reset to cero
    Cancion* previous = NULL;
    Cancion* current = _primera;

    while (current != NULL)
    {
        if(indice == internalIndex){
            break;
        }else{
            previous = current;
            current = current->GetSiguiente();
            internalIndex++;
        }

    }
    
    /* -> */

    if(current == NULL) { return false; }

    if(previous == NULL){
        
        if(current->GetSiguiente() == NULL){ 
            _primera = NULL;
            delete current;
        }else{
            _primera = _primera->GetSiguiente();
            delete current;
        }

    }else{
        previous->SetSiguiente(current->GetSiguiente());
        delete current;
    }    

    return true;
}

