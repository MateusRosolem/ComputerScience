#include <stdio.h>
#include <string.h>

int main (){
int vin[11];
int vai[31];

for(int i=0; i<31; i+3){
int p=0;
printf("\n digite valor de vai para i igual %d \n", i);
scanf("%d", &vin[i]);

    vai[i]=vin[p];
    vai[i+1]=vin[p];
    vai[i+2]=vin[p];

   

    p++;
}

for(int p=0; p<31; p++){
    printf("\n VI %d tem vlor de %d", p, vai[p]);
}

    return 0;
}