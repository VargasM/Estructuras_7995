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

   /* //Grafo Clase Recorridos
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
    g.insertarArista('I','F',0);*/

    // Grafo Quiz Clase Prim, Kruskal y Djikstra
    Grafo<int, int> h;
    h.insertarVertice(0);
    h.insertarVertice(1);
    h.insertarVertice(2);
    h.insertarVertice(3);
    h.insertarVertice(4);
    h.insertarVertice(5);
    h.insertarVertice(6);
    h.insertarVertice(7);

    h.insertarArista(0,1,5);
    h.insertarArista(0,4,9);
    h.insertarArista(0,7,8);
    h.insertarArista(1,2,12);
    h.insertarArista(1,3,15);
    h.insertarArista(1,7,4);
    h.insertarArista(2,3,3);
    h.insertarArista(2,6,11);
    h.insertarArista(3,6,9);
    h.insertarArista(4,5,4);
    h.insertarArista(4,6,20);
    h.insertarArista(4,7,5);
    h.insertarArista(5,2,1);
    h.insertarArista(5,6,13);
    h.insertarArista(7,2,7);
    h.insertarArista(7,5,6);


    cout << "======================================================================== " << endl;
    cout << "\t\t@author: Anderson Alvarado"<<endl;
    cout << "======================================================================== " << endl;
    
    cout << "\nGRAFO DEL TALLER" << endl;
    f.imprimirGrafo();// mostrar grafo
    /*cout << "\nAlgoritmo de Prim desde C1" << endl<< endl;
    int suma1 = f.prim("C1");
    cout << "\nSuma de pesos: " <<  suma1 << endl;
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
    g.imprimirGrafo();// mostrar grafo actual*/

    cout << "\n\nGrafo quiz clase Prim: " << endl;
    h.imprimirGrafo();// mostrar grafo actual
    cout << "\nAlgoritmo de Prim desde 0" << endl<< endl;
    int suma2 = h.prim(0);
    cout << "\nSuma de pesos: " <<  suma2 << endl;

    cout << "\n\nGrafo clase Kruskal: " << endl;
    h.imprimirGrafo();// mostrar grafo actual
    cout << "\nAlgoritmo de Kruskal" << endl<< endl;
    h.kruskal();
}