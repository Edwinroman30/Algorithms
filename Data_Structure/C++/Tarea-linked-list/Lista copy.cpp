#include "Lista.h"
#include <iostream>

Lista::Lista(): _primer(NULL) , _ultimo(NULL), _lenght(0)
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

	_lenght++;
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
		
	if(_lenght-1 >= indice){

		Elemento* elem = _primer;

		while (elem != NULL)
		{
			
			Elemento* tmp = elem;
			elem = elem->GetSiguiente();

			if(inx == indice){
				//delete elem;
				std::cout << "deleted - true" << std::endl;
				return true;
			}

			inx++;
		}

	}

	std::cout << "deleted - false" << std::endl;
    return false;
}
