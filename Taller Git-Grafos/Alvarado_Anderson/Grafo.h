// =========================================================================
// @author: Anderson Alvarado
// =========================================================================
#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <utility>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <algorithm> //sort
using namespace std;

template <class T, class C>
class Grafo
{
protected:
    vector<vector<pair<int, C>>> aristas; //{vertice destino, peso}
    vector<T> vertices;

public:
    int cantVertices();
    int cantAristas();
    int buscarVertice(T vertice);
    bool insertarVertice(T Vertice);
    void eliminarVertice(T vertice);
    bool insertarArista(T origen, T destino, C peso);
    int buscarArista(int origen, int destino);
    bool eliminarArista(T origen, T destino);
    void imprimirGrafo();
    void recorridoPlano();
    void recorridoDFS(T inicio);
    void recorridoDFS(int indice, bool *visitados);
    void recorridoBFS(T vOrigen);
    int prim(T vOrigen);
    void kruskal();
    void iniciar(vector<int> &v);
    int encontrar(vector <int> &v, int &a);
    void unir(vector <int> &v,int &a, int &b);
    void dijkstra(T vOrigen);
};

#include "Grafo.hxx"
#endif