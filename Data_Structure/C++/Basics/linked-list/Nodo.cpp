#include "Nodo.h"
#include <iostream>

Nodo::Nodo(std::string descripcion): _descripcion(descripcion), _siguiente(nullptr)
{
}

void Nodo::SetSiguiente(Nodo* siguiente)
{
	_siguiente = siguiente;
}

std::string Nodo::GetDescripcion()
{
	return _descripcion;
}

Nodo::~Nodo()
{
	std::cout << "Destruyendo nodo " << _descripcion << std::endl;
}

Nodo* Nodo::GetSiguiente()
{
	return _siguiente;
}