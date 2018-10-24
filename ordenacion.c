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

void printTable(int* table, int size)
{
	int i;

	printf("[");
	for (i=0; i<size; i++)
	{
		printf(" %d", table[i]);
	}
	printf(" ]");
}

/***************************************************/
/* Funcion: SelectSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int SelectSort(int* tabla, int ip, int iu)
{
	int i, min, aux, num_ob = 0;

	for(i=ip; i<iu; i++){
		min = minimo(tabla, i, iu, &num_ob);
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}

	return(num_ob);
}

int minimo(int *tabla, int ip, int iu, int* num_ob)
{
	int min = ip, j;

	for(j=ip; j<=iu; j++) {
		if(tabla[j]<tabla[min])
			min = j;

		(*num_ob)++;
	}

	return min;
}

int SelectSortInv(int* tabla, int ip, int iu)
{
	int i, min, aux, num_ob = 0;

	for (i=iu; i>ip; i--) {
		min = minimo(tabla, ip, i, &num_ob);
		printf("minimo >> %d\n", min);
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}

	return(0);
}
