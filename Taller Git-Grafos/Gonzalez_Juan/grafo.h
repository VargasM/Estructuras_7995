//
// Created by 57318 on 2/05/2022.
//

#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <class T, class U>
class Grafo{
private:
    vector<T> vertices;
    vector < vector < pair < int, U > > > aristas;

public:
    Grafo();
    int cantiVertices();
    int cantiAristas();
    int buscarVertice(T vertice);
    bool insertarVertice(T vertice);
    U buscarArista(T origen, T destino);
    bool eliminarVertice(T vertice);
    bool eliminarArista(T origen, T destino);
    bool insertarArista(T origen, T destino, U costo);
};

#include "grafo.hxx"
#endif