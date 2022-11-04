#pragma once
#include <stdlib.h>
#include "iostream";

typedef int tipoClave;
class PaginaB;
typedef PaginaB * BPagina;

class PaginaB
{
protected:
	tipoClave * claves; // puntero array de claves variables
	BPagina * ramas; // puntero array de punteros a páginas variable
	int cuenta; // número de claves que almacena la página
private:
	int m; //máximo número de claves que puede almacenar la página
public:
	// crea una página vacía de un cierto orden dado
	PaginaB(int orden)
	{
		m = orden;
		claves = new tipoClave[orden];
		ramas = new BPagina[orden];
		for (int k = 0; k <= orden; k++)
			ramas[k] = NULL;
	}

	// decide si un nodo está lleno
	bool nodoLLeno()
	{
		return (cuenta == m - 1);
	}
	// decide si una página tiene menos de la mitad de claves
	bool nodoSemiVacio()
	{
		return (cuenta < m / 2);
	}
	// obtener la clave que ocupa la posición i en el array de claves
	tipoClave Oclave(int i) 
	{ 
		return claves[i]; 
	}
	// cambiar la clave que ocupa la posición i en el array de claves
	void Pclave(int i, tipoClave clave) 
	{ 
		claves[i] = clave; 
	}
	// obtener la rama que ocupa la posición i en el array de ramas
	PaginaB* Orama(int i) 
	{ 
		return ramas[i]; 
	}
	// cambiar la rama que ocupa la posición i en el array de ramas
	void Prama(int i, PaginaB* p) 
	{ 
		ramas[i] = p; 
	}
	// obtener el valor de cuenta
	int Ocuenta() 
	{ 
		return cuenta; 
	}
	// cambiar el valor de cuenta
	void Pcuenta(int valor) 
	{ 
		cuenta = valor; 
	}
};

