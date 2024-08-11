#include <stdio.h>

int main(){
int v1[10],v2[5];
int vresult1[15], vresult2[1000], divisores=0;//malloc
int i=0,j=0,k=0;

for ( i = 0; i < 10; i++)
{
    scanf("Insira valor de v1%d\n",v1[i]);
}    
for(i=0;i<5;i++)
{
    scanf("insira valor de v2%d\n",v2[i]);
}


k=0;
for(i=0;i<10;i++)
{  
    if(v1[i]%2==0)
    {    
        vresult1[k]=v1[i];
        for(j=0;j<5;j++)
        {
            vresult1[j]+=v2[j];
        }
        printf("vresult1[%d]=%d\n", k, vresult1[k]);//soma de cada numero par do primeiro vetor somado a todos os numeros do segundo vetor
        k++;
    }
}


for(i=0;i<10;i++)
{
    for(j=0;j<5;j++)
    {    
        if(v1[i]%2==1 && v1[i]%v2[j]==0)
        {
            divisores++; 
        }
    }
    printf("o numero de divisores do v1[%d] eh %d\n",i,divisores);
    divisores=0;  
}

//QUANTIDADE numero de divisores que cada numero impar do primeiro vetor tem no segundo vetor

}