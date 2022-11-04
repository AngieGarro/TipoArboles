
#include <iostream>
#include "Arbin.h"

Arbin::Arbin() {
    setPeso(0);
    setRaiz(nullptr);

}

void Arbin::insertarFE(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return;
    }
    else if (esHoja(nodo->getNum())) {
        nodo->setFe(0);
    }
    else {
        insertarFE(nodo->getIzq());
        insertarFE(nodo->getDer());
        nodo->setFe(alturaFE(nodo->getDer()) - alturaFE(nodo->getIzq()));
    }
}
NodoAVL* Arbin::buscarNodo(NodoAVL* nodo, int pValor) {
    if (nodo == nullptr) {
        return nullptr;
    }
    else {
        if (nodo->getNum() == pValor) {
            return nodo;
        }
        else if (nodo->getNum() > pValor) {
            return buscarNodo(nodo->getIzq(), pValor);
        }
        else {
            return buscarNodo(nodo->getDer(), pValor);
        }
    }
}


bool Arbin::existeElemento(int pValor) {
    if (getPeso() == 0) {
        return false;
    }
    else {
        NodoAVL* aux = buscarNodo(getRaiz(), pValor);
        if (aux == nullptr) {
            return false;
        }
        else {
            return true;
        }

    }
}

NodoAVL* Arbin::getRaiz() const {
    return raiz;
}

void Arbin::setRaiz(NodoAVL* raiz) {
    Arbin::raiz = raiz;
}

int Arbin::getPeso() const {
    return peso;
}

void Arbin::setPeso(int peso) {
    Arbin::peso = peso;
}

int Arbin::pesoArbin() {
    return getPeso();
}

bool Arbin::esVacioArbin() {
    if (getPeso() == 0) {
        return true;
    }
    else {
        return false;
    }
}

void Arbin::insertarElemRecursivo(NodoAVL* nodoRaiz, NodoAVL* nodoHijo, int pValor, int tipo) {
    if (nodoRaiz == nullptr) {
        nodoRaiz = new NodoAVL(pValor);
        if (getPeso() == 0) {
            setRaiz(nodoRaiz);
        }
        else if (tipo == 1) {
            nodoHijo->setIzq(nodoRaiz);
        }
        else if (tipo == 2) {
            nodoHijo->setDer(nodoRaiz);
        }
        setPeso(getPeso() + 1);
    }
    else if (pValor < nodoRaiz->getNum()) {
        insertarElemRecursivo(nodoRaiz->getIzq(), nodoRaiz, pValor, 1);
    }
    else if (pValor > nodoRaiz->getNum()) {
        insertarElemRecursivo(nodoRaiz->getDer(), nodoRaiz, pValor, 2);
    }
}

bool Arbin::insertarElem(int pValor) {

    bool existe = existeElemento(pValor);

    if (!existe) {
        insertarElemRecursivo(getRaiz(), new NodoAVL(), pValor, 0);

        insertarFE(getRaiz());
        balancearAVL();

        return true;


    }
    else {
        return false;
    }

    return true;
}


string Arbin::inOrden() {
    return inOrdenRecursivo(getRaiz());
}

string Arbin::inOrdenRecursivo(NodoAVL* nodo) {
    string inOrden;
    if (nodo != nullptr) {
        inOrden = inOrdenRecursivo(nodo->getIzq());
        inOrden += to_string(nodo->getNum()) + " - ";
        inOrden += inOrdenRecursivo(nodo->getDer());
    }
    return inOrden;
}




//METODOS AVL 


NodoAVL* Arbin::buscarNodoDesbalance(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return nullptr;
    }
    else {
        if ((nodo->getFe() == 2 &&
            (nodo->getDer()->getFe() == 0 || nodo->getDer()->getFe() == 1 || nodo->getDer()->getFe() == -1)) ||
            nodo->getFe() == -2 &&
            (nodo->getIzq()->getFe() == 0 || nodo->getIzq()->getFe() == 1 || nodo->getIzq()->getFe() == -1)) {
            return nodo;
        }
        else {
            buscarNodoDesbalance(nodo->getIzq());
            return buscarNodoDesbalance(nodo->getDer());
        }
    }
}


void Arbin::rsd(NodoAVL* nodo) {
    NodoAVL* p = nodo;
    NodoAVL* q = nodo->getIzq();
    NodoAVL* b = q->getDer();
    NodoAVL* padre = nodo->getPadre();
    p->setIzq(b);
    if (b != nullptr) {
        b->setPadre(p);
    }
    q->setDer(p);
    p->setPadre(q);
    if (nodo == getRaiz()) {
        setRaiz(q);
        q->setPadre(nullptr);
    }
    else {

        if (padre->getDer() == nodo) {
            padre->setDer(q);
        }
        else {
            padre->setIzq(q);
        }
        q->setPadre(padre);
    }
}

void Arbin::rdd(NodoAVL* nodo) {
    NodoAVL* p = nodo;
    NodoAVL* q = nodo->getIzq();
    NodoAVL* r = q->getDer();
    NodoAVL* c = r->getDer();
    NodoAVL* b = r->getIzq();
    NodoAVL* padre = nodo->getPadre();
    p->setIzq(c);
    if (c != nullptr) {
        c->setPadre(p);
    }
    r->setDer(p);
    p->setPadre(r);
    r->setIzq(q);
    q->setPadre(r);
    q->setDer(b);
    if (b != nullptr) {
        b->setPadre(q);
    }
    if (nodo == getRaiz()) {
        setRaiz(r);
        r->setPadre(nullptr);
    }
    else {
        if (padre->getDer() == nodo) {
            padre->setDer(r);
        }
        else {
            padre->setIzq(r);
        }
        r->setPadre(padre);
    }
}

void Arbin::rsi(NodoAVL* nodo) {
    NodoAVL* p = nodo;
    NodoAVL* q = nodo->getDer();
    NodoAVL* b = p->getDer()->getIzq();
    NodoAVL* padre = nodo->getPadre();
    p->setDer(b);
    if (b != nullptr) {
        b->setPadre(p);
    }
    q->setIzq(p);
    p->setPadre(q);
    if (nodo == getRaiz()) {
        setRaiz(q);
        q->setPadre(nullptr);
    }
    else {
        if (padre->getDer() == nodo) {
            padre->setDer(q);
        }
        else {
            padre->setIzq(q);
        }
        q->setPadre(padre);
    }
}

void Arbin::rdi(NodoAVL* nodo) {
    NodoAVL* p = nodo;
    NodoAVL* q = nodo->getDer();
    NodoAVL* r = q->getIzq();
    NodoAVL* c = r->getDer();
    NodoAVL* b = r->getIzq();
    NodoAVL* padre = nodo->getPadre();
    p->setDer(b);
    if (b != nullptr) {
        b->setPadre(p);
    }
    r->setDer(q);
    q->setPadre(r);
    r->setIzq(p);
    p->setPadre(r);
    q->setIzq(c);
    if (c != nullptr) {
        c->setPadre(q);
    }
    if (nodo == getRaiz()) {
        setRaiz(r);
        r->setPadre(nullptr);
    }
    else {

        if (padre->getDer() == nodo) {
            padre->setDer(r);
        }
        else {
            padre->setIzq(r);
        }
        r->setPadre(padre);
    }
}



void Arbin::balancearAVL() {
    NodoAVL* aux = buscarNodoDesbalance(getRaiz());
    if (aux != nullptr) {
        if (aux->getFe() == 2 && aux->getDer()->getFe() == -1) {
            rdi(aux);
            insertarFE(getRaiz());
        }
        else if (aux->getFe() == 2 && aux->getDer()->getFe() == 1 ||
            aux->getFe() == 2 && aux->getDer()->getFe() == 0) {
            rsi(aux);
            insertarFE(getRaiz());
        }
        else if (aux->getFe() == -2 && aux->getIzq()->getFe() == 1) {
            rdd(aux);
            insertarFE(getRaiz());
        }
        else if (aux->getFe() == -2 && aux->getIzq()->getFe() == -1 ||
            aux->getFe() == -2 && aux->getIzq()->getFe() == 0) {
            rsd(aux);
            insertarFE(getRaiz());
        }
    }
}


int Arbin::nivelRecursivo(NodoAVL* nodo) {
    int a, b;
    if (nodo == nullptr) {
        return -1;
    }
    else {
        a = nivelRecursivo(nodo->getIzq());
        b = nivelRecursivo(nodo->getDer());
        if (a > b) {
            return a + 1;
        }
        else {
            return b + 1;
        }
    }
}


int Arbin::numHojasRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    else {
        if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr) {
            return 1;
        }
        else {
            return numHojasRecursivo(nodo->getIzq()) + numHojasRecursivo(nodo->getDer());
        }
    }
}


int Arbin::nivel() {
    return nivelRecursivo(getRaiz());
}

int Arbin::numHojas() {
    return numHojasRecursivo(getRaiz());
}
int Arbin::alturaFE(NodoAVL* nodo) {
    int altura = nivelRecursivo(nodo);
    return  altura + 1;
}
int Arbin::altura() {
    return nivel() + 1;
}
bool Arbin::esHoja(int pValor) {
    if (getRaiz() == nullptr) {
        return false;
    }
    else {
        NodoAVL* nodo = buscarNodo(getRaiz(), pValor);
        if (nodo == nullptr) {
            return false;
        }
        else if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
}

