#include "grafo.h"

template<class T, class U>
grafo<T, U>::grafo() {

}

template <class T,class U>
int  grafo<T,U>::cantivertices(){
    this->vertices.size ();
	return vertices.size();
}
template <class T,class U>
int  grafo<T,U>::cantiaristas(){
   int suma =0;
    for (int i = 0; i <cantivertices() ; ++i) {
    suma+= aristas [i].size();
    }
    return suma;
}
template <class T,class U>
int grafo<T,U>::buscarVertice (T vert){
    int ind = -1;
    for (int i = 0; i < cantivertices () ; ++i) {
        if  (vertices [i]==vert){
            ind =i;
        }
    }
    return ind;
}
template <class T,class U>
bool grafo<T,U>::insertarVertice ( T vert )
{
    bool res= false;
    if (buscarVertice(vert) == -1){
        vertices.push_back(vert);
        vector<std::pair< int, U >> *nvector = new std::vector<std::pair< int, U >>;
        aristas.push_back(*nvector);
        res = true;
    }
    return res;
}
template <class T,class U>
bool grafo<T,U>::insertarArista( T ori, T des, U cos ){
    bool res = false;
    int i_ori = buscarVertice(ori);
    int i_des = buscarVertice(des);
    if(i_ori != -1 && i_des != -1){
        bool esta = false;
       typename std::vector<std::pair<int, U> >::iterator it = aristas[i_ori].begin();
        for(; it != aristas[i_ori].end(); it++){
            if(it->first == i_des) esta = true;
        }
        if (!esta){
            std::pair<int, U> *n_par = new std::pair<int, U>;
            n_par -> first = i_des;
            n_par -> second = cos;
            aristas[i_ori].push_back(*n_par);
            res = true;
        }
    }
    return res;
}
template <class T,class U>
U grafo<T,U>::buscarArista(T ori, T des) {
    U res = -1;
    int i_ori = buscarVertice(ori);
    int i_des = buscarVertice(des);
    if ( i_ori != -1 && i_des != -1 ) {
        typename std::vector< pair<int,U> >::iterator it = aristas[i_ori].begin();
        for (; it != aristas[i_ori].end(); it++) {
            if (it->first == i_des)  res = it->second;
        }
    }
    return res;
}
template <class T,class U>
bool grafo<T,U>::eliminarVertice(T vert) {
    bool res = false;
    int i_vert = buscarVertice(vert);
    if ( i_vert != -1) {
      vector< pair<int,U> > *itA = &aristas[i_vert];
      aristas.erase(aristas.begin()+i_vert);
        for (int i = 0; i < aristas.size(); ++i) {
            itA=&aristas[i];
            for (int j = 0; j < itA->size(); ++j) {
                pair<int,U> temp =(*itA)[j];
                if (temp.first==i_vert){
                  itA->erase(itA->begin()+j);
                  res= true;
                }
            }
        }
        vertices.erase(vertices.begin()+i_vert);
    }
    return res;
}
template <class T,class U>
bool grafo<T,U>::eliminarArista(T ori, T des) {
    bool res = false;
    int i_ori = buscarVertice(ori);
    int i_des = buscarVertice(des);
    if ( i_ori != -1 && i_des != -1 ) {
      typename  std::vector< pair<int,U> >::iterator it, posE;
        for (it = aristas[i_ori].begin(); it != aristas[i_ori].end(); it++) {
            if (it->first == i_des)  posE = it;
        }
        aristas[i_ori].erase(posE);
    }
    return res;
}

/*template <class T,class U>
void grafo<T,U>::graficar()
{
    int cant=cantivertices();
    for (int i = 0; i < cant; ++i) {
        cout<< vertices[i]<<"----->";
        vector <pair<int,U>> cont=aristas[i];

    }

}
*/
