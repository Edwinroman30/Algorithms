#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>

class Elemento
{
    public:
        Elemento(std::string titulo, std::string autor,std::string editora,
            std::string fecha, std::string categoria);
        void SetTitulo(std::string titulo) { _titulo = titulo; }
        std::string GetTitulo(){ return _titulo; }
        void SetAutor(std::string autor) { _autor = autor; }
        std::string GetAutor(){ return _autor; }
        void SetEditora(std::string editora) { _editora = editora; }
        std::string GetEditora(){ return _editora; }
        void SetFecha(std::string fecha) { _fecha = fecha; }
        std::string GetFecha(){ return _fecha; }
        void SetCategoria(std::string categoria) { _categoria = categoria; }
        std::string GetCategoria(){ return _categoria; }
        void SetSiguiente(Elemento* siguiente) { _siguiente = siguiente; }
        Elemento* GetSiguiente() { return _siguiente; }

    private:
        std::string _titulo;
        std::string _autor;
        std::string _editora;
        std::string _fecha;
        std::string _categoria;
        Elemento* _siguiente;

};
#endif
