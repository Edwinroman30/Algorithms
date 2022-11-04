#ifndef PILA_H
#define PILA_H

#include "Elemento.h"

class Pila
{
    public:
        Pila();
        void Agregar(Elemento* elemento);
        Elemento* Extraer();

    private:
        Elemento* _ultimo;
};
#endif
