#include "iostream"
#include "grafo.h"
using namespace std;
int main() {
  grafo<string,int> grafito;
   //INSERTAR VERTICES
    grafito.insertarVertice("C1");
    grafito.insertarVertice("C2");
    grafito.insertarVertice("C3");
    grafito.insertarVertice("C4");
    //INSERTAR ARISTAS
    grafito.insertarArista("C1","C2",2);
    grafito.insertarArista("C2","C1",6);
    grafito.insertarArista("C1","C4",3);
    grafito.insertarArista("C2","C4",2);
    grafito.insertarArista("C2","C3",5);
    grafito.insertarArista("C4","C2",5);
    grafito.insertarArista("C4","C3",6);
    grafito.insertarArista("C3","C1",3);
    //MOSTRAR CANTIDAD DE VERTICES
    cout<<"cantidad de vertices: "<<grafito.cantivertices();
    //MOSTRAR CANTIDAD DE ARISTAS
    cout <<endl<<"cantidad de aristas: "<<grafito.cantiaristas();
    //BUSCAR ARISTAS
    grafito.buscarArista("C1","C2");
    //graficar completo
    // grafito.graficar();
   //eliminar vertice
    grafito.eliminarVertice("C4");
   cout<<endl<< "vertice C4 eliminado: ";
   //reconteo
    cout<<endl<<"cantidad de vertices: "<<grafito.cantivertices();
    cout<<endl<<"cantidad de aristas: "<<grafito.cantiaristas();
    //eliminar arista
    grafito.eliminarArista("C2","C3");
    cout<<endl<<"arista C2->C3 eliminado: ";
    //reconteo
    cout<<endl<<"cantidad de vertices: "<<grafito.cantivertices();
    cout<<endl<<"cantidad de aristas: "<<grafito.cantiaristas();
}
