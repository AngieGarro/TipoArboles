#include "GestorAVL.h"


GestorAVL::GestorAVL() {
    arbol = new Arbin();
}

Arbin* GestorAVL::getArbol() const {
    return arbol;
}

bool GestorAVL::insertarElem(int pValor) {
    return arbol->insertarElem(pValor);
}

int GestorAVL::pesoArbin() {
    return arbol->getPeso();
}

bool GestorAVL::esVacioArbin() {
    return arbol->esVacioArbin();
}

void GestorAVL::setArbol(Arbin* arbol) {
    GestorAVL::arbol = arbol;
}



string GestorAVL::inOrden() {
    string inOrden = arbol->inOrden();
    inOrden = inOrden.substr(0, inOrden.length() - 3);
    return inOrden;
}


