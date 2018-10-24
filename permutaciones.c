/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include "permutaciones.h"

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
	if(inf>sup) return ERR;
	return ((rand() % (sup - inf)) + inf);
}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int N)
{
	int* perm = NULL;
	int i, rnd, aux;

	if(N<1) return NULL;

	perm = (int*) calloc(N, sizeof(int));
	if(perm == NULL) return NULL;

	for(i=0; i<N; i++){
		perm[i] = i+1;
	}

	for(i=0; i<N; i++){
		rnd = aleat_num(i, N);
		aux = perm[i];
		perm[i] = perm[rnd];
		perm[rnd] = aux;
	}

	return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N)
{
	int i;
	int** s_perms = NULL;
	s_perms = (int**) calloc(n_perms, sizeof(int*));
	if(s_perms == NULL) return NULL;

	for(i=0; i<n_perms; i++){
		s_perms[i] = genera_perm(N);
		if(s_perms[i] == NULL) return NULL;
	}

	return s_perms;
}
