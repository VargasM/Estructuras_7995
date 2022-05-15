// =========================================================================
// @author: Anderson Alvarado
// =========================================================================
#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <vector>
#include <utility>
#include <stack>
#include <limits>
#include <queue>
using namespace std;

typedef long long unsigned ll;

template <class T, class C>
class Grafo
{
protected:
    vector <vector<C>> matAristas;
    vector<T> vertices;
    ll numVertices = 0;

public:
    int  cantiVertices();
    int  cantiAristas();
    void insertarVertice(T Vertice);
    void insertarArista(T origen, T destino, C peso);
    ll   buscarVertice(T vertice);
    T    obtenerVertice(ll indice);
    bool buscarArista(ll origen, ll destino);
    void eliminarVertice(T vertice);
    void eliminarArista(T origen, T destino);
    void recorridoPlano();
    void imprimirGrafo();
    void recorridoDFS(T inicio);
    void recorridoDFS(ll inicio, bool *visitados);
    void recorridoBFS(T inicio);
    void prim(T inicio,vector<T> &camino,vector<T> &predecesor ,vector<C> &pesos);
    void menorPeso(vector<pair<int,int>> &vistos);
    void dijkstra(T inicio, vector<T> &s, vector<T> &pred,  vector<C> &dist);
};

#include "Grafo.hxx"
#endif