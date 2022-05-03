#ifndef __GRAFOSTADGRAFOSACTUALIZADOS_H__
#define __GRAFOSTADGRAFOSACTUALIZADOS_H__

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>

using namespace std;

template <class T, class V>
class Grafo
{
protected:
    vector <T> vertices;
    vector<vector<pair<T,V>>> aristas; // vector de vectores de pares que contiene el valor del nodo T y la conexion V
public:
    void crearGrafo();
    int cantidadVertices();
    int cantidadAristas();
    int encontrarVertice (T n_ver);
    int encontrarArista(T n_ori, T n_des);
    bool insertarVertice (T n_ver);
    bool insertarArista (T n_ori, T n_des, V val);
    bool eliminarVertice(T n_ver);
    bool eliminarArista(V n_ori, V n_des);
};

#include "TADGRAFOSACTUALIZADOS.HXX"
#endif
