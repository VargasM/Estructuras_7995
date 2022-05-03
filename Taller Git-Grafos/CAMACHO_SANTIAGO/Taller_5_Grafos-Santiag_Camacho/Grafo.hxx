//
// Created by Santiago on 2/5/2022.
//

#ifndef TALLER_5_GRAFO_GRAFO_HXX
#define TALLER_5_GRAFO_GRAFO_HXX

#include "Grafo.h"

template<class T, class U>
Grafo<T, U>::Grafo() = default;

template<class T, class U>
int Grafo<T, U>::cantidadVertices() {
    return vertices.size();

}

template<class T, class U>
int Grafo<T, U>::cantidadAristas() {
    int totalAristas=0;
    for (int i = 0; i < cantidadVertices(); ++i) {
        totalAristas+=aristas[i].size();
    }
    return totalAristas;
}

template<class T, class U>
int Grafo<T, U>::buscarVertice(T vertice) {
    int identificador = -1;
    for (int i = 0; i < cantidadVertices(); ++i) {
        if(vertices[i]==vertice){
            identificador=i;
        }
    }
    return identificador;
}

template<class T, class U>
bool Grafo<T, U>::insertarVertice(T vertice) {
    bool insertado=false;
    if(buscarVertice(vertice)==-1){
        vertices.push_back(vertice);
        vector< pair<int,U> > *nuevaArista = new vector<pair<int, U>>;
        aristas.push_back(*nuevaArista);
        insertado= true;
    }
    return insertado;
}

template<class T, class U>
bool Grafo<T, U>::insertarArista(T ori, T des, U cos) {
    bool insertada=false;
    int auxOrigen = buscarVertice(ori);
    int auxDestino = buscarVertice(des);
    if(auxOrigen != -1 && auxDestino != -1){
        bool existe= false;
        for (int i = 0; i < aristas.size(); ++i) {
            for (int j = 0; j < aristas[i].size(); ++j) {
                if(i==auxOrigen){
                    if(aristas[i][j].first==auxDestino){
                        existe= true;
                    }
                }
            }
        }
        if(!existe){
            pair<int, U> *nuevoPar = new pair<int, U>;
            nuevoPar->first=auxDestino;
            nuevoPar->second=cos;
            aristas[auxOrigen].push_back(*nuevoPar);
            insertada=true;
        }
    }
    return insertada;
}

template<class T, class U>
U Grafo<T, U>::buscarArista(T ori, T des) {
    U res =-1;
    int auxOrigen= buscarVertice(ori);
    int auxDestino = buscarVertice(des);
    if(auxOrigen != -1 && auxDestino != -1){
        for (int i = 0; i < aristas.size(); ++i) {
            for (int j = 0; j < aristas[i].size(); ++j) {
                if(i==auxOrigen){
                    if(aristas[i][j].first==auxDestino){
                        res=aristas[i][j].second;
                    }
                }
            }
        }
    }
    return res;
}

template<class T, class U>
bool Grafo<T, U>::eliminarArista(T ori, T des) {
    bool eliminado=false;
    int posicionEliminar=0;
    int auxOrigen= buscarVertice(ori);
    int auxDestino = buscarVertice(des);
    vector< pair<int, U> > *aux= &aristas[auxOrigen];
    if(auxOrigen != -1 && auxDestino != -1){
        for (int i = 0; i < aristas.size(); ++i) {
            for (int j = 0; j < aristas[i].size(); ++j) {
                if(i==auxOrigen){
                    if(aristas[i][j].first==auxDestino){
                        posicionEliminar=j;
                    }
                }
            }
        }
        aux->erase(aux->begin()+posicionEliminar);
        eliminado=true;
    }
    return eliminado;
}

template<class T, class U>
bool Grafo<T, U>::eliminarVertice(T vert) {
   bool eliminado=false;
   int vertice= buscarVertice(vert);
   if(vertice!=-1){
       vector<pair<int, U>> *aux = &aristas[vertice];
       aux->clear();
       aristas.erase(aristas.begin() + vertice);
       for (int i = 0; i < aristas.size(); i++)
       {
           aux = &aristas[i];
           for (int j = 0; j < aux->size(); j++)
           {
               pair<int, U> temp = (*aux)[j];
               if (temp.first == vertice)
               {
                   aux->erase(aux->begin() + j);
                   eliminado = true;
               }
           }
       }
       vertices.erase(vertices.begin() + vertice);
       eliminado=true;
   }
    return eliminado;
}

#endif //TALLER_5_GRAFO_GRAFO_HXX
