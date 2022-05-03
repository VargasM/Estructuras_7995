#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    Grafo<string,int> grafo;
    //Se insertan los vertices
    grafo.insertarVertice("C1");
    grafo.insertarVertice("C2");
    grafo.insertarVertice("C3");
    grafo.insertarVertice("C4");
    //Se insertan las aritas
    grafo.insertarArista("C1", "C2", 1);
    grafo.insertarArista("C2", "C1", 9);
    grafo.insertarArista("C1", "C4", 8);
    grafo.insertarArista("C2", "C4", 6);
    grafo.insertarArista("C2", "C3", 4);
    grafo.insertarArista("C4", "C2", 3);
    grafo.insertarArista("C4", "C3", 7);
    grafo.insertarArista("C3", "C1", 5);
    //Cantidad de vertices
    cout << "cantidad de vertices: " << grafo.cantidadVertices();
    //Cantidad de aristas
    cout << endl << "cantidad de aristas: " << grafo.cantidadAristas();
    //Busca arista
    grafo.buscarArista("C1", "C2");
    //Elima vertice
    grafo.eliminarVertice("C4");
    cout<<endl<< "vertice C4 eliminado: ";
    //Muestra las aristas y vertices actualizados
    cout << endl << "cantidad de vertices: " << grafo.cantidadVertices();
    cout << endl << "cantidad de aristas: " << grafo.cantidadAristas();
    //Elimina arista
    grafo.eliminarArista("C2", "C3");
    cout<<endl<<"arista C2->C3 eliminado: ";
    //Muestra las ariats y vertices actualizadas
    cout << endl << "cantidad de vertices: " << grafo.cantidadVertices();
    cout << endl << "cantidad de aristas: " << grafo.cantidadAristas();
}
