#pragma once
#include "PaginaB.h"
#include <stdlib.h>

class AB
{
protected:
	int orden;
	PaginaB* raiz;
public:
	AB()
	{
		orden = 0;
		raiz = NULL;
	};
	AB(int m)
	{
		orden = m;
		raiz = NULL;
	}
	bool arbolBvacio()
	{
		return raiz == NULL;
	}
	PaginaB* Oraiz() 
	{ 
		return raiz; 
	}
	void Praiz(PaginaB * r) 
	{ 
		raiz = r; 
	}
	int Oorden() 
	{ 
		return orden; 
	}
	void Porden(int ord) { 
		orden = ord; 
	}
	void crear() 
	{ 
		orden = 0; raiz = NULL; 
	}

	//TAD DEL ARBOL B
	PaginaB* buscar(tipoClave cl, int& n);
	void insertar(tipoClave cl);
	void eliminar(tipoClave cl);
	void escribir();
	void listarCreciente();

private:
	PaginaB* buscar(PaginaB* actual,tipoClave cl, int& n);
	bool buscarNodo(PaginaB*, tipoClave cl, int& k);
	PaginaB* insertar(PaginaB* raiz,tipoClave cl);

	bool empujar(PaginaB* actual, tipoClave cl, tipoClave& mediana, PaginaB*& nuevo);
	void meterPagina(PaginaB* actual, tipoClave cl, PaginaB* ramaDr, int k);
	void dividirNodo(PaginaB* actual, tipoClave& mediana, PaginaB*& nuevo, int pos);
	void escribir(PaginaB* r, int h);
	void inOrden(PaginaB* r);
};

