#pragma once

class NodoAVL {
private:
    int num;

    NodoAVL* izq;
    NodoAVL* der;


    //albin
    int fe;
    NodoAVL* padre;
    //albin
public:
    NodoAVL();

    NodoAVL(int num);

    int getNum() const;

    void setNum(int num);

    NodoAVL* getIzq() const;

    NodoAVL* getDer() const;

    void setIzq(NodoAVL* izq);

    void setDer(NodoAVL* der);

    int getFe() const;

    void setFe(int fe);

    NodoAVL* getPadre() const;

    void setPadre(NodoAVL* padre);


};
