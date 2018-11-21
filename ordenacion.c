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
/* Funcion: SelectSortInv                          */
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

/***************************************************/
/* Funcion: MergeSort                              */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* ALgoritmo de ordenacion MergeSort               */
/***************************************************/
int MergeSort(int* tabla, int ip, int iu)
{
    int imedio, num;

    if(ip > iu) return ERR;
    else if(ip == iu) return OK;
    else{
    	imedio = (ip + iu) / 2;
      num = MergeSort(tabla, ip, imedio);
      num += MergeSort(tabla, imedio+1, iu);
      num += Merge(tabla, ip, iu, imedio);
    }
    return num;
}

/***************************************************/
/* Funcion: Merge                                  */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Combinacion de tablas para MergeSort            */
/***************************************************/
int Merge(int *tabla, int ip, int iu, int imedio)
{
  int *tabla_aux = NULL;
  int i, j, k, num;

	tabla_aux = (int *) calloc(iu-ip+1, sizeof(int));
  if(!tabla_aux) return ERR;

  for(num=0, k=0, i=ip, j=imedio+1; i<=imedio && j<=iu; k++){
    if(tabla[i] < tabla[j]){
      tabla_aux[k] = tabla[i];
			i++;
      num++;
  	}
    else{
      tabla_aux[k] = tabla[j];
      j++;
    }
  }

  for(;i<=imedio; i++, k++)
    tabla_aux[k] = tabla[i];

  for(;j<=iu; j++, k++)
    tabla_aux[k] = tabla[j];

	for(i=iu; i >= ip; i--){
    k--;
    tabla[i] = tabla_aux[k];
  }

  return num;
}
