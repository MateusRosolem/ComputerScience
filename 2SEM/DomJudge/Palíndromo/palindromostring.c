#include <stdio.h>
#include <string.h>
char k[2000], j[2000];
int quant=0, tamanho;
int aux=0;


void recurs(int i,int cont,int quantid)
{
    if(j[i]==k[cont])
    {
        if(quant<quantid)
        quant=quantid;
        recurs(i+1,cont+1,quantid+1);
    }
}


void padrao(int quanti)
{
    int a=0, c=0;
        while(c<tamanho)
        {
            if(j[a]==k[c])
            {
                if(quant<quanti)
                    quant=quanti;
                recurs(a+1,c+1,quanti+1);
                a++;
                c=0;
            }
            else
            {
                c++;
            }
        }
}


int main(){
int i=0;

scanf("%s", k);

tamanho=strlen(k);
for(i=0;i<tamanho;i++)
    j[i]=k[tamanho-i-1];
padrao(1);
printf("%d", quant);

    return 0;
}
