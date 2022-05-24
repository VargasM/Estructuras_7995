#ifndef GRAFO_HXX_INCLUDED
	#define GRAFO_HXX_INCLUDED
	#include <vector>
	#include <list>
	#include "Grafo.h"
	

	using namespace std;
	

	template<class T, class U>
	

	int Grafo<T,U>::cantVertices()
	{
	    return vertices.size();
	}
	

	template<class T, class U>
	int Grafo<T,U>::cantAristas()
	{
	    int suma = 0;
	    for (int i=0; i< cantVertices(); i++)
	    {
	        suma += aristas[i].size();
	    }
	    return suma;
	}
	

	template<class T, class U>
	int Grafo<T,U>::buscarVertices(T vert)
	{
	    int ind = -1;
	    for(int i = 0 ; i < cantVertices(); i++)
	    {
	        if(vertices[i] == vert)
	        {
	            ind= i;
	        }
	    }
	    return ind;
	}
	

	

	template<class T, class U>
	bool Grafo<T,U>::insertarVertice(T vert)
	{
	    bool res = false;
	    if (buscarVertices(vert) == -1)
	    {
	        vertices.push_back(vert);
	        vector<pair<int,char>> *nvector = new vector <pair<int,char>> ;
	        aristas.push_back(*nvector);
	        res = true;
	    }
	    return res;
	}
	

	template<class T, class U>
	bool Grafo<T,U>::insertarArista(T ori,T des,U cos)
	{
	    bool res = false;
	    int i_ori = buscarVertices(ori);
	    int i_des = buscarVertices(des);
	

	    if(i_ori != -1 && i_des != -1)
	    {
	        bool esta = false;
	        typename vector<pair<int, char> >::iterator it;
	

	        for(it = aristas[i_ori].begin(); it != aristas[i_ori].end(); it++)
	        {
	            if(it->first == i_des) esta = true;
	        }
	        if (!esta)
	        {
	            pair<int, U> *n_par = new pair<int, U>;
	            n_par -> first = i_des;
	            n_par -> second = cos;
	            aristas[i_ori].push_back(*n_par);
	            res = true;
	        }
	    }
	    return res;
	}
	

	

	template<class T, class U>
	U Grafo<T,U>:: buscarArista(T ori, T des)
	{
	    U res = -1;
	    int i_ori = buscarVertices(ori);
	    int i_des = buscarVertices(des);
	    if ( i_ori != -1 && i_des != -1 )
	    {
	        typename vector< pair<int,T> >::iterator it;
	

	        for (it = aristas[i_ori].begin(); it != aristas[i_ori].end(); it++)
	        {
	            if (it->first == i_des)
	            {
	                res = it->second;
	            }
	        }
	    }
	    return res;
	}
	

	template<class T, class U>
	bool Grafo<T,U>::eliminarVertice(T vert)
	{
	    bool res = false;
	    int i_vert = buscarVertices(vert);
	    if ( i_vert != -1)
	    {
	        typename vector<vector<pair<int,T>>>::iterator itA, posE;
	

	        int ind = 0;
	        for (itA = aristas.begin(); itA != aristas.end(); itA++, ind++)
	        {
	            if (ind == i_vert)
	            {
	                posE = itA;
	            }
	            else
	            {
	                typename vector< pair<int,T> >::iterator it, posEE;
	

	                for (it = itA->begin(); it != itA->end(); it++)
	                {
	                    if (it->first == i_vert)
	                    {
	                        posEE = it;
	                    }
	                }
	                itA->erase(posEE);
	            }
	        }
	        aristas.erase(posE);
	    }
	    return res;
	}
	

	template<class T, class U>
	bool Grafo<T,U>::eliminarArista(T ori, T des)
	{
	    bool res = false;
	    int i_ori = buscarVertices(ori);
	    int i_des = buscarVertices(des);
	    if ( i_ori != -1 && i_des != -1 )
	    {
	        typename vector< pair<int,T> >::iterator it, posE;
	        for (it = aristas[i_ori].begin(); it != aristas[i_ori].end(); it++)
	        {
	            if (it->first == i_des)  posE = it;
	        }
	        aristas[i_ori].erase(posE);
	    }
	    return res;
	}
	

	#endif // GRAFO_HXX_INCLUDED
