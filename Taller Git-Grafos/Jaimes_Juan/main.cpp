#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    Grafo<string> MiGrafo;

    MiGrafo.insertarVertice("C1");
    MiGrafo.insertarVertice("C2");
    MiGrafo.insertarVertice("C3");
    MiGrafo.insertarVertice("C4");

    MiGrafo.insertarArista("C1", "C2", 2);
    MiGrafo.insertarArista("C2", "C1", 6);
    MiGrafo.insertarArista("C1", "C4", 3);
    MiGrafo.insertarArista("C2", "C4", 2);
    MiGrafo.insertarArista("C2", "C3", 5);
    MiGrafo.insertarArista("C4", "C2", 5);
    MiGrafo.insertarArista("C4", "C3", 6);
    MiGrafo.insertarArista("C3", "C1", 3);

    cout << "Vertices del grafo: " << MiGrafo.CantiVertex() << endl;
    cout << "Aristas del grafo: " << MiGrafo.CantiAristas() << endl;
    int encontrado = MiGrafo.BuscarArista("C1", "C2");
    cout << "Arista encontrada: " << encontrado << endl;
    bool eliminado = MiGrafo.EliminarVertice("C2");
    cout << "Vertice C2 eliminado: " << eliminado << endl;

    cout << "Vertices del grafo: " << MiGrafo.CantiVertex() << endl;
    cout << "Aristas del grafo: " << MiGrafo.CantiAristas() << endl;

    eliminado = MiGrafo.EliminarArista("C1", "C2");
    cout << "arista C1->C2 eliminado: " << eliminado << endl;

    cout << "Vertices del grafo: " << MiGrafo.CantiVertex() << endl;
    cout << "Aristas del grafo: " << MiGrafo.CantiAristas() << endl;
}


