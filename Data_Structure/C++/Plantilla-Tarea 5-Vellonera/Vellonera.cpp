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

    if(_primera == NULL)
        return;

    /*IMPLEMENTAR ESTE METODO PARA ORDERNAR LAS CANCIONES DE MENOR A MAYOR (SEGUN SU DURACION)*/
    Cancion* initial = _primera;
    Cancion* temp;

    tiempo t1;
    tiempo t2;

    while (initial != NULL){

        temp = initial->GetSiguiente();

        while (temp != NULL){

            t1 = initial->GetDuracion(); //30
            t2 = temp->GetDuracion();    //20

            if(t1.GetTiempoTotal() >= t2.GetTiempoTotal()){
               
                Cancion dinamicSong = *initial;
                t1 = dinamicSong.GetDuracion();

               
                initial->SetArtista(temp->GetArtista());
                initial->SetTitulo(temp->GetTitulo());
                initial->SetDuracion(t2);

                temp->SetArtista(dinamicSong.GetArtista());
                temp->SetTitulo(dinamicSong.GetTitulo());
                temp->SetDuracion(t1);
           
            }

            temp = temp->GetSiguiente();
        }
        
        initial = initial->GetSiguiente();
    }
     
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
            _primera->SetAnterior(NULL);
            delete current;
        }

    }else{
        previous->SetSiguiente(current->GetSiguiente());
        delete current;
    }    

    return true;
}

