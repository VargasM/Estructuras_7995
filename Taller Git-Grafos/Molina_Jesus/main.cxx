#include <iostream>
#include "grafo.h"
using namespace std;


int main( int argc, char* argv[] )
{
    GRAFO<int,int> grafo;
    grafo.insertarVertice(1);
    grafo.insertarVertice(2);
    grafo.insertarVertice(3);
    grafo.insertarVertice(4);

    grafo.insertarArista(2,3,8);
    grafo.insertarArista(4,1,1);
    grafo.insertarArista(4,2,4);
    grafo.insertarArista(1,2,6);
    grafo.insertarArista(1,3,2);


    if(grafo.buscarVertices(3)!= -1)
    {
        cout<<"\nSi existe el vertice "<<grafo.buscarVertices(3);
    }
    else
    {
        cout<<"\nNo existe el vertice "<<grafo.buscarVertices(3);

    }

    cout<<"\nCantidad de vertices : "<<grafo.cantVertices();
    cout<<"\nNumero de aristas "<<grafo.cantAristas();

    bool confirmacion=grafo.eliminarArista(4,1);
    if (confirmacion==true)
      cout<<"\n Se elimino la arista";
    else
      cout<<"\nNo se elimino la arista";


    cout<<"\nNumero de aristas "<<grafo.cantAristas();

    if(grafo.buscarArista(4,1) == -1)
        cout<<"\nCosto de conexión: "<<grafo.buscarArista(3,1);
     else
        cout<<"\nLa arista no existe ";

    confirmacion=grafo.eliminarVertice(4);
      if (confirmacion==true)
        cout<<"\n Se elimino el vertice";
      else
        cout<<"\nNo se elimino el vertice";

    cout<<"\nCantidad de vertices : "<<grafo.cantVertices();
}
