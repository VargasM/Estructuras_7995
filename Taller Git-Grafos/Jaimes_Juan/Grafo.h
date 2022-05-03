#ifndef GRAFO_H_
#define GRAFO_H_
#include <list>
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <class T>
struct Grafo
{
	vector<T> vertex;
	vector< list< pair<int,float> > > aristas;

	int CantiVertex();
	int CantiAristas();
	int BuscarVertice(T vert);
	bool insertarVertice(T vert);
	bool insertarArista(T ori, T dest, float costo);
	int BuscarArista(T ori, T dest);
	bool EliminarVertice(T elim);
	bool EliminarArista(T oriE, T destE);

};

#include "Grafo.hxx"

#endif