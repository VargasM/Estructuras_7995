#include <iostream>
#include "Grafo.h"
using namespace std; 

int main( int argc, char* argv[] ) {

    Grafo<int,int> grafo; 
    grafo.insertarVertice(0);
    grafo.insertarVertice(1);
    grafo.insertarVertice(2);
    grafo.insertarVertice(3);

   

    grafo.insertarArista(0,1,2);
    grafo.insertarArista(0,3,3);
    grafo.insertarArista(1,2,5);
    grafo.insertarArista(1,0,6);
    grafo.insertarArista(1,3,2);
    grafo.insertarArista(2,0,3);
    grafo.insertarArista(3,2,6);
    grafo.insertarArista(3,1,5);

     if(grafo.buscarVertice(1)!= -1){
        cout<<"El vertice "<<grafo.buscarVertice(1)<<" existe"<<endl;
    }

    cout<<"Numero vertices : "<<grafo.cantVertices()<<endl;
    cout<<"Numero de aristas "<<grafo.cantAristas()<<endl;
    grafo.eliminarArista(0,1);
    grafo.eliminarArista(1,3);
    
    cout<<"Numero de aristas despúes de el llamado de la función eliminarArista dos veces: "<<grafo.cantAristas()<<endl;
    if(grafo.buscarArista(3,1) != -1){
        cout<<"Costo de conexión de la arista 3 y 1 es: "<<grafo.buscarArista(3,1)<<endl;
    }
    if(grafo.buscarArista(11,9) == -1){
        cout<<"La arista 11 y 9 no existe "<<endl;
    }

    cout<<"Costo de conexión de la arista 1 y 0 : "<<grafo.buscarArista(1,0)<<endl;
    grafo.eliminarVertice(0);
    //Prueba con vertice que no existe
    grafo.eliminarVertice(8);
    cout<<"Número de vertices despúes del llamado de la función eliminarVertice "<<grafo.cantVertices()<<endl;

}
    