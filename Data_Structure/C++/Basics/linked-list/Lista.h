#pragma once
#include "Nodo.h"

class Lista
{
private:
	Nodo* _primer;
	Nodo* _ultimo;
public:
	Lista();
	~Lista();
	void Agregar(Nodo* nodo);
	Nodo* GetPrimer();
};

