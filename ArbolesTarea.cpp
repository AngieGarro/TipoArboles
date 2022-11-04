// arbolesTarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
#include "AB.h"
#include "RBTree.h"
#include "Arbin.h"
#include "arbol.h"
using namespace std;



void agregarDato(AB*& A) {
    cout << "Agregando un nuevo dato al árbol " << endl;
    cout << "Digite el valor ";
    int dato;
    cin >> dato;
   // if (A->insertar(dato))
    //    cout << "Se ha agregado exitosamente el valor " << dato << " al arbol." << endl;
   // else
    //    cout << dato << " ya existe en el arbol." << endl;
}


void menu() {
    int opc = 0;
    AB* A = new AB();
    RBTree RBT;
    Arbin TAVL;
    Arbol ABplus(10);

    do {
        system("cls");
        cout << "OPERACIONES ARBOLES BINARIOS!\n";
        cout << "-----------------------------\n";
        cout << "Arbol Rojo-Negro\n";
        cout << "(1) Agregar dato al arbol \n";
        cout << "(2) Imprimir Orden \n";
        cout << "(3) Imprimir PreOrden \n";

        cout << "-----------------------------\n";
        cout << "Arbol AVL\n";
        cout << "(11) Agregar dato al arbol \n";
        cout << "(12) Imprimir Orden \n";
        cout << "(13) Imprimir PreOrden \n";

        cout << "-----------------------------\n";
        cout << "Arbol B\n";
        cout << "(21) Agregar dato al arbol \n";
        cout << "(22) Imprimir Orden \n";
        cout << "(23) Imprimir PreOrden \n";

        cout << "-----------------------------\n";
        cout << "Arbol B+\n";
        cout << "(31) Agregar mensaje arbol b+ \n";
        cout << "(32) Imprimir arbol b+ \n";
        cout << "(33) borrar arbol b+ \n";
        cin >> opc;

        switch (opc) {
        case 1: {
            cout << "Agregando un nuevo dato al árbol Rojo-Negro " << endl;
            cout << "Digite el valor ";
            int dato;
            cin >> dato;
            RBT.insert(dato);
            break;
        }

        case 2: {
            cout << "Arbol Rojo Negro en orden " << endl;
            RBT.in_order();

            break;
        }
        case 3: {
            cout << "Arbol Rojo Negro en preOrden " << endl;
            TAVL.numHojas();
            break;
        }

        case 11: {
            cout << "Agregando un nuevo dato al árbol AVL " << endl;
            cout << "Digite el valor ";
            int dato;
            cin >> dato;
            TAVL.insertarElem(dato);
            break;
        }

        case 12: {
            cout << "Arbol AVL en orden " << endl;
            cout << TAVL.inOrden();
            break;
        }
        case 13: {
            cout << "Hojas de árbol AVL " << endl;
            cout << TAVL.numHojas();
            break;
        }

        case 21: {
            agregarDato(A);
            break;
        }

        case 22: {
            cout << "Arbol B en orden " << endl;
            A->escribir();
            break;
        }
        case 23: {
            cout << "Arbol B en preOrden " << endl;
            A->listarCreciente();
            break;
        }


        case 31: {
            cout << "Agregando un nuevo mensaje al árbol B+ " << endl;
            cout << "Digite el mensaje ";
            string dato;
            cin >> dato;
            ABplus.lecturaLlaves(dato);
            break;
        }

        case 32: {
            cout << "Arbol B+ en orden " << endl;
            ABplus.pintar();
            break;
        }
        case 33: {
            cout << "Digite el mensaje ";
            string dato;
            cin >> dato;
            ABplus.borradoLlaves(dato);
            break;
        }


        }
        system("pause");
    } while (opc != 0);

}


int main()
{
    
    menu();
}
