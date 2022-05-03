#ifndef _GRAFO_H
#define _GRAFO_H
#include <list>
#include <vector>
#include <utility>


using namespace std; 

template <class T, class U = int>
class Grafo{
    private:
        vector<T> vertices;  
        vector<vector<pair<int,U>>> aristas; 
    public:
        //Grafo();
        int cantVertices();
        int cantAristas();  
        U buscarVertice(T vertice); 
        bool insertarVertice(T vertice);
        bool insertarArista(T ori, T des, U cos); 
        U buscarArista(T ori,T des);
        bool eliminarVertice(T vertice);
        bool eliminarArista(T ori, T des); 

};
#include "Grafo.hxx"
#endif