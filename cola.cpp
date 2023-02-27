#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	nodo *siguiente;
};

void inicializar(nodo *&frente, nodo *&fondo);
void agregar(nodo *&frente, nodo *&fondo, int numero);
void eliminar(nodo *&frente, nodo *&fondo);
void listar(nodo *&frente);

int main() {
	int cantidad, numero;
	nodo *frente, *fondo;
	inicializar(frente, fondo);

	printf("Ingrese cantidad a agregar a la cola: ");
	scanf("%d", &cantidad);

	for(int i = 0; i < cantidad; i++) {
		printf("Ingrese numero %d: ", i);
		scanf("%d", &numero);
		agregar(frente, fondo, numero);
	}

	while(frente != NULL) {
		eliminar(frente, fondo);
	}

	listar(frente);

	return (0);
}

void inicializar(nodo *&frente, nodo *&fondo) {
	frente = NULL;
	fondo = NULL;
}

void agregar(nodo *&frente, nodo *&fondo, int numero) {
	nodo *nuevo_nodo = new nodo;
	nuevo_nodo -> dato = numero;
	nuevo_nodo -> siguiente = NULL;
	if(frente == NULL) {
		frente = nuevo_nodo;
	} else {
		fondo -> siguiente = nuevo_nodo;
	}
	fondo = nuevo_nodo;
}

void eliminar(nodo *&frente, nodo *&fondo) {
	if(frente != NULL) {
		int datoEliminado;
		nodo *auxiliar = frente;
		datoEliminado = frente -> dato;
		frente = frente -> siguiente;
		delete auxiliar;
		if(frente == NULL) {
			fondo = NULL;
		}
		printf("\nDato eliminado: %d\n", datoEliminado);
	} else {
		printf("\nERROR - Cola vacia\n");
	}
}

void listar(nodo *&frente) {
	nodo *auxiliar;
	auxiliar = frente;
	while(auxiliar != NULL) {
		printf("Dato: %d\n", auxiliar -> dato);
		auxiliar = auxiliar -> siguiente;
	}
	system("pause");
}
