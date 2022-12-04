/*
 * Arbol.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: raydelto
 */

#include "Arbol.h"
#include <iostream>

Arbol::Arbol(): _raiz(NULL)
{
}

//Este método viene lleno en la plantilla. Limpia la lista de nodos generados antes de recorrer el árbol
void Arbol::IniciarProceso()
{
	_ultimoNodo = NULL;
	_primerNodo = NULL;
}

//Este método viene lleno en la plantilla. Procesa los nodos del arbol. Se espera que el estudiante en su implementación del método Recorrer llame a este método por cada nodo recorrido
void Arbol::Procesar(Nodo* nodo)
{
	if(_primerNodo == NULL) //Si la lista está vacía
	{
		_primerNodo = nodo;
		_ultimoNodo = nodo;
	}else
	{
		_ultimoNodo->SetSiguiente(nodo);
		_ultimoNodo = nodo;
	}
}

void Arbol::Recorrer()
{
	Recorrer(_raiz);
}

// Implementar este método
void Arbol::Recorrer(Nodo* nodo)
{
	//La primera línea de código de este método debe llamar al método procesar
	Procesar(nodo);

	if(nodo == NULL)
		return;

	//Escribir aqui el código de su implementación de recorrer el árbol
	std::cout << nodo->GetNombre() << std::endl;

		Nodo* iteratorVariable =  nodo->GetPrimerHijo();
		while (iteratorVariable != NULL)
		{
			Recorrer(iteratorVariable);
			iteratorVariable = iteratorVariable->GetSiguienteHijo();
		}
	
}

//Retorna un nodo dado un indice (iniciado en cero). Si el indice no existe el método retorna NULL
Nodo* Arbol::GetNodo(int indice)
{
	Nodo* nodo = _primerNodo;
	int i = 0;
	while(nodo != NULL)
	{
		if(i == indice)
		{
			return nodo;
		}
		nodo = nodo->GetSiguiente();
		i++;
	}
	return NULL;
}

Arbol::Arbol(Nodo* raiz): _raiz(raiz), _primerNodo(NULL), _ultimoNodo(NULL)
{
}

Arbol::~Arbol() 
{
}

//Este método corresponde a la clase NODO
//Implementar este método
void Nodo::AgregarHijo(Nodo* hijo)
{
	//Este método le agrega un hijo a este nodo del arbol
	if(_primerHijo == NULL) //Si la lista está vacía
	{
		_primerHijo = hijo;
		_ultimoHijo = _primerHijo;
	}else
	{
		_ultimoHijo->SetSiguiente(hijo);
		_ultimoHijo = hijo;
	}

}