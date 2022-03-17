#include <stdlib.h>
#include <stdio.h>
#include "arbolbb.h"

// Crea la estructura utilizada para gestionar el árbol.
void crear(T_Arbol* arbol){
    arbol = NULL;
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
void insertar(T_Arbol* arbol,unsigned num);
// Muestra el contenido del árbol en InOrden
void mostrar(T_Arbol arbol);
// Guarda en disco el contenido del fichero
void salvar(T_Arbol arbol, FILE* fichero);


