#include "Lista.h"
#include <iostream>


Lista::Lista(): _primer(NULL) , _ultimo(NULL)
{

}

void Lista::Agregar(Elemento* elemento)
{

	/*IMPLEMENTE ESTE METODO
		Dado un objeto de tipo puntero a Elemento agréguelo a la lista.
		Tenga pendiente que el atributo _primer guarda un puntero al primer elemento de la lista y que _ultimo es un puntero al al último elemento de la lista
	*/

	if(_primer == NULL){
		
		_primer = elemento;
		_ultimo = elemento;
		
	}else{

		_ultimo->SetSiguiente(elemento);
		_ultimo = elemento;
	}

	
}



bool Lista::Eliminar(int indice)
{
	/*
	IMPLEMENTE ESTE METODO
	Dado un indice entero elimine el objeto en esa posición.  Ejemplo si el parámetro indice es igual a 0 se eliminará el primer elemento.

	Esta función retorna un booleano,  retorno verdadero si el índice está contenido en la lista.

	Ejemplo, si la lista tiene 4 elementos y se pide eliminar el índice 9 este método retornará falso porque ese índice no está contenido en la lista.
	*/

	int inx = 0;

	Elemento* elem = _primer;

	// This while is to know how many element there are in the list.
	while (elem != NULL)
	{			
		elem = elem->GetSiguiente();
		inx++;
	}


	if(!(inx-1 >= indice))
		return false;
	/* 
		These two condition mean the same if the given index is higher than our 
		calculated index we get out of range. (The under condition look more simple).
	 */
	if(indice > inx)
		return false;



	//Este bloque busca el elemento en espefico dado el indice.
	inx = 0;
	
	Elemento* previous = NULL;
	Elemento* current = _primer;

	while (current != NULL)
	{			
		if(inx == indice){
			break;
		}else{

			previous = current;
			current = current->GetSiguiente();
		}

		inx++;
	}
	

	/* Refactor */

	if(current == NULL)
		return false;
	

	if(previous == NULL){ 
		
		if(_primer->GetSiguiente() == NULL){ 
			_primer = NULL; //Cuando queda solo ese primer elemento y nada a que apuntar.
			delete current;
		}else{
			_primer = _primer->GetSiguiente(); //Si estamos eliminando el primer elemento pero este tiene otro elementos al que apuntar.
			delete current;
		}
	}
	else{
		previous->SetSiguiente(current->GetSiguiente());
		delete current;
	}
		
	return true;

}