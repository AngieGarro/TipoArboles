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

    void balancearAVL(); // Modifica la estructura del árbol de forma que quede balanceado.

    int nivelRecursivo(NodoAVL*); //Calcula la nivel de un Arbin
    int numHojasRecursivo(NodoAVL*);


    void rsd(NodoAVL*); // Modifica la estructura del árbol si fe = -2, y la raíz del sub árbol izq su fe = -1 ó 0

    void rdd(NodoAVL*); // Modifica la estructura del árbol si fe = -2, y la raíz del sub árbol der su fe = 1

    void rsi(NodoAVL*); // Modifica la estructura del árbol si fe = 2, y la raíz del sub árbol der su fe = 1 ó 0

    void rdi(NodoAVL*); // Modifica la estructura del árbol si fe = 2, y la raíz del sub árbol der su fe = -1


    //termina arbolAVL

    void insertarElemRecursivo(NodoAVL*, NodoAVL*, int, int); //Inserta un entero en el árbol ordenado.

    

    string inOrdenRecursivo(NodoAVL*); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

   
public:
    Arbin();

    NodoAVL* getRaiz() const;
    void setRaiz(NodoAVL* raiz);

    int getPeso() const;
    void setPeso(int peso);

    int pesoArbin(); //Calcula el número de elementos del Arbin
    NodoAVL* buscarNodo(NodoAVL*, int);
    bool existeElemento(int); // Retorna verdadero si el elemento existe, y falso caso contrario.
    bool esVacioArbin(); //Retorna si un Arbin es vacío o no

    bool insertarElem(int); //Inserta un entero en el árbol ordenado.

   
    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)
    
 //metodos ALBIN
    bool esHoja(int); //Dice si un Arbin es hoja o no
    int altura();
    bool esVacioAVL(); //Retorna si un Arbin es vacío o no
    int numHojas();
    int nivel(); //Calcula del nivel de un Arbin
    NodoAVL* buscarNodoDesbalance(NodoAVL*);
    //FIN METODOS ALBIN





};

