#include "NodoAVL.h"

NodoAVL::NodoAVL() {
    num = 0;
    fe = 0;
    padre = nullptr;
    setDer(nullptr);
    setIzq(nullptr);
}

NodoAVL::NodoAVL(int num) {
    setNum(num);
    setDer(nullptr);
    setIzq(nullptr);
    num = 0;
    fe = 0;
    padre = nullptr;
}


int NodoAVL::getNum() const {
    return num;
}

void NodoAVL::setNum(int num) {
    NodoAVL::num = num;
}

NodoAVL* NodoAVL::getIzq() const {
    return izq;
}

NodoAVL* NodoAVL::getDer() const {
    return der;
}

void NodoAVL::setIzq(NodoAVL* izq) {
    NodoAVL::izq = izq;
}

void NodoAVL::setDer(NodoAVL* der) {
    NodoAVL::der = der;
}

int NodoAVL::getFe() const {
    return fe;
}

void NodoAVL::setFe(int fe) {
    NodoAVL::fe = fe;
}

NodoAVL* NodoAVL::getPadre() const {
    return padre;
}

void NodoAVL::setPadre(NodoAVL* padre) {
    NodoAVL::padre = padre;
}
