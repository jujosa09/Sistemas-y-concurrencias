#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "gestion_memoria.h"

/*
 * gestion_memoria.h
 *
 *  Created on: dd/mm/aaaa
 *  Author: name
 */

typedef struct T_Nodo* T_Manejador;

struct T_Nodo {
	unsigned inicio;
	unsigned fin;
	T_Manejador sig;
};

/* Crea la estructura utilizada para gestionar la memoria disponible. Inicialmente, sólo un nodo desde 0 a MAX */
	void crear(T_Manejador* manejador){
        *manejador = (T_Manejador) malloc(sizeof(struct T_Nodo));
        if(*manejador != NULL){
            (*manejador) -> inicio = 0;
            (*manejador) -> fin = 999;
            (*manejador) -> sig = NULL;
        }else{
            perror("Memoria insuficiente al crear");
        }

    }

/* Destruye la estructura utilizada (libera todos los nodos de la lista. El parámetro manejador debe terminar apuntando a NULL */
	void destruir(T_Manejador* manejador){
        T_Manejador aux;
        while (*manejador != NULL) {
                aux = *manejador;
                *manejador = (*manejador) -> sig;
                free(aux);
            }
    }

/* Devuelve en “dir” la dirección de memoria “simulada” (unsigned) donde comienza el trozo de memoria continua de tamaño “tam” solicitada.
Si la operación se pudo llevar a cabo, es decir, existe un trozo con capacidad suficiente, devolvera TRUE (1) en “ok”; FALSE (0) en otro caso.
 */
	void obtener(T_Manejador *manejador, unsigned tam, unsigned* dir, unsigned* ok){
        *ok = 0; //Asumo que no va a haber memoria
        T_Manejador ant = NULL;
        T_Manejador curr = *manejador;
        while(curr != NULL && ((curr -> fin - curr -> inicio + 1) < tam)){
            ant = curr;
            curr = curr -> sig;
        }
        if(curr != NULL){
            *ok = 1;
            *dir = curr -> inicio;
            if(curr -> fin - curr -> inicio + 1 > tam){
                curr -> inicio = curr -> inicio + tam;
            }else{
                if(ant == NULL){
                    *manejador = (*manejador) -> sig;

                }else{
                    ant -> sig = curr -> sig;
                }
                free(curr);
            }

        }

    }

/* Muestra el estado actual de la memoria, bloques de memoria libre */
	void mostrar (T_Manejador manejador){
        if(manejador == NULL){
            printf("No hay memoria");
        }else {
            T_Manejador aux;
            int i = 0;
            aux = manejador;
            while (aux != NULL) {
                printf("Inicio: %d  Fin: %d  Bloque: %d \n", aux->inicio, aux->fin, i);
                i = i + 1;
                aux = aux->sig;
            }
        }
    }

/* Devuelve el trozo de memoria continua de tamaño “tam” y que
 * comienza en “dir”.
 * Se puede suponer que se trata de un trozo obtenido previamente.
 */
    void compactar(T_Manejador *manejador){
        T_Manejador curr = *manejador;
        while(curr != NULL && curr -> sig != NULL){
            if(curr -> fin +1 == curr -> sig -> inicio){ //Son bloques consecutivos
                curr -> fin = curr->sig->fin;
                T_Manejador aux = curr -> sig;
                curr -> sig = aux -> sig;
                free(curr ->sig);
            }else{
                curr = curr -> sig;
            }
        }
    }
	void devolver(T_Manejador *manejador,unsigned tam,unsigned dir){
        T_Manejador ant = NULL;
        T_Manejador curr = *manejador;
        T_Manejador nuevoNodo = (T_Manejador)malloc(sizeof (struct T_Nodo));
        if(nuevoNodo == NULL){
            return;
        }else{
            //Actualizar inicio y fin de nuevoNodo

            //Recorrido condicional - Encontrar la posicion que le corresponde a nuevo

            //Fuera del bucle while:
            //1. Insertar en la primer posicion - ant == NULL y nuevo primer nodo de la lista
            //2. ant!=NULL y nuevo va en una posicion intermedia o final

            compactar(manejador);
        }
    }


