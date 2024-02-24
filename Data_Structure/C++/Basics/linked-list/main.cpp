#include <iostream>
#include "Lista.h"

int main()
{
    Nodo* uno = new Nodo("Uno");
    Nodo* dos = new Nodo("Dos");
    Nodo* tres = new Nodo("Tres");
    
    Lista* lista = new Lista();
    lista->Agregar(uno);
    lista->Agregar(dos);
    lista->Agregar(tres);

    Nodo* i = lista->GetPrimer();

    while (i != nullptr)
    {
        std::cout << i->GetDescripcion() << std::endl;
        i = i->GetSiguiente();
    }
    delete lista;
}