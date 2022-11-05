#include "Agenda.h"
#include <fstream>
#include <string>
#include <iostream>

#define NOMBRE_ARCHIVO "contactos.txt"

Agenda::Agenda(): _primer(NULL) , _ultimo(NULL)
{
}

void Agenda::Agregar(Contacto* contacto)
{
    //Implementar este método 
    /*
        Este método tiene como objetivo agregar un contacto a la agenda.
    */

   contacto->SetSiguiente(NULL);

    if(_primer == NULL){
        _primer = contacto;
        _ultimo = contacto;
    }else{
        _ultimo->SetSiguiente(contacto);
        _ultimo = contacto;
    }
}

bool Agenda::Eliminar(int indice)
{
    //Implementar este método 
    /*
        Este método tiene como objetivo eliminar un contacto de la agenda.

        Este método recibe parámetro el índice del contacto a eliminar (iniciando en cero).
    */

   int internalIndex = 0;
   Contacto* element = _primer;
   
   while (element != NULL)
   {
      element = element->GetSiguiente();
      internalIndex++;
   }
   
    if(indice > internalIndex) //Posible error
        return false;

    /* -> */

    internalIndex = 0; //Reset to cero
    Contacto* previous = NULL;
    Contacto* current = _primer;

    while (current != NULL)
    {
        if(internalIndex == indice){
            break;
        }else{
            previous = current;
            current = current->GetSiguiente();
            internalIndex++;
        }
    }
    
    /* -> */

    if(current == NULL) { return false; }

    if(previous == NULL){ // The First case it is when it is the first element. The first's previous element always is null.
        
        if(current->GetSiguiente() == NULL){ //It is the first element and has not others next to it.
            _primer = NULL;
            delete current;
        }else{
            _primer = _primer->GetSiguiente();
            delete current;
        }

    }else{
        previous->SetSiguiente(current->GetSiguiente());
        delete current;
    }    

    return true;

}

bool Agenda::Modificar(int indice, std::string nombre, std::string telefono)
{
    //Implementar este método 
    /*
        Este método tiene como objetivo modificar un contacto de la agenda.

        Este método recibe parámetros el índice del contacto a modificar (iniciando en cero) , el nuevo nombre y nuevo teléfono de dicho contacto.
    */
    
    /* -> First Phase */

    int internalIndex = 0;
    Contacto* contact = _primer;
    
    while (contact != NULL)
    {
        contact = contact->GetSiguiente();
        internalIndex++;
    }
    
    if(indice > internalIndex)
        return false;

    /* -> Second Phase */

    internalIndex = 0; //Reset to cero.
    Contacto* previous = NULL;
    Contacto* current = _primer;
    
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
    
    /* Third Phase */
    if(current == NULL)
        return false;

    current->SetNombre(nombre);
    current->SetTelefono(telefono);

    return true;
}


void Agenda::Cargar()
{
    //Terminar la implementación de este método 
    /*
        Este método es el que carga desde un archivo de texto todos los contactos almacenados en el disco duro.
    */

    std::ifstream lector(NOMBRE_ARCHIVO);
	std::string linea;
    Contacto* contact = NULL;

    const char DELIMITER = ',';
    std::string tempString = "";
    std::string tempName = "";

    while(!lector.eof()) //Mientras no sea el final del archivo....
    {
        std::getline(lector, linea);
        tempString = "";

        if(linea == "")
            return;

        //This bucle works as a split() function.
        for(int i = 0; i < (int)linea.size(); i++){
            if(linea[i] != DELIMITER){
                tempString += linea[i];
            }else{
                //It mean delimiter found!
                tempName = tempString;           
                tempString = "";
            }
        }

        this->Agregar(new Contacto(tempName, tempString));
        //std::cout << tempName << " " << tempString << std::endl; DEBUGGING PURPORSE
    }

    lector.close();
}

void Agenda::Guardar()
{
    //Terminar la implementación de este método 
    /*
        Este método es el que guarda en un archivo de texto (en el disco duro) todos los contactos.
    */
    std::ofstream escritor(NOMBRE_ARCHIVO);

    Contacto* contacto = _primer;
    while(contacto != NULL)
    {
        escritor << contacto->GetNombre() << "," << contacto->GetTelefono() << std::endl;
        contacto = contacto->GetSiguiente();
    }

    escritor.close();
}
