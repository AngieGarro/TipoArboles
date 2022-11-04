#pragma once
#include <string>
using namespace std;

#include "NodoAVL.h"

class Arbin {
private:
    NodoAVL* raiz;
    int peso;

    //empiezaARBOL AVL
    int alturaFE(NodoAVL*);

    void insertarFE(NodoAVL*); // Inserta el factor de equilibrio en cada nodo.

    void balancearAVL(); // Modifica la estructura del �rbol de forma que quede balanceado.

    int nivelRecursivo(NodoAVL*); //Calcula la nivel de un Arbin
    int numHojasRecursivo(NodoAVL*);


    void rsd(NodoAVL*); // Modifica la estructura del �rbol si fe = -2, y la ra�z del sub �rbol izq su fe = -1 � 0

    void rdd(NodoAVL*); // Modifica la estructura del �rbol si fe = -2, y la ra�z del sub �rbol der su fe = 1

    void rsi(NodoAVL*); // Modifica la estructura del �rbol si fe = 2, y la ra�z del sub �rbol der su fe = 1 � 0

    void rdi(NodoAVL*); // Modifica la estructura del �rbol si fe = 2, y la ra�z del sub �rbol der su fe = -1


    //termina arbolAVL

    void insertarElemRecursivo(NodoAVL*, NodoAVL*, int, int); //Inserta un entero en el �rbol ordenado.

    

    string inOrdenRecursivo(NodoAVL*); // Imprime el Arbin de forma IRD (izquierda - ra�z - derecha)

   
public:
    Arbin();

    NodoAVL* getRaiz() const;
    void setRaiz(NodoAVL* raiz);

    int getPeso() const;
    void setPeso(int peso);

    int pesoArbin(); //Calcula el n�mero de elementos del Arbin
    NodoAVL* buscarNodo(NodoAVL*, int);
    bool existeElemento(int); // Retorna verdadero si el elemento existe, y falso caso contrario.
    bool esVacioArbin(); //Retorna si un Arbin es vac�o o no

    bool insertarElem(int); //Inserta un entero en el �rbol ordenado.

   
    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - ra�z - derecha)
    
 //metodos ALBIN
    bool esHoja(int); //Dice si un Arbin es hoja o no
    int altura();
    bool esVacioAVL(); //Retorna si un Arbin es vac�o o no
    int numHojas();
    int nivel(); //Calcula del nivel de un Arbin
    NodoAVL* buscarNodoDesbalance(NodoAVL*);
    //FIN METODOS ALBIN





};

