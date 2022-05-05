// =========================================================================
// @author: Anderson Alvarado
// =========================================================================
#include "Grafo.h"

// cantidad de vertices en el grafo
template <class T, class C>
int Grafo<T, C>::cantVertices()
{
    return vertices.size();
}
// cantidad de aristas en el grafo
template <class T, class C>
int Grafo<T, C>::cantAristas()
{
    int suma = 0;
    //vector<pair<int, C>> temp;

    for (int i = 0; i <vertices.size(); ++i)
    {
        //temp = aristas[i];
        suma += aristas[i].size();
    }
    return suma;
}
//Buscar un vertice dado en el grafo
template <class T, class C>
int Grafo<T, C>::buscarVertice(T vertice)
{
    int indice = -1;
    for (int i = 0; i < cantVertices(); i++)
    {
        if (vertice == vertices[i])
            indice = i;
    }
    return indice;
}
//Insertar un nuevo vertice
template <class T, class C>
bool Grafo<T, C>::insertarVertice(T vertice)
{
    bool insertado = false;
    if (vertices.size() == 0 || buscarVertice(vertice) == -1)
    {
        this->vertices.push_back(vertice);
        //vector< pair< int, C >>  *aux = new vector < pair < int, C >>;
        vector<pair<int, C>> aux;
        this->aristas.push_back(aux);
        insertado = true;
    }
    return insertado;
}
// eliminar un vertice dado en el grafo
template <class T, class C>
void Grafo<T, C>::eliminarVertice(T vertice)
{
    int ver = buscarVertice(vertice);
    if (ver != -1)
    {
        vector<pair<int, C>> *aux = &aristas[ver];
        aux->clear();
        aristas.erase(aristas.begin() + ver);
        for (int i = 0; i < aristas.size(); i++)
        {
            aux = &aristas[i];
            for (int j = 0; j < aux->size(); j++)
            {
                pair<int, C> temp = (*aux)[j];
                if (temp.first == ver)
                {
                    aux->erase(aux->begin() + j);
                }
            }
            // eliminarArista(vertice,vertices[i]);
        }
        vertices.erase(vertices.begin() + ver);
    }
}
// buscar si una arista se encuentra entre el vertice de origen y destino
template <class T, class C>
int Grafo<T, C>::buscarArista(int origen, int destino)
{
    int encontrado = -1;
    vector<pair<int, C>> aux = aristas[origen];
    for (int i = 0; i < aux.size(); i++)
    {
        pair<int, C> temp = aux[i];
        if (temp.first == destino)
            encontrado = i;
    }
    return encontrado;
}
//insertar una arista entre dos vertices del grafo
template <class T, class C>
bool Grafo<T, C>::insertarArista(T origen, T destino, C peso)
{
    bool insertada = false;
    int ori = buscarVertice(origen);
    int des = buscarVertice(destino);
    if (ori != -1 && des != -1)
    {
        if (buscarArista(ori, des) == -1)
        {
            vector<pair<int, C>> *aux = &aristas[ori];
            pair<int, C> nAri(des, peso);
            aux->push_back(nAri);
            insertada = true;
        }
    }
    return insertada;
}
// eliminar una arista entre dos vertice en el grafo
template <class T, class C>
bool Grafo<T, C>::eliminarArista(T origen, T destino)
{
    bool res = false;
    int ori = buscarVertice(origen);
    int des = buscarVertice(destino);
    if (ori != -1 && des != -1)
    {
        int ariIn = buscarArista(ori, des);
        if (ariIn != -1)
        {
            vector<pair<int, C>> *aux = &aristas[ori];
            aux->erase(aux->begin() + ariIn);
            res = true;
        }
    }
    return res;
}
/*template <class T, class C>
bool eliminarArista(T origen, T destino) {
		bool res = false;
		int ori = buscarVertice(origen);
		int des = buscarVertice(destino);
        int posE = 0, i = 0;
		if ( ori != -1 && des != -1 ) {
			//std::vector<std::pair<int, C>>::iterator it, posE;
            vector<pair<int, C>> aux = aristas[ori];
			for (; i != aux.size(); i++) 
            {
				if (aux.first == des)  
                    posE = i;
			}
			aux.erase(posE);
            res = true;
		}
		return res;
}*/
//Impresion del Grafo
template <class T, class C>
void Grafo<T, C>::imprimirGrafo()
{
    cout << endl;
    for (int i = 0; i < cantVertices(); ++i)
    {
        cout << vertices[i] << "-> ";
        vector<pair<int, C>> aux = aristas[i];
        for (int j = 0; j < aux.size(); j++)
        {
            pair<int, C> temp = aux[j];
            cout << vertices[temp.first] << " " << temp.first << " " << temp.second << ", ";
        }
        cout << endl;
    }
    cout << endl;
}
//Recorrido plano del grafo
template <class T, class C>
void Grafo<T, C>::recorridoPlano()
{
    for (int i = 0; i < cantVertices(); i++)
    {
        cout << vertices[i] << ", ";
    }
    cout << endl;
}
// Recorrido en profundidad DFS del grafo
template <class T, class C>
void Grafo<T, C>::recorridoDFS(T inicio)
{
    bool *visitados = new bool [cantVertices()];
    int indice = buscarVertice(inicio);
    if (indice != -1)
    {
        for(int i=0; i<cantVertices(); i++)
            visitados[i] = false;

        recorridoDFS(indice, visitados);
    }    
    else
        cout << "El vertice no existe" << endl;
}
template <class T, class C>
void Grafo<T, C>::recorridoDFS(int indice, bool *visitados)
{
    cout << vertices[indice] << ", ";
    visitados[indice] = true;
    vector<pair<int, C>> aux = aristas[indice];
 
    for (int i = 0; i < aux.size(); ++i)
    {
        pair<int, C> temp = aux[i];
        if (!visitados[temp.first])
            recorridoDFS(temp.first, visitados);     
    }
}
// Recorrido en anchura BFS del grafo
template <class T, class C>
void Grafo<T, C>::recorridoBFS(T vOrigen)
{
    int nodo = buscarVertice(vOrigen);
    
    if (nodo != -1)
    {
        bool *visitados = new bool [cantVertices()];
        queue<int> colaV;
        colaV.push(nodo);

        for(int i=0; i<cantVertices(); i++)
            visitados[i] = false;

        while (!colaV.empty())
        {
            nodo = colaV.front();
            colaV.pop();

            if (!visitados[nodo])
            {
                cout << vertices[nodo] << ", ";
                visitados[nodo] = true;

                vector<pair<int, C>> aux = aristas[nodo];
                for (int i = 0; i < aux.size(); ++i)
                {
                    pair<int, C> temp = aux[i];
                    colaV.push(temp.first);
                }
            }
        }
    }
    else
        cout << "El vertice no existe" << endl;
}
// algoritmo de prim
template <class T, class C>
int Grafo<T, C>::prim(T vOrigen){
    
    int suma = 0;
    int nodo = buscarVertice(vOrigen);
    

    if (nodo != -1)
    {    
        vector <bool> visitados;
        visitados.resize(cantVertices());

        struct compare {
	        public: 
	            bool operator()(pair<int, int> x, pair<int, int>y)
                {
                    return x.first > y.first;
                }
        };
        priority_queue<pair<int, int>, vector <pair<int, int>>, compare> cola; //  costo,  indice vertice
        cola.push({0,nodo});

        while(!cola.empty())
        {
            pair<int, int> curr =  cola.top();
            cola.pop();
            if(!visitados[curr.second])
            {
                cout <<  "vertice: "<< vertices[curr.second] << ", peso: " << curr.first<<endl;

                visitados[curr.second] = true;
                suma += curr.first;

                vector<pair<int, int>> aux = aristas[curr.second];
                for(int j = 0; j<aux.size(); ++j)
                {
                    pair<int, C> temp = aux[j];
                    cola.push({temp.second, temp.first});
                }    
            }   
        }
    }
    else
        cout << "El vertice no existe" << endl;

    return suma;
}