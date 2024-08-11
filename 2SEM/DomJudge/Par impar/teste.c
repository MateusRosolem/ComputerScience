#include <stdio.h>
int main (  )
{
  int i;
  // imprime sempre na mesma linha sobrescrevendo a mesg anterior
  for (i = 0; i < 10; i++){
    printf("\rEstamos em %d", i);
    sleep(1);
    }
  // pula uma linha para não misturar com a de terminal
  printf("\n");
  return 0;
}