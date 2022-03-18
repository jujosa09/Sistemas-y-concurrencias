#include <stdlib.h>
#include <stdio.h>
#include "arbolbb.h"

// Crea la estructura utilizada para gestionar el árbol.
void crear(T_Arbol* arbol){
    *arbol = NULL;
}
// Destruye la estructura utilizada y libera la memoria.
void destruir(T_Arbol* arbol){
    while(*arbol != NULL){
        destruir(&((*arbol)->izq));
        destruir(&((*arbol))->der);

        free(*arbol);

        *arbol = NULL;
    }
}
// Inserta num en el árbol. Si ya está insertado, no hace nada
void insertar(T_Arbol* arbol,unsigned num){
    if(*arbol == NULL){
        *arbol = malloc(sizeof(struct T_Nodo));
        if(*arbol != NULL) {
            (*arbol)->dato = num;
            (*arbol)->der = NULL;
            (*arbol)->izq = NULL;
        }else{
            perror("No se ha asignado bien la memoria");
            return;
        }
    }else{
        if (num < (*arbol)->dato) {
                insertar(&((*arbol)->izq), num);
        } else if(num > (*arbol)->dato) {
                insertar(&((*arbol)->der), num);
        }
    }

}
// Muestra el contenido del árbol en InOrden
void mostrar(T_Arbol arbol) {
    while(arbol != NULL){
        mostrar(arbol->izq);
        printf(" %d ", arbol->dato);
        mostrar(arbol->der);
    }
}
// Guarda en disco el contenido del fichero
void salvar(T_Arbol arbol, FILE* fichero){
    if(arbol != NULL){
       salvar(arbol->izq,fichero);
       unsigned n = arbol->dato;
        fwrite(&n,sizeof(unsigned),1,fichero);
        salvar(arbol->der,fichero);
    }

}


