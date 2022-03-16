/*
 * Program: PointerToFunction.c
 * Description: Example of pointers to functions
 */
 
#include <stdio.h> 
// Tenemos dos funciones con un parametro entero y otro char y que devuelve void 
void fun1(int a, char b) //esta muestra por pantalla los dos parametros
{ 
    printf("Parametros de tipo int: %d Parametro de tipo char: %c\n", a, b); 
} 

void fun2(int a, char b) //esta muestra por pantalla la suma de los dos parametros
{
	printf("Suma de los parametros: %d\n", a+b); 
}
  
int main() 
{ 
	setvbuf(stdout, NULL, _IONBF, 0);
    // fun_ptr y fun_ptr2 son puntero a una funcion que tiene un parametro entero otro char y que devuelve void 
    void (*fun_ptr)(int, char);
    void (*fun_ptr2)(int, char);

    //fun_ptr apunta a la funcion fun1
    fun_ptr = &fun1;     
    // invocamos la funcion fun1(10,'H') utilizando fun_ptr 
    (*fun_ptr)(10, 'H'); 
    
    /******************** Notacion equivalente ***************************************/
    // El nombre de la funcion ya es un puntero, no necesitamos &
    fun_ptr2 = fun2;  
    //invocamos la funcion fun2(4,'K') con fun_ptr2
    fun_ptr2(4, 'K');  // El operador * se puede eliminar 
  
    return 0; 
} 