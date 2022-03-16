 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
/* int main(int argc, char **argv) 
	argc : numero de argumentos. 
	argv : array de cadena de caracteres. argv[0] es el nombre del programa
*/
{
  int i ;
  for (i = 0; i < argc; i++)
  {
    printf ("Argumento %d: %s\n", i, argv[i]) ;
  }
  return 0;
} 
