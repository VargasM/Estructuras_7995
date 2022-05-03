ve
#ifndef UNTITLED3_GRAFO_H
#define UNTITLED3_GRAFO_H

#include "vector"
#include "iostream"
#include "list"

using namespace  std;
template <class T ,class U>
class grafo {
private:
    vector <T> vertices;
    vector <vector <pair <int,U>>> aristas;
public:
    grafo();
    int cantivertices();
    int cantiaristas();
    int buscarVertice (T vert);
    bool insertarVertice ( T vert );
    bool insertarArista( T ori, T des, U cos );
    U buscarArista (T ori, T des);
    bool eliminarVertice(T vert);
    bool eliminarArista(T ori, T des);
    void graficar();
};

#include "grafo.hxx"

#endif //UNTITLED3_GRAFO_H
