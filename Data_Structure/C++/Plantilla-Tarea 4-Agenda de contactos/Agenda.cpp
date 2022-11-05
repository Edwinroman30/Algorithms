#include "Agenda.h"
#include <fstream>
#include <string>

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
}

bool Agenda::Eliminar(int indice)
{
    //Implementar este método 
    /*
        Este método tiene como objetivo eliminar un contacto de la agenda.

        Este método recibe parámetro el índice del contacto a eliminar (iniciando en cero).
    */
    return false;
}

bool Agenda::Modificar(int indice, std::string nombre, std::string telefono)
{
    //Implementar este método 
    /*
        Este método tiene como objetivo modificar un contacto de la agenda.

        Este método recibe parámetros el índice del contacto a eliminar (iniciando en cero) , el nuevo nombre y nuevo teléfono de dicho contacto.
    */
    return false;
}

void Agenda::Cargar()
{
    //Terminar la implementación de este método 
    /*
        Este método es el que carga desde un archivo de texto todos los contactos almacenados en el disco duro.
    */
    std::ifstream lector(NOMBRE_ARCHIVO);
	std::string linea;
    lector.close();
}

void Agenda::Guardar()
{
    //Terminar la implementación de este método 
    /*
        Este método es el que guarda en un archivo de texto (en el disco duro) todos los contactos.
    */
    std::ofstream escritor(NOMBRE_ARCHIVO);
    escritor.close();
}
