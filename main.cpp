#include <iostream>
	#include "Grafo.h"
	

	using namespace std;
	

	typedef Grafo <char,int> Tgrafo;
	

	int menu();
	

	int main()
	{
	

	    Tgrafo grafo;
	    int opcion = 0;
	

	    char vert,ori,des;
	

	    /*
	    VERTICES:
	    C1 = A
	    C2 = B
	    C3 = C
	    C4 = D
	    */
	

	    grafo.insertarVertice('A');
	    grafo.insertarVertice('B');
	    grafo.insertarVertice('C');
	    grafo.insertarVertice('D');
	    grafo.insertarArista('A','B',2);
	    grafo.insertarArista('A','D',3);
	    grafo.insertarArista('B','A',6);
	    grafo.insertarArista('B','C',5);
	    grafo.insertarArista('B','D',2);
	    grafo.insertarArista('C','A',3);
	    grafo.insertarArista('D','B',5);
	    grafo.insertarArista('D','C',6);
	

	    while(opcion!= 7)
	    {
	        opcion = menu();
	        if (opcion == 1)
	        {
	            cout << "cantidad de vertices: " << grafo.cantVertices() << endl;
	        }
	        else if (opcion == 2)
	        {
	            cout << "cantidad de Aristas: " <<  grafo.cantAristas () << endl;
	        }
	        else if (opcion == 3)
	        {
	            cout << "ingrese Vertice ";
	            cin >>vert;
	            cout << "vertice encontrada: " << grafo.buscarVertices(vert) << endl;
	        }
	        else if (opcion == 4)
	        {
	            cout << "ingrese ori";
	            cin >>ori;
	            cout << "ingrese des";
	            cin >>des;
	            cout << "arista encontrada: " << grafo.buscarArista(ori,des) << endl;
	        }
	        else if (opcion == 5)
	        {
	            cout << "ingrese vertice a eliminar: ";
	            cin >> vert;
	            cout << "verice eliminada : " << grafo.eliminarVertice(vert)<< endl;
	        }
	        else if (opcion == 6)
	        {
	            cout << "ingrese ori";
	            cin >>ori;
	            cout << "ingrese des";
	            cin >>des;
	            cout << "arista eliminada : " << grafo.eliminarArista(ori,des) << endl;
	        }
	    }
	

	    return 0;
	}
	

	

	int menu()
	{
	    int opcion;
	

	    cout << "\n\n\t MENU" << endl;
	    cout << "cantVertices..........1" << endl;
	    cout << "cantAristas...........2" << endl;
	    cout << "buscarVertices........3" << endl;
	    cout << "buscarArista..........4" << endl;
	    cout << "eliminarVertice.......5" << endl;
	    cout << "eliminarArista........6" << endl;
	    cout << "Salir.................7" << endl;
	

	    cout << "Ingrese Opcion: ";
	    cin >> opcion;
	

	    return opcion;
	}

