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
#include <time.h>
#include "tiempos.h"
#include "ordenacion.h"
#include "permutaciones.h"

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int N, 
                              PTIEMPO ptiempo)
{
        struct timespec tp1, tp2;
        clockid_t clk_id;
        int** table = NULL;
        int i, max = -1, min = -1;
        
        /* Genera tabla de permutaciones */
        table = genera_permutaciones(n_perms, N);

        
        clk_id = CLOCK_MONOTONIC;
        clock_gettime(clk_id, &tp1);        
        /* realiza la ordenacion y obtiene num. max, min y total de OB */
        for (i=0; i<n_perms; i++){
                n = metodo(table[i], 0, N);

                if(n>max) max=n;                
                if (min = -1) min=n;
                else if(n<min) min=n;
                
                tot = tot + n;
        }
        clock_gettime(clk_id, &tp2);


        ptiempo->tiempo = (tp2.nsec - tp1.nsec)/n_perms;
        ptiempo->n_elems= n_perms * N;                
        ptiempo->medio_ob = tot/(ptiempo->n_elems);
        ptiempo->min_ob = min;
        ptiempo->max_ob = max;

        return 0;
}  

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*  escribe en fichero los tiempos medios, y los 
números promedio, mı́nimo y máximo de veces que
se ejecuta la OB con n perms permutaciones de tamaños
en el rango desde num min hasta num max, incluidos, 
usando incrementos de tamaño incr. Return ERR o OK*/
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
        /*
        FILE* f = NULL;
        PTIEMPO ptiempo;

        tiempo_medio_ordenacion(metodo, 10, 10, ptiempo);
        
        f = fopen ("file.txt", "w+");
        
        fprintf(f, "bla", ptiempo->n_elems, ptiempo->medio_ob, ptiempo->n_elems, ptiempo->n_elems);
   

        fclose(f);
        */

        return 0;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
  return 0;
}
