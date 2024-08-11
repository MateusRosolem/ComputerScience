#include <stdio.h>

int cont=0, k=0,n=0;



void hanoi(int n, int org, int aux, int dst, int cont)
{
    //while(cont!=k)
    //{
        if(n==1)
        {
            //printf("1\n");
            dst++;
            org--;
            cont++;
        }
        else
        {

            //printf("ELSE\n");
            hanoi(n-1, org, aux, dst,cont);
            hanoi(1, org, dst, aux,cont);
            hanoi(n-1, aux, dst, org,cont);


        }
    //}
    printf("\n");
    printf("%d\n ",org);
    printf("%d\n ",aux);
    printf("%d\n",dst);
}



int main(){
int o=0, a=0, d=0;
scanf("%d %d", &n, &k);
o=n;

hanoi(n, o, a, d, cont);


    return 0;
}