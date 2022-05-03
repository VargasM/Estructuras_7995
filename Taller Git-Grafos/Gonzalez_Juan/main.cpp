#include <iostream>
#include "grafo.h"

using namespace std;

int main() {

    Grafo<int,int> grafo;
    int verif, vertice, origen, destino, costo;


    //insercion de vertices
    for(int i=0; i<4; i++){
        cout << "\nIngrese un Vertice: ";
        cin >> vertice;
        verif=grafo.buscarVertice(vertice);

        if(verif!=-1)
        {
            cout << "\nVEl vertice ya existe" << endl;
        }
        else
        {
            grafo.insertarVertice(vertice);
        }
    }

    //insercion de aristas
    for(int i=0; i<9; i++){
        cout << "\nIngrese un vertice origen: ";
        cin >> origen;
        cout << "\nIngrese un vertice destino: ";
        cin >> destino;
        cout << "\nIngrese un costo: ";
        cin >> costo;
        grafo.insertarArista(origen, destino, costo);
    }

    //impresion de cantidad de nodos y aristas
    cout << "\n Cantidad de Vertices: " << grafo.cantiVertices() << endl;
    cout << "\n Cantidad de Aristas: " << grafo.cantiAristas() << endl;

    //buscar un vertice
    int aiuda, verticeB;
    cout << "\n¿Que vertice quiere buscar? ";
    cin >> verticeB;
    aiuda=grafo.buscarVertice(verticeB);
    if(aiuda != -1){

        cout << "\nEncontrado!";
    }else{
        cout << "\nNo encontrado!";
    }

    //buscar una arista
    int origenA, destinoA, exito;
    cout << "Ingrese el origen ";
    cin >> origenA;
    cout << "Ingrese el destino: ";
    cin >> destinoA;
    exito = grafo.buscarArista(origenA,destinoA);
    if (exito != -1){

        cout << "Se encontró la arista"<< endl;
    }else {
        cout << "No se encontro la arista." << endl;
    }


    //eliminar un vertice
    int elimi;
    cout << "\nIngrese el vertice que quiere eliminar: ";
    cin>>elimi;
    grafo.eliminarVertice(elimi);


    //eliminar una arista
    int elimiO, elimiD;
    cout << "\nIngrese el origen de la arista que quiere eliminar: ";
    cin>>elimiO;
    cout << "\nIngrese el destino de la arista que quiere eliminar: ";
    cin>>elimiD;
    grafo.eliminarArista(elimiO, elimiD);

}





