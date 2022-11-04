#pragma once
#include"Arbin.h"


class GestorAVL {

private:
    Arbin* arbol;
public:
    GestorAVL();

    Arbin* getArbol() const;

    void setArbol(Arbin* arbol);

    bool insertarElem(int); //Inserta un entero en el �rbol ordenado.

    int pesoArbin(); //Calcula el n�mero de elementos del Arbin

    bool esVacioArbin(); //Retorna si un Arbin es vac�o o no

   

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - ra�z - derecha)


};

