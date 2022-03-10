#include <stdio.h>

int main() {
    int num1;
    int num2;
    char operador;
    printf("Introduzca en este orden, el primer numero, el segundo y el operador: ");
    scanf("%d %d %s", &num1,&num2,&operador);
    printf("%d %d %s \n", num1,num2,operador);
    if(operador == '+'){
        printf("El resultado es: %d", num1+num2);
    }else if(operador == '-'){
        printf("El resultado es: %d", num1-num2);
    }else if(operador == '*'){
        printf("El resultado es: %d", num1*num2);
    }else if(operador == '/'){
        printf("El resultado es: %d", num1/num2);
    }else{
        printf("Error al introducir el operador\n");
    }
    return 0;
}
