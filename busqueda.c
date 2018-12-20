/**
 *
 * Descripcion: Implementacion funciones para busqueda 
 *
 * Fichero: busqueda.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 11-11-2016
 *
 */

#include "busqueda.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 *  Funciones de geracion de claves
 *
 *  Descripcion: Recibe el numero de claves que hay que generar
 *               en el parametro n_claves. Las claves generadas
 *               iran de 1 a max. Las claves se devuelven en 
 *               el parametro claves que se debe reservar externamente
 *               a la funcion.
 */

/**
 *  Funcion: generador_claves_uniforme
 *               Esta fucnion genera todas las claves de 1 a max de forma 
 *               secuencial. Si n_claves==max entonces se generan cada clave
 *               una unica vez.
 */
void generador_claves_uniforme(int *claves, int n_claves, int max)
{
	int i;

	for (i = 0; i < n_claves; i++)
		claves[i] = 1 + (i % max);

	return;
}

PDICC ini_diccionario(int tamanio, char orden)
{
	DICC *new_diccionario;

	if (tamanio == 0 || (orden != ORDENADO && orden != NO_ORDENADO))
		return NULL;

	new_diccionario = (DICC *)calloc(1, sizeof(DICC));

	if (!new_diccionario)
		return NULL;

	new_diccionario->tamanio = tamanio;
	new_diccionario->n_datos = 0;
	new_diccionario->orden = orden;
	new_diccionario->tabla = (int *)calloc(tamanio, sizeof(int));

	memset(new_diccionario->tabla, ERR, tamanio);

	return new_diccionario;
}

void libera_diccionario(PDICC pdicc)
{
	if (!pdicc)
		return;

	if (pdicc->tabla)
		free(pdicc->tabla);

	free(pdicc);
}

int inserta_diccionario(PDICC pdicc, int clave)
{
	int a, j;

	if (!pdicc)
		return ERR;

	if (pdicc->tamanio <= pdicc->n_datos)
		return ERR;

	(pdicc->tabla)[pdicc->n_datos] = clave;
	pdicc->n_datos++;

	if (pdicc->orden == ORDENADO) {
		a = pdicc->tabla[pdicc->n_datos - 1];
		j = pdicc->n_datos - 2;

		while (j >= 0 && pdicc->tabla[j] > a) {
			pdicc->tabla[j + 1] = pdicc->tabla[j];
			j--;
		}
		pdicc->tabla[j + 1] = a;
	}

	return OK;
}

int insercion_masiva_diccionario(PDICC pdicc, int *claves, int n_claves)
{
	int i;

	if (!pdicc || !claves)
		return ERR;

	if (pdicc->tamanio - pdicc->n_datos < n_claves)
		return ERR;

	for (i = 0; i < n_claves; i++) {
		if (inserta_diccionario(pdicc, claves[i]) == ERR)
			return ERR;
	}

	return OK;
}

int busca_diccionario(PDICC pdicc, int clave, int *ppos, pfunc_busqueda metodo)
{
	int search_result;

	if (!pdicc || !ppos || !metodo || !pdicc->tabla)
		return ERR;

	search_result = metodo(pdicc->tabla, 0, pdicc->tamanio, clave, ppos);

	if (*ppos == NO_ENCONTRADO)
		return NO_ENCONTRADO;

	return search_result;
}

/* Funciones de busqueda del TAD Diccionario */
int bbin(int *tabla, int P, int U, int clave, int *ppos)
{
	int mitad, iU = U, iP = P, n_operaciones = 0;

	if (!tabla || !ppos || P > U)
		return ERR;

	while (iP <= iU) {
		n_operaciones++;
		mitad = (iP + iU) / 2;

		if (tabla[mitad] == clave) {
			*ppos = mitad;
			return n_operaciones;
		} else if (tabla[mitad] < clave) {
			iP = mitad + 1;
		} else {
			iU = mitad - 1;
		}
	}

	*ppos = NO_ENCONTRADO;
	return n_operaciones;
}

int blin(int *tabla, int P, int U, int clave, int *ppos)
{
	int i;

	if (!tabla || !ppos || P > U)
		return ERR;

	for (i = P; i <= U; i++) {
		if (tabla[i] == clave) {
			*ppos = i;
			return (i - P) + 1;
		}
	}

	*ppos = NO_ENCONTRADO;
	return (i - P) + 1;
}
