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
	BPagina * ramas; // puntero array de punteros a p�ginas variable
	int cuenta; // n�mero de claves que almacena la p�gina
private:
	int m; //m�ximo n�mero de claves que puede almacenar la p�gina
public:
	// crea una p�gina vac�a de un cierto orden dado
	PaginaB(int orden)
	{
		m = orden;
		claves = new tipoClave[orden];
		ramas = new BPagina[orden];
		for (int k = 0; k <= orden; k++)
			ramas[k] = NULL;
	}

	// decide si un nodo est� lleno
	bool nodoLLeno()
	{
		return (cuenta == m - 1);
	}
	// decide si una p�gina tiene menos de la mitad de claves
	bool nodoSemiVacio()
	{
		return (cuenta < m / 2);
	}
	// obtener la clave que ocupa la posici�n i en el array de claves
	tipoClave Oclave(int i) 
	{ 
		return claves[i]; 
	}
	// cambiar la clave que ocupa la posici�n i en el array de claves
	void Pclave(int i, tipoClave clave) 
	{ 
		claves[i] = clave; 
	}
	// obtener la rama que ocupa la posici�n i en el array de ramas
	PaginaB* Orama(int i) 
	{ 
		return ramas[i]; 
	}
	// cambiar la rama que ocupa la posici�n i en el array de ramas
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

