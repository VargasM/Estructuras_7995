#include "TADGRAFOSACTUALIZADOS.h"
#include <iostream>

using namespace std;

int main()
{

    int opcion,opcion2;
    int nodoA,nodoB;
    Grafo<int,int> G;
    int valor;
    int nodoBuscar;
    int v1, v2;
    int vErase;
    int esta;

    do
    {
        cout << endl;
        cout << "\nMENU\n";
        cout << "1) Crear grafo\n"; // grafo vacío
        cout << "2) Insertar nodo \n";
        cout << "3) Insertar arista \n";
        cout << "4) Eliminar Nodo \n";
        cout << "5) Eliminar arista \n";
        cout << "6) buscar nodo \n";
        cout << "7) buscar arista \n";
        cout << "8) ver cantidad de vertices \n";
        cout << "9) ver cantidad de aristas \n";
        cout << "10) SALIR\n";
        cout << "\nIngrese la opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                G.crearGrafo();
                break;
            case 2:
                cout << "- Inserte el valor de nodo: ";
                cin >> valor;
                G.insertarVertice(valor);
                break;
            case 3:
                cout << "- Ingrese primer nodo: ";
                cin >> v1;
                cout << "- Ingrese segundo nodo: ";
                cin >> v2;
                G.insertarArista(v1,v2,0);
                break;
            case 4:
                cout << "- Ingrese el nodo a eliminar: ";
                cin >> vErase;
                G.eliminarVertice(vErase);
                break;
            case 5:
                cout << "- Ingrese nodo de la arista a eliminar: ";
                cin >> nodoA;
                cout << "- Ingrese segundo nodo de la arsita a eliminar: ";
                cin >> nodoB;
                G.eliminarArista(nodoA,nodoB);
            case 6:
                int aux;
                cout << "- Ingrese nodo a buscar: ";
                cin >> nodoBuscar;
                aux = G.encontrarVertice(nodoBuscar);
                if (aux != -1)
                    cout << "Se encontro el nodo" << endl;
                else
                    cout << "No existe el nodo" << endl;
                break;
            case 7:
                cout << "Ingrese nodo origen de la arista a buscar: ";
                cin >> nodoA;
                cout << "Ingrese nodo destino de la arista a buscar: ";
                cin >> nodoB;

                esta = G.encontrarArista(nodoA,nodoB);

                if (esta != -1)
                    cout << "Se encontro la arista en el indice " << esta << "." << endl;
                else
                    cout << "No se encontro la arista." << endl;

                break;
            case 8:
                cout << "- Cantidad de vertices: " << G.cantidadVertices() << endl;
                break;
            case 9:
                cout << "- Cantidad de aristas: " << G.cantidadAristas() << endl;
                break;
            case 10:
                cout << endl;
                cout << "\n- Seguro que quiere salir?(SI=1)(NO=0) :";
                cin >> opcion2;
                cout << endl;
                if (opcion2 == 1)
                    opcion = 0;
                else if (opcion2 == 0)
                    break;
        }
    } while (opcion != 0);

}