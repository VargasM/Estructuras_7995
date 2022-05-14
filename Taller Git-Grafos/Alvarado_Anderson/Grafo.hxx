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
        cout << vertices[i] << " -> ";
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
int Grafo<T, C>::prim(T vOrigen)
{
    
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
// algoritmo de kruskal
template <class T, class C>
void Grafo<T, C>::kruskal()
{
    if(cantVertices()>0)
    {
        int cant = cantVertices(); // cantidad de arboles
        int pos = 0; //posicion
        vector <pair<int, pair <int,int>>> lista; // vector de aristas {a,{b,c}}: a = peso, b = v origen, c = v destino
        
        for(int i = 0; i<cantVertices(); i++) //llenar la lista de aristas
        {
            vector<pair<int, int>> aux = aristas[i];
            for(int j = 0; j<aux.size(); j++)
            {
                pair<int, C> temp = aux[j];
                lista.push_back ({temp.second,{i,temp.first}});
            }
        }
        sort(lista.begin(),lista.end());// ordenar la lista por aristas segun el peso
        /*for(int k =0; k< lista.size();k++ ){ // ver la lista de aristas ordenada por pesos
            pair<int, pair <int,int>> curr = lista [k];
            cout << "Peso: " << curr.first << ", arista: (" << curr.second.first << ", " << curr.second.second << ") " << endl;
        }*/
        vector <int> v; // vector con el arbol de recubrimiento minimo;
        v.resize(cantVertices());
        iniciar(v);

        while(cant != 1 && pos < cantAristas())
        {
            pair<int, pair <int,int>> curr = lista [pos];
            if(encontrar(v,curr.second.first) != encontrar(v,curr.second.second))
            {
                cout << "Peso: " << curr.first << ", arista: (" << curr.second.first << ", " << curr.second.second << ") " << endl;
                unir(v, curr.second.first, curr.second.second);
                cant--;
            }
            pos++;   
        }
    }    
    else
        cout << "El grafo no tiene ningun vertice" << endl;
}
//inicializar el vector que contiene el arbol de recubrimiento minimo
template <class T, class C>
void Grafo<T, C>::iniciar(vector<int> &v)
{
    for(int i = 0; i<cantVertices(); i++)
        v[i] = i;  
}
//encontrar arbol
template <class T, class C>
int Grafo<T, C>::encontrar(vector <int> &v, int &a)
{
    if(a == v[a])
        return a;

    return v[a] = encontrar (v, v[a]);
} 
//unir dos arboles
template <class T, class C>
void Grafo<T, C>::unir(vector <int> &v,int &a, int &b)
{
    a = encontrar(v,a);
    b = encontrar(v,b);
    v[b] = a;
} 
// algoritmo de Dijkstra
template <class T, class C>
void Grafo<T, C>::dijkstra(T vOrigen)
{
    int nodo = buscarVertice(vOrigen);

    if (nodo != -1)
    {    
        map <T,map< T, int>> matriz; // matriz  de los caminos 
        map <T,bool> visitados; // mapa de los vertices ya visitados
        map <T,T> pred; // mapa de los predecesores del vertice
        map <T,int> Q; // vertices pendientes por procesar
        map <T,int> dist; //distancias minimas 
    }
    else
        cout << "El vertice no existe" << endl;
}