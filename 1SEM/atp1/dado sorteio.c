#include <stdio.h>
#include <stdlib.h>

int main(){
int dado;
int rpt=0;

while(rpt<7){

dado=rand()%6;
printf("%d ",dado);
dado=rand()%6;
printf("%d ",dado);
dado=rand()%6;
printf("%d \n",dado);

    rpt++;
}








    return 0;
}