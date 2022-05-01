#include "Grafo.h"
#include <vector>
#include <iostream>
#include <utility>
#include <iostream>

using namespace std; 

template <class T,class U>
int Grafo<T,U>::cantVertices(){
    return this->vertices.size();
}

template <class T,class U>
int Grafo<T,U>::cantAristas(){

    int sum = 0 ; 
    for(int i = 0 ; i< this->cantVertices();i++){
        sum += this->aristas[i].size();
    }
    return sum; 
}


template <class T,class U>
U Grafo<T,U>::buscarVertice(T vertice){

    int ind = -1;
    for(int i = 0 ; i<this->cantVertices();i++){
        if(this->vertices[i] == vertice){
            ind = i ; 
        }
    }
    return ind; 
}

template <class T,class U>
bool Grafo<T,U>::insertarVertice(T vertice){
    bool res = false; 

    if(this->buscarVertice(vertice) ==-1){
        this->vertices.push_back(vertice);
        vector<pair<int,U>> *nVec = new vector<pair<int,U>>;
        this->aristas.push_back(*nVec);
        res = true;  
    }

    return res; 

}


template <class T,class U>
bool Grafo<T,U>::insertarArista(T ori, T des, U cos){
    bool res = false; 
    int i_ori = buscarVertice(ori);
    int i_dest = buscarVertice(des);


    if(i_ori !=-1 && i_dest !=-1){
        bool esta = false; 
        typename vector<pair<int,U> >::iterator it = this->aristas[i_ori].begin();
        //Se verifica si la arista ya exsite 
        for(;it!= this->aristas[i_ori].end();it++){
            if(it->first == i_dest){
                esta = true;
            }
        }
        //Se no esta se inserta la arista
        if(!esta){
            pair<int,U> *n_par =  new pair<int,U>;
            n_par ->first = i_dest; 
            n_par ->second = cos; 
            this->aristas[i_ori].push_back(*n_par);
            res = true; 
             
        }
    }
    return res; 

}


template <class T,class U>
bool Grafo<T,U>::eliminarVertice(T vertice){
    int ind = this->buscarVertice(vertice); 
    if(ind!= -1){
        for(int i = 0 ; i<this->aristas.size();i++){
            for(typename vector<pair<int,U>> :: iterator it2 = this->aristas[i].begin();it2 != this->aristas[i].end();it2++){
                if(it2-> first == vertice){
                    this->aristas[i].erase(it2);
                    break;
                }
            }
        }
        this->aristas.erase(this->aristas.begin()+ind);
        this->vertices.erase(this->vertices.begin()+ind);
        return true;
    }
    return false;
}

template <class T,class U>
bool Grafo<T,U>::eliminarArista(T ori, T des){
    bool eliminado = false;
    int i_ori = buscarVertice(ori);
    int i_dest = buscarVertice(des);
    if(i_ori != -1 && i_dest != -1){
        typename vector<pair<int,U> >::iterator it = this->aristas[i_ori].begin();
        //Se verifica si la arista ya exsite 
        for(;it!= this->aristas[i_ori].end();it++){
            if(it->first == i_dest){
                this->aristas[i_ori].erase(it);
                eliminado = true;
                break;
            }
        }

    }
    return eliminado;
}

template <class T,class U>
U Grafo<T,U>::buscarArista(T ori, T des){
    bool encontrado = false;
    int r = -1 ; 
    int i_ori = buscarVertice(ori);
    int i_dest = buscarVertice(des);
    if(i_ori != -1 && i_dest != -1){
        typename vector<pair<int,U> >::iterator it = this->aristas[i_ori].begin();
        //Se verifica si la arista ya exsite 
        for(;it!= this->aristas[i_ori].end();it++){
            if(it->first == i_dest){
                r = it->second;
                break;
            }
        }

    }
    return r;
}







