// =========================================================================
// @author: Anderson Alvarado
// =========================================================================
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include "Grafo.h"

using namespace std;

int main()
{
    //Grafo Taller
    Grafo<string, int> f;
    f.insertarVertice("C1");
    f.insertarVertice("C2");
    f.insertarVertice("C3");
    f.insertarVertice("C4");

    f.insertarArista("C1","C2",2);
    f.insertarArista("C1","C4",3);
    f.insertarArista("C2","C1",6);
    f.insertarArista("C2","C3",5);
    f.insertarArista("C2","C4",2);
    f.insertarArista("C3","C1",3);
    f.insertarArista("C4","C2",5);
    f.insertarArista("C4","C3",6);

    //Grafo Clase Recorridos
    Grafo<char, int> g;
    g.insertarVertice('A');
    g.insertarVertice('B');
    g.insertarVertice('C');
    g.insertarVertice('D');
    g.insertarVertice('E');
    g.insertarVertice('F');
    g.insertarVertice('G');
    g.insertarVertice('H');
    g.insertarVertice('I');

    g.insertarArista('A','E',0);
    g.insertarArista('A','I',0);
    g.insertarArista('B','D',0);
    g.insertarArista('B','G',0);
    g.insertarArista('C','A',0);
    g.insertarArista('C','I',0);
    g.insertarArista('D','E',0);
    g.insertarArista('D','G',0);
    g.insertarArista('D','H',0);
    g.insertarArista('E','F',0);
    g.insertarArista('E','I',0);
    g.insertarArista('F','B',0);
    g.insertarArista('F','C',0);
    g.insertarArista('G','E',0);
    g.insertarArista('G','F',0);
    g.insertarArista('H','B',0);
    g.insertarArista('I','F',0);

    cout << "======================================================================== " << endl;
    cout << "\t\t@author: Anderson Alvarado"<<endl;
    cout << "======================================================================== " << endl;
    
    cout << "\nGRAFO DEL TALLER" << endl;
    f.imprimirGrafo();// mostrar grafo
    cout << endl;

    cout << "\nGRAFO DEL QUIZ CLASE DE RECORRIDOS" << endl;
    g.imprimirGrafo();
    cout << "Cantidad de vertices: " << g.cantVertices() << endl;
    cout << "\nRECORRIDO Plano" << endl;
    g.recorridoPlano();
    cout << "\nRECORRIDO BFS desde D" << endl;
    g.recorridoBFS('D');
    cout << "\nRECORRIDO DFS desde H" << endl;
    g.recorridoDFS('H');
    cout << "\n\nEliminar vertice A ";
    g.eliminarVertice('A');
    cout << "\n\nGrafo actual: " << endl;
    g.imprimirGrafo();// mostrar grafo actual
}