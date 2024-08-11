#include <stdio.h>
#define n 5

int search(int num, int *v, int i)
{
    if(i==n)
    {
        return -1;
    }
    else if(num==v[i])
    {  
        return i;
    }
    else{
        search(num, v,i+1);
    }
}


int main(){
int v[n]={0,1,2,3,4}, num;

printf("Qual numero deseja procurar?\n");
scanf("%d", &num);

printf("%d", search(num, v, 0) );



/*

recursiva pra procurar um elemento em um vetor de N elementos

procurar um elemento em um vetor de n elementos eh o memos que comparar com o primeiro elemento e, se nao for igual,voltar a procurar o memso elemento no vetor restante de n-1 elementos.

a função deve retornar -1 se o elemento nao for encontrado, ou o indice do elemento encontrado

*/

    return 0;
}