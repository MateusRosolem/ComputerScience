#include <stdio.h>
#include <string.h>

int main(){
int num;
int res[11];


printf("digite um numero para descobrir a tabuada\n ");
scanf("%d", &num);
for(int p=0; p<11 ;p++){

res[p]=num*p;
printf(" %d vezes %d = %d \n", num, p, res[p]);

}

    return 0;
}