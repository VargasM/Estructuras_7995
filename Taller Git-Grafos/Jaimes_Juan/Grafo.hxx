#include "Grafo.h"
#include <queue>
#include <limits>
#include <string.h>

using namespace std;

template <class T>
int Grafo<T>::CantiVertex()
{
	return vertex.size();
}
//-------------------------------------------------------
template <class T>
int Grafo<T>::CantiAristas()
{
	int Tamano = 0;
	if(!aristas.empty())
	{
		for(int i = 0; i < vertex.size(); i++)
	    {
		    Tamano = Tamano + aristas[i].size();
		}
	}
	return Tamano;
}
//-------------------------------------------------------
template <class T>
int Grafo<T>::BuscarVertice(T vert)
{
	int Encontrado = -1;
	for(int i = 0; i < CantiVertex(); i++)
	{
		if(vertex[i] == vert)
		{
			Encontrado = i;
		}
	}

	return Encontrado;
}
//-------------------------------------------------------
template <class T>
bool Grafo<T>::insertarVertice(T vert)
{
	bool comp = false;
	if(BuscarVertice(vert) == -1)
	{
		vertex.push_back(vert);
		list< pair<int,float> > *AddList = new list< pair<int,float> >;
		aristas.push_back(*AddList);
		comp = true;
	}
	return comp;
}
//-------------------------------------------------------
template <class T>
bool Grafo<T>::insertarArista(T ori, T dest, float costo)
{
	bool Insert = false;

	int index_ori = BuscarVertice(ori);
	int index_dest = BuscarVertice(dest);

	if(index_ori != -1 && index_dest != -1)
	{
		list< pair<int,float> >::iterator itList = aristas[index_ori].begin();
		bool ConexEncon = false;
		while(itList != aristas[index_ori].end())
		{
			if(itList->first == index_dest)
			{
				ConexEncon = true;
			}
			itList++;
		}

		if(!ConexEncon)
		{
			pair<int,float> *temp = new pair<int,float>;

			temp->first = index_dest;
			temp->second = costo;
			aristas[index_ori].push_back(*temp);
			Insert = true;
		}
	}

	return Insert;
}
//-------------------------------------------------------
template <class T>
int Grafo<T>::BuscarArista(T ori, T dest)
{
	float CostUnion = -1;

	int index_ori = BuscarVertice(ori);
	int index_dest = BuscarVertice(dest);

	if(index_ori != -1 && index_dest != -1)
	{
		list< pair<int,float> >::iterator itList = aristas[index_ori].begin();
		while(itList != aristas[index_ori].end())
		{
			if(itList->first == index_dest)
			{
				CostUnion = itList->second;
			}
			itList++;
		}
	}

	return CostUnion;
}
//-------------------------------------------------------
template <class T>
bool Grafo<T>::EliminarVertice(T elim)
{
	bool Eliminado = false;
	int IndexElim = BuscarVertice(elim);

	if(IndexElim != -1)
	{
		vector< list< pair<int,float> > >::iterator ItA, PosElim;
		int IndexAux = 0;
		for(ItA = aristas.begin(); ItA != aristas.end(); ItA++, IndexAux++)
		{
			if(IndexAux == IndexElim)
			{
				PosElim = ItA;
				Eliminado = true;
			}
			else
			{
				list< pair<int,float> >::iterator itList, posElim2;
		        for(itList = ItA->begin(); itList != ItA->end();itList++)
		        {
			        if(itList->first == IndexElim)
			        {
				        posElim2 = itList;
				        ItA->erase(posElim2);
			        }
		        }
			}
		}
		aristas[IndexElim].clear();

		//Posicionamiento de NULL dentro del vector de vertex
		for(int i = 0; i < CantiVertex(); i++)
	    {
		    if(i == IndexElim)
		    {
			    vertex[i] = numeric_limits<int>::max();
		    }
	    }
	}
	return Eliminado;
}
//-------------------------------------------------------
template <class T>
bool Grafo<T>::EliminarArista(T oriE, T destE)
{
	bool Comp = false;
	int index_ori = BuscarVertice(oriE);
	int index_dest = BuscarVertice(destE);

	if(index_ori != -1 && index_dest != -1)
	{
		list< pair<int,float> >::iterator itList, posElim3; 
		for(itList = aristas[index_ori].begin();itList != aristas[index_ori].end();itList++)
		{
			if(itList->first == index_dest)
			{
				posElim3 = itList;
				Comp = true;
			}
		}
		aristas[index_ori].erase(posElim3);
	}
	return Comp;
}



