#include "Elemento.h"

Elemento::Elemento(std::string titulo, std::string autor,std::string editora,
            std::string fecha, std::string categoria): _titulo(titulo),
        _autor(autor),
        _editora(editora),
        _fecha(fecha),
        _categoria(categoria),
        _siguiente(NULL)        
{
}
