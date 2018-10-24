/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tiempos.h"
#include "ordenacion.h"
#include "permutaciones.h"

/***************************************************/
/* Funcion: tiempo_medio_ordenacion                */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Asigna los campos de la estructura tiempo       */
/* tras realizar la ordenacion                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo,
                              int n_perms,
                              int N,
                              PTIEMPO ptiempo)
{
        struct timespec tp1, tp2;
        clockid_t clk_id;
        int** table = NULL;
        int i, max=-1, min=-1, tot=0, n=0;

	if(N<1 || n_perms<1 || ptiempo==NULL) return ERR;

        /* Genera tabla de permutaciones */
        table = genera_permutaciones(n_perms, N);
	if(table==NULL) return ERR;

        clk_id = CLOCK_MONOTONIC;
        clock_gettime(clk_id, &tp1);
        /* realiza la ordenacion y obtiene num. total de OB */
        for (i=0; i<n_perms; i++){
                n = metodo(table[i], 0, N-1);
                if(n>max) max=n;
                if (min==-1) min=n;
                else if(n<min) min=n;
                tot+=n;
        }
        clock_gettime(clk_id, &tp2);

        ptiempo->tiempo = (tp2.tv_nsec - tp1.tv_nsec)/n_perms;
        ptiempo->n_elems= n_perms;
        ptiempo->medio_ob = tot/(ptiempo->n_elems);
        ptiempo->min_ob = min;
        ptiempo->max_ob = max;
        ptiempo->N = N;

	for (i=0; i<n_perms; i++)
		free(table[i]);

	free(table);
        return 0;
}


/***************************************************/
/* Funcion: genera_tiempos_ordenacion              */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Escribe los tiempos medios, números promedio,   */
/* min y máx de veces que se ejecuta la OB con     */
/* n perms permutaciones de tamaños entre num min  */
/* y num max, con incrementos de tamaño incr.      */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero,
                                int num_min, int num_max,
                                int incr, int n_perms)
{
        PTIEMPO ptiempo = NULL;
	int N;
	FILE* f = NULL;

	if(num_min<1 || num_max<1 || n_perms<1 || fichero==NULL || incr<1) return ERR;

	ptiempo = (PTIEMPO) calloc(1, sizeof(TIEMPO));
	if(ptiempo == NULL) return ERR;

	f = fopen(fichero, "w");
	if(f == NULL){
		free(ptiempo);
		return ERR;
	}

	for(N=num_min; N<=num_max; N+=incr){
        	if(tiempo_medio_ordenacion(metodo, n_perms, N, ptiempo) == ERR) return ERR;
		guarda_tabla_tiempos(fichero, ptiempo, N);
	}

	fclose(f);
	free(ptiempo);
        return 0;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos                   */
/* Autores: David Palomo, Antonio Solana           */
/*                                                 */
/* Escribe en fichero los datos obtenidos en la    */
/* funcion genera_tiempos_ordenacion               */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
	FILE* f = NULL;

	if(fichero==NULL || tiempo==NULL) return ERR;

	f = fopen(fichero, "a");
	if(f == NULL){
		free(tiempo);
		return ERR;
	}

	fprintf(f, "%d %f %d %d %f.\n",
		n_tiempos, 
		tiempo->tiempo, 
		tiempo->min_ob, 
		tiempo->max_ob, 
		tiempo->medio_ob);

	fclose(f);
  	return 0;
}
