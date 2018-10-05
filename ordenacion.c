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

	if(tabla==NULL) return ERR;

	/* DEBUG PRINT TABLA */
	for(i=ip; i<iu; i++){
		printf("%d ", tabla[i]);
	}

	printf("\n");
	for(i=ip; i<iu; i++){
		min = minimo(tabla, i, iu);
		printf("%d ",tabla[min] );
		aux = tabla[i];
		tabla[i] = tabla[min];
		tabla[min] = aux;
	}
	printf("\n");

	return(i-ip);
}

int minimo(int *tabla, int ip, int iu)
{
	int min = tabla[ip], j;

	for(j=ip; j<iu; j++){
		printf("Mirando en %d (como max %d)\n", j, iu);
		if(tabla[j]<tabla[min])
			printf("\tParece que %d es menor que %d\n", tabla[j], tabla[min]);
			min = j;
	}
	printf("[%d][%d] ENCONTRADO MINIMO en %d -> %d\n", ip, iu, min, tabla[min]);

	return min;
}

int SelectSortInv(int* tabla, int ip, int iu)
{
  /* vuestro codigo */
}
