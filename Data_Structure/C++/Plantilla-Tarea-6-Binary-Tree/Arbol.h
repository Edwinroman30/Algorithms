/*
 * Arbol.h
 *
 *  Created on: Mar 9, 2019
 *      Author: raydelto
 */

#ifndef ARBOL_H_
#define ARBOL_H_
#include "Nodo.h"

class Arbol
{
private:
	Nodo* _raiz;

	//Esta clase tiene una lista enlazada de todos los nodos. Esta lista es lineal y no almacena en forma jerárquica
	Nodo* _primerNodo; //Primer nodo de la lista enlazada de nodos
	Nodo* _ultimoNodo; //Ultimo nodo de la lista enlazada de nodos

	//Este método viene lleno en la plantilla. Procesa los nodos del arbol. Se espera que el estudiante en su implementación del método Recorrer llame a este método por cada nodo recorrido
	void Procesar(Nodo* nodo);
public:
	//Este método limpia la lista de nodos generados antes de recorrer el árbol
	void IniciarProceso();
	void Recorrer();
	void Recorrer(Nodo* nodo);
	Arbol(Nodo* raiz);
	Arbol();
	virtual ~Arbol();
	Nodo* GetPrimerNodo() { return _primerNodo; }
	void SetRaiz(Nodo* raiz) { _raiz = raiz; }
	Nodo* GetRaiz() { return _raiz; }

	//Retorna un nodo dado un indice (iniciado en cero). Si el indice no existe el método retorna NULL
	Nodo* GetNodo(int indice);
};

#endif /* ARBOL_H_ */
