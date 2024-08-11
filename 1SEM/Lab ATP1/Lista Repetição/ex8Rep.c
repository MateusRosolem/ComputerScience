#include <stdio.h>

int main(){
int ele, r, n, termo;
int i;

printf("qual e o primeiro elemento, razao e numero de termnos nessa ordem da PA desejada?\n");
scanf("%i %i %i", &ele, &r, &n);

for(i=0;i<n;i++){
termo=ele+(i-1)*r;
printf("o %i termo eh: %i \n", i, termo);

}



    return 0;
}