/*
 * principal.c
 *
 *  Created on: 21 mar. 2019
 *      Author: Laura
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "arbolbb.h"

void crearFicheroAleatorios(char *nombreFich, int TAM)
{
	FILE *fichero;
    int n;
    if(fichero = fopen(nombreFich,"wb") == NULL){
        perror("Error abriendo fichero.txt");
    }
    printf("El fichero se ha abierto correctamente\n");
    srand(time(NULL));
    for(int i = 0; i < TAM; i++){
        n = rand()%TAM;
        fwrite(&n,sizeof(int),1,fichero);
    }
    fclose(fichero);

}

void mostrarFicheroAleatorios(char *nombreFich)
{
    FILE *fichero;
    int n;
    if(fichero = fopen(nombreFich,"rb") == NULL){
        perror("Error abriendo fichero.txt");
    }
    printf("El fichero se ha abierto correctamente\n");
    while(fread(&n,sizeof(int),1, fichero) == 1){
        printf(" %d ", n);
    }
    fclose(fichero);
}

void cargaFichero(char* nfichero, T_Arbol* miarbol)
{
	
}

int main(int argc, char **argv)
{
	int TAM;
	char nombreFich[30];

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Introduzca nombre fichero:\n");
	scanf("%s", nombreFich);

	printf("Introduzca tamaño:\n");
	scanf("%d", &TAM);

	crearFicheroAleatorios(nombreFich, TAM);
	mostrarFicheroAleatorios(nombreFich);

	printf ("\n Ahora lo cargamos en el arbol\n");
	T_Arbol miarbol;
	crear (&miarbol);
	cargaFichero(nombreFich,&miarbol);
	printf ("\n Y lo mostramos ordenado\n");
	mostrar(miarbol);

	printf("\n Ahora lo guardamos ordenado\n");
	FILE * fich;
	fich = fopen (nombreFich, "wb");
	salvar (miarbol, fich);
	fclose (fich);
	printf("\n Y lo mostramos ordenado\n");
	mostrarFicheroAleatorios(nombreFich);
	destruir (&miarbol);

}













































