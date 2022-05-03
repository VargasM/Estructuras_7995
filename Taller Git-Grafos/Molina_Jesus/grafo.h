#ifndef _GRAFO_H
#define _GRAFO_H
#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

template< class T, class U = int>
class GRAFO
{
private:
    vector<T> vertices ;
    vector < vector< pair< int, U > > > aristas;


public:
    int cantVertices();
    int cantAristas ();
    int buscarVertices(T vert);
    bool insertarVertice ( T vert );
    bool insertarArista( T ori, T des, U cos );
    U buscarArista(T ori, T des);
    bool eliminarVertice(T vert);
    bool eliminarArista(T ori, T des);


};
#include "grafo.hxx"

#endif





