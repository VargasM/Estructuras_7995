//
// Created by Santiago on 2/5/2022.
//

#ifndef TALLER_5_GRAFO_GRAFO_H
#define TALLER_5_GRAFO_GRAFO_H

#include <vector>

using namespace std;


template< class T, class U>
class Grafo{
private:
    vector<T> vertices;
    /*Aristas:  lista de listas de pares, donde cada par contiene un índice
      de vértice (entero) y un costo de conexión (plantilla).*/
    vector< vector< pair<int,U> > > aristas;

public:
    Grafo();
    int cantidadVertices();
    int cantidadAristas();
    int buscarVertice(T vertice);
    bool insertarVertice(T vertice);
    bool insertarArista(T ori, T des, U cos);
    U buscarArista(T ori, T des);
    bool eliminarArista(T ori, T des);
    bool eliminarVertice(T vert);
};

#include "Grafo.hxx"
#endif //TALLER_5_GRAFO_GRAFO_H
