#include <stdio.h>
#define n 4
int i=0;

int fuc(int matriz[n][n], int k, int v[])
{

}


int recurs(int *v, int cont){

    if(v[i]<v[cont] && cont!=n)
    {   
        i=cont;
        printf("OI ");
    }
    recurs(v, cont+1);
    return i;
}

int main()
{
int v[4]={3,0,8,4};
int cont=1;

printf("%d\n", recurs(v, cont));

    return 0;
}