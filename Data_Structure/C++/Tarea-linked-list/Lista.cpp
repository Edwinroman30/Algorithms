#include "Lista.h"
#include <iostream>


Lista::Lista(): _primer(NULL) , _ultimo(NULL)
{

}


bool Lista::Eliminar(int indice)
{

	int inx = 0;

	Elemento* elem = _primer;

	while (elem != NULL)
	{			
		elem = elem->GetSiguiente();
		inx++;
	}

	if(!(inx-1 >= indice))
		return false;

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
	

	if(current == NULL){
		return false;
	}else{
		
		if(previous != NULL){ 
			previous->SetSiguiente(current->GetSiguiente());
			delete current;
		}
		else{

			if(_primer->GetSiguiente() != NULL){ 
				_primer = _primer->GetSiguiente(); //Si estamos eliminando el primer elemento pero este tiene otro elementos al que apuntar.
				delete current;
			}else{
				_primer = NULL; //Cuando queda solo ese primer elemento y nada a que apuntar.
				delete current;
			}

		}
		
		return true;
	}
	
	return false;

	/*
	IMPLEMENTE ESTE METODO
	Dado un indice entero elimine el objeto en esa posición.  Ejemplo si el parámetro indice es igual a 0 se eliminará el primer elemento.

	Esta función retorna un booleano,  retorno verdadero si el índice está contenido en la lista.

	Ejemplo, si la lista tiene 4 elementos y se pide eliminar el índice 9 este método retornará falso porque ese índice no está contenido en la lista.
	*/
}

void Lista::Agregar(Elemento* elemento)
{

	if(_primer == NULL){
		
		_primer = elemento;
		_ultimo = elemento;
		
	}else{

		_ultimo->SetSiguiente(elemento);
		_ultimo = elemento;
	}

	/*IMPLEMENTE ESTE METODO
		Dado un objeto de tipo puntero a Elemento agréguelo a la lista.
		Tenga pendiente que el atributo _primer guarda un puntero al primer elemento de la lista y que _ultimo es un puntero al al último elemento de la lista
	*/
}