#include "Pila.h"
#include <iostream>
#include <string>

using namespace std;
Pila* pila = new Pila();

void Listar()
{
    cout << endl;
    Pila* temporal = new Pila();
    Elemento *e = pila->Extraer();
    int i = 0;
    while(e != NULL)
    {
        temporal->Agregar(e);
        i++;
        cout << i << "- " << e->GetTitulo() << " (" << e->GetAutor() << ")" << endl;
        e = pila->Extraer();
    }
    if(i == 0)
    {
        cout << "La pila está vacía" << endl;
    }else
    {
        e = temporal->Extraer();
        while(e != NULL)
        {
            pila->Agregar(e);
            e = temporal->Extraer();
        }
    }
    cout << endl;
}

void Buscar()
{
    cout << endl;
    std::string categoria;
    cout << "Seleccione la categoría de que desea buscar: ";
    getline(cin, categoria);
    Pila* temporal = new Pila();
    Elemento *e = pila->Extraer();
    int i = 0;
    while(e != NULL)
    {
        i++;
        cout << "Se ha removido el libro: " << e->GetTitulo();
        temporal->Agregar(e);
        
        if(e->GetCategoria() == categoria)
        {
            cout << ". Cumple con el criterio de búsqueda." << endl;
            break;
        }else
        {
            cout << ", no cumple con el criterio de búsqueda." << endl;
        }
        e = pila->Extraer();
    }
    if(i == 0)
    {
        cout << "La pila está vacía" << endl;
    }else
    {
        e = temporal->Extraer();
        while(e != NULL)
        {
            pila->Agregar(e);
            e = temporal->Extraer();
        }
    }
    cout << endl;
}





void UltimoLibro()
{
    cout << endl;
    Elemento *e = pila->Extraer();
    if(e == NULL)
    {
        cout << "La lista está vacía" << endl;
    }else
    {
        cout << e->GetTitulo() << " (" << e->GetAutor() << ")" << endl;
    }
    cout << endl;
}


void Insertar()
{
    cout << endl;
    string titulo;
    string autor;
    string editora;
    string fecha;
    string categoria;

    cout << "Introducir el título del libro: ";
    getline(cin, titulo);
    cout << "Introducir el autor del libro: ";
    getline(cin, autor);
    cout << "Introducir el editora del libro: ";
    getline(cin, editora);
    cout << "Introducir la fecha de publicación del libro: ";
    getline(cin, fecha);
    cout << "Introducir la categoria del libro: ";
    getline(cin, categoria);

    Elemento* elemento = new Elemento(titulo, autor, editora, fecha , categoria);
    pila->Agregar(elemento);
    cout << endl << endl;
}


void MostrarMenu()
{
    int opcion = 0;
    do
    {
        cout << endl;
        cout << "1- Listar libros" << endl;
        cout << "2- Insertar Libro" << endl;
        cout << "3- Solicitar último libro de la pila" << endl;
        cout << "4- Buscar Libro por categoría" << endl;
        cout << "5- Salir" << endl;
        cout << "Elija una opción => ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion)
        {
            case 1:
                Listar();
            break;
            case 2:
                Insertar();
            break;
            case 3:
                UltimoLibro();
            break;
            case 4:
                Buscar();
            break;
            case 5:
                exit(0);
            break;
            default:
                cout << "Opción inválida" << endl;
            break;
        }
    }while(opcion != 5);
}

int main()
{
    MostrarMenu();
    return 0;
}
