/**
 *
 * Descripcion: Implementacion de funciones de ordenacion
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "ordenacion.h"
#define ERR -1

/***************************************************/
/* Funcion: SelectSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int SelectSort(int* tabla, int ip, int iu)
{
	int i, min, aux;

	for(i=ip; i<iu; i++){
		min = minimo(tabla, i, iu);
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}

	return(i-ip);
}

int minimo(int *tabla, int ip, int iu)
{
	int min = ip, j;

	for(j=ip; j<=iu; j++) {
		if(tabla[j]<tabla[min])
			min = j;
	}

	return min;
}

int SelectSortInv(int* tabla, int ip, int iu)
{
	int i, min, aux;

	for (i=iu; i>ip; i--) {
		min = minimo(tabla, ip, i);
		printf("minimo >> %d\n", min);
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}

	return(0);
}
