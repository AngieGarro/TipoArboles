#pragma once
#include"Arbin.h"


class GestorAVL {

private:
    Arbin* arbol;
public:
    GestorAVL();

    Arbin* getArbol() const;

    void setArbol(Arbin* arbol);

    bool insertarElem(int); //Inserta un entero en el árbol ordenado.

    int pesoArbin(); //Calcula el número de elementos del Arbin

    bool esVacioArbin(); //Retorna si un Arbin es vacío o no

   

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)


};

