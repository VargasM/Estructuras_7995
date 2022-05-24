#ifndef GRAFO_H_INCLUDED
	#define GRAFO_H_INCLUDED
	#include <vector>
	

	using namespace std;
	

	template<class T, class U>
	class Grafo
	{
	protected:
	    vector<T> vertices ;
	    vector < vector< pair< int, T >>> aristas;
	

	public:
	    int cantVertices();
	    int cantAristas ();
	    int buscarVertices(T vert);
	    bool insertarVertice(T vert);
	    bool insertarArista(T ori,T des,U cos);
	    U buscarArista(T ori, T des);
	    bool eliminarVertice(T vert);
	    bool eliminarArista(T ori, T des);
	};
	

	

	

	#include "Grafo.hxx"
	

	#endif // GRAFO_H_INCLUDED
