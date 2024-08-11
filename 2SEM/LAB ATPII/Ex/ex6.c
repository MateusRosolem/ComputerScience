#include <stdio.h>

int main(){
int preco[10];
int quant[5][10];// armazem e produto
int i=0,j=0, somaarmazem[5]=0, somaproduto[10];
int maior;

for(i=0;i<10;i++)
{
printf("qual o preco do produto %d",i);
scanf("%d", &preco[i]);
}


for(i=0;i<5;i++) //armazem
{
    for(j=0;j<10;j++) //produto
    {
        printf("qual o quantidade (no armazem %d) do produto %d\n",i, j);
        scanf("%d", &quant[i][j]);
        somaarmazem[i]+=quant[i][j];
        somaproduto[j]+=quant[i][j];
    }
}
for(j=0;j<10;j++) 
{
    for(i=0;i<5;i++) 
    {
        somaproduto[j]+=quant[i][j];
    }
}



//a quantidade de produtos estocados em cada armazem
for(i=0;i<5;i++)
{    
    printf("A quantidade de produtos estocados em cada armazem eh %d\n",somaarmazem[i]);
}


//a quantidade de cada um dos produtos estocados, em todos os armazem juntos
for(i=0;i<10;i++)
{
        printf("A quantidade do produto %d em todos os armazens eh %d\n",i,somaproduto[i]);
}

for(i=0;i<10;i++)
{
    for(j=0;j<5;j++)
    {
        if(i==0)
        {
            maior=quant[i][j];
        }
        else if(maior>quant[i-])
        {  
            
        }
    }
}
printf("o preço do produto que tem maior estoque em um unico armazem %d\n",i);



printf("O menor estoque armazenado eh %d\n",i);



printf("o custo de cada armazem %d",);





    return 0;
}