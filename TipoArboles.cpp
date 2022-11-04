// TipoArboles.cpp : This file contains the 'main' function. Interface
//

#include <iostream>
#include <stdlib.h>
#include "ABB.h"
#include "AB.h"
#include "NodoA.h"

using namespace std;

//ARBOL BINARIO DE BUSQUEDA
//SUB-MENU
void agregarDato(ABB*& A) {
    cout << "Agregando un nuevo dato al arbol " << endl;
    cout << "Digite el valor ";
    int dato;
    cin >> dato;
    if (A->agregar(dato))
        cout << "Se ha agregado exitosamente el valor " << dato << " al arbol." << endl;
    else
        cout << dato << " ya existe en el arbol." << endl;
}

void menu() {
    int opc = 0;
    ABB* A = new ABB();
    AB* B = new AB();
    do {
        system("cls");
        cout << "----------------INVESTIGACION ARBOLES-----------------\n";
        cout << "______________________________________________________ \n";
        cout << "(1) ARBOLES B \n";
        cout << "(2) ARBOLES B+ \n";
        cout << "(3) ARBOLES AVL \n";
        cout << "(4) ARBOLES ROJO - NEGRO \n";
        cout << "(0) Salir del menu \n";
        cout << endl;
        cout << "Ingrese su opcion->";
        cin >> opc;
        switch (opc) {
        case 1: {
            cout << "Arboles B..." << endl;
            break;
        }
        case 2: {
            cout << "Arboles B+..." << endl;
            
            break;
        }
        case 3: {
            cout << "Arboles AVL..." << endl;
            
            break;
        }
        case 4: {
            cout << "Arboles ROJO - NEGRO..." << endl;
            
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
