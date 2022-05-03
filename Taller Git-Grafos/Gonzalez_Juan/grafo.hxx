//
// Created by 57318 on 2/05/2022.
//
#include "grafo.h"


        template < class T, class U>
        Grafo<T,U>::Grafo(){
        }


        template < class T, class U>
        int Grafo<T,U>::cantiVertices(){
            return vertices.size();
        }


        template < class T, class U>
        int Grafo<T,U>::cantiAristas(){

            int suma=0;
            for (int i=0; i< cantiVertices(); i++){
                suma=suma+aristas[i].size();
            }
            return suma;
        }


        template < class T, class U>
        int Grafo<T,U>::buscarVertice(T vertice){

            int ind= -1;
            for (int i=0; i<cantiVertices(); i++){
                if (vertices[i]==vertice){
                    ind=i;
                }
            }
            return ind;
        }

        template < class T, class U>
        bool Grafo<T,U>::insertarVertice(T vertice){
            bool insertado = false;
            if (buscarVertice(vertice)==-1){
                vertices.push_back(vertice);
                vector < pair < int , U > > *nvector = new vector < pair < int, U>>;
                aristas.push_back(*nvector);
                insertado=true;
            }
            return insertado;
        }

        template < class T, class U>
        bool Grafo<T,U>::insertarArista(T origen, T destino, U costo){
            bool insertado=false;
            int elorigen = buscarVertice(origen);
            int eldestino = buscarVertice(destino);
            if(elorigen != -1 && eldestino != -1){
                if(buscarArista(elorigen, eldestino)==-1)
                {
                    pair <int, U> *n_par = new pair<int, U>;
                    n_par -> first = eldestino;
                    n_par -> second = costo;
                    aristas[elorigen].push_back(*n_par);
                    insertado=true;
                }
            }
            return insertado;
        }

        template < class T, class U>
        U Grafo<T, U>::buscarArista(T origen, T destino){
            int res=-1;
            int elorigen=buscarVertice(origen);
            int eldestino=buscarVertice(destino);
            if(elorigen != -1 && eldestino != -1) {
                typename vector < pair < int, U > > ::iterator it = aristas[elorigen].begin();
                for (; it != aristas[elorigen].end(); it++) {
                    if (it->first == eldestino) {
                        res = it->second;
                    }
                }
            }
            return res;
        }

        template < class T , class U>
        bool Grafo<T,U>::eliminarVertice(T vertice){
            bool eliminado =false;
            int pos=buscarVertice(vertice);
            if(pos!=-1){
                vector<pair<int, U>> *aux = &aristas[pos];
                aux->clear();
                aristas.erase(aristas.begin()+pos);
                for(int i=0; i<aristas.size(); i++){
                    for(int j=0; j<aristas[i].size(); j++){
                        if(aristas[i][j].first==pos){
                            aristas[i].erase(aristas[i].begin()+j);
                            eliminado=true;
                        }
                    }
                }
                vertices.erase(vertices.begin()+pos);
            }
            return eliminado;
        }

        template < class T, class U>
        bool Grafo<T,U>::eliminarArista(T origen, T destino){
            bool res = false;
            int elorigen=buscarVertice(origen);
            int eldestino=buscarVertice(destino);
            if(elorigen != -1 && eldestino != -1){
                typename vector < pair <int,U> >::iterator it, posE;
                for (it = aristas[elorigen].begin();it!=aristas[elorigen].end();it++){
                    if(it->first == eldestino) {
                        posE = it;
                    }
                }
                aristas[elorigen].erase(posE);
            }
            return res;
        }
