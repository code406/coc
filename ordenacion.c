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
/* Funcion: printTable                             */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Imprime la tabla de elementos, util para debug  */
/***************************************************/
void printTable(int* table, int size)
{
	int i;
	if (table==NULL || size<1) return;

	printf("[");
	for (i=0; i<size; i++)
	{
		printf(" %d", table[i]);
	}
	printf(" ]");
}


/***************************************************/
/* Funcion: SelectSort                             */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* ALgoritmo de ordenacion SelectSort              */
/***************************************************/
int SelectSort(int* tabla, int ip, int iu)
{
	int i, min, aux, num_ob = 0;

	if(tabla==NULL || ip<0 || iu<ip) return ERR;
	for(i=ip; i<iu; i++){
		min = minimo(tabla, i, iu, &num_ob);
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}

	return(num_ob);
}

/***************************************************/
/* Funcion: minimo                                 */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Obtiene el indice del elemento mas pequenio     */
/***************************************************/
int minimo(int *tabla, int ip, int iu, int* num_ob)
{
	int min, j;

	if(tabla==NULL || ip<0 || iu<ip || num_ob==NULL) return ERR;
	for(j=ip, min=ip; j<=iu; j++) {
		if(tabla[j]<tabla[min])
			min = j;

		(*num_ob)++;
	}
	return min;
}

/***************************************************/
/* Funcion: SelectSort                             */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* ALgoritmo de ordenacion SelectSort inverso      */
/***************************************************/
int SelectSortInv(int* tabla, int ip, int iu)
{
	int i, min, aux, num_ob = 0;

	if(tabla==NULL || ip<0 || iu<ip) return ERR;
	for (i=iu; i>ip; i--) {
		min = minimo(tabla, ip, i, &num_ob);
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}

	return(num_ob);
}
