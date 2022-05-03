#include "TADGRAFOSACTUALIZADOS.h"

template <class T, class V>
void Grafo<T,V>::crearGrafo()
{
    if (!aristas.empty())
        aristas.clear();
    cout << "Grafo vacio creado";

}

template <class T, class V>
int Grafo<T, V>::cantidadVertices()
{
    return vertices.size();
}

template <class T, class V>
int Grafo<T, V>::cantidadAristas()
{
    int suma = 0;
    for (int i = 0; i <vertices.size(); ++i)
    {

        suma += aristas[i].size();
    }
    return suma;
}

template <class T, class V>
int Grafo<T, V>::encontrarVertice(T n_ver)
{
    int ind = -1;
    for (int i = 0; i < cantidadVertices(); i++)
    {
        if (n_ver == vertices[i])
            ind = i;
    }
    return ind;
}

template <class T, class V>
bool Grafo<T, V>::insertarVertice(T n_ver)
{
    bool insertado = false;
    if (vertices.size() == 0 || encontrarVertice(n_ver) == -1)
    {
        this->vertices.push_back(n_ver);
        vector<pair<int, V>> aux;
        this->aristas.push_back(aux);
        insertado = true;
    }
    return insertado;
}

template <class T, class V>
bool Grafo<T, V>::eliminarVertice(T n_ver)
{
    bool eliminado = false;
    int ver = encontrarVertice(n_ver);
    if (ver != -1)
    {
        vector<pair<int, V>> *aux = &aristas[ver];
        aux->clear();
        aristas.erase(aristas.begin() + ver);
        for (int i = 0; i < aristas.size(); i++)
        {
            aux = &aristas[i];
            for (int j = 0; j < aux->size(); j++)
            {
                pair<int, V> temp = (*aux)[j];
                if (temp.first == ver)
                {
                    aux->erase(aux->begin() + j);
                    eliminado = true;
                }
            }
        }
        vertices.erase(vertices.begin() + ver);
    }
    return eliminado;
}

template <class T, class V>
int Grafo<T, V>::encontrarArista(T n_ori, T n_des)
{
    int encontrado = -1;
    vector<pair<int, V>> aux = aristas[n_ori];
    for (int i = 0; i < aux.size(); i++)
    {
        pair<int, V> temp = aux[i];
        if (temp.first == n_des)
            encontrado = i;
    }
    return encontrado;
}

template <class T, class V>
bool Grafo<T, V>::insertarArista(T n_ori, T n_des, V val)
{
    bool insertado = false;
    int i_ori = encontrarVertice(n_ori);
    int i_des = encontrarVertice(n_des);
    if (i_ori != -1 && i_des != -1)
    {
        if (encontrarArista(i_ori, i_des) == -1)
        {
            vector<pair<int, V>> *aux = &aristas[i_ori];
            pair<int, V> n_ari(i_des, val);
            aux->push_back(n_ari);
            insertado = true;
        }
    }
    return insertado;
}

template <class T, class V>
bool Grafo<T, V>::eliminarArista(V n_ori, V n_des)
{
    bool res = false;
    T i_ori = encontrarVertice(n_ori);
    T i_des = encontrarVertice(n_des);
    if (i_ori != -1 && i_des != -1)
    {
        int ariIn = encontrarArista(i_ori, i_des);
        if (ariIn != -1)
        {
            vector<pair<int, V>> *aux = &aristas[i_ori];
            aux->erase(aux->begin() + ariIn);
            res = true;
        }
    }
    return res;
}


