#include <stdio.h>
#include <string.h>

int main(){

int a=0, b=5, *pa, *pb, aux;

pa=&a;
pb=&b;
aux=*pa;
*pa=*pb;
*pb=aux;
printf("%d//%d\n", *pa, *pb);


pa=*pb;
printf("%d",pa);
    return 0;
}

FILE *fp;

if ((fp = fopen("dados.in", "r"))!=0)
{
    return 0;
}   return 0;