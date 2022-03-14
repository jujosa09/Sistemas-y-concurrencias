#include<stdio.h>
#include "parkingDinamico.h"

int main(){
    TParking miParking = inicializar();
    char matricula[8];
    enum TipoV tipo;
    int res,pl;
    while( leerVehiculo(&tipo, matricula)){
        printf("\nEn que plaza quiere aparcar? ");
        scanf("%d",&pl);        
        res = entrar(&miParking,tipo,matricula,pl);
        if(res){
            printf("\nLa plaza estaba DISPONIBLE para %s\n", matricula);
        }else{
            printf("\nLa plaza estaba OCUPADA para %s\n", matricula);
        }
    }
    mostrarParking(miParking);
    salirTodos(&miParking);
    if(miParking == NULL){
        printf("\nHan salido todos los vehiculos\n");
    }
    mostrarParking(miParking);
}