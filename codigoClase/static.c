// Static.c

#include <stdio.h>
int glob = 0; //variable global -- cualquier funcion puede modificarla
void add2() {
  static int var = 1; // variable local que mantiene su valor entre llamadas
  glob++;
  printf("var = %d  glob = %d\n", var+=2, glob) ;
}

int main (int argc, char ** argv) {
  add2();
  add2();
  add2();
  
  return 0;
}  
