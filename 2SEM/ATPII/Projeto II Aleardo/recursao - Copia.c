#include <stdio.h>
int n=0,m=0, *k, *nums;//Variáveis de entrada
int i=0,j=0; //Variáveis contadoras

int soma=0;  //Variáveis de contas(tamanho do maior conjunto)
int cont=0;

int *comb,  *vetormaior; //Variáveis de saída(numero de combinações e os vetores de conjuntos resultantes)



void recursao(int termo,int base )
{ //ver se é m ou m-1
    while(soma!=0 && base!=0)
    {
        soma+=nums[base];
        if(soma<k[base])
            recursao(termo, base-1);
        else if(soma==k[base])
        {
           for(j=0+(m*termo);j<m+(m*termo);j++)
                vetormaior[j]=k[j];
            soma=0;
            comb[termo]++;
        }    
        else
            soma-=k[base];
            recursao(termo,base-1);
    }
    recursao();//Diminuir numero de algarismos nos conjuntos resultantes

}

//botar for pra rodar m-1 vezes, começando de elemento por elemento




int main()
{
int a;

//ENTRADA DE DADOS
    scanf("%d %d",&n, &m); //Quantidade de números que vão ser decompostos e a quantidade de números que vão ser usados na decomposição

    nums=malloc(m*sizeof(int));
    k=malloc(n*sizeof(int));
    comb=malloc(n*sizeof(int));
    vetormaior=malloc(m*n*sizeof(int));

    for(i=0;i<m;i++)
        scanf("%d",&nums[i]); //Números(m vezes) que podem ser usados para compor o número maior
    for(i=0;i<n;i++)
        scanf("%d",&k[i]); //Números que querem que seja decompostos

//Recursao
for(a=0;a>n;a++)
recursao(a,m);


//SAIDA DE DADOS
for(i=0;i<n;i++)
{
    if(comb[i]!=0) //Se houver combinações
        printf("%d ", comb[i]); //printar o numero de combinações
    else
    {
        printf("0");// senao printar zero
        break;
    }

    for(j=0+(m*i);j<m+(m*i);j++)
        if(vetormaior[j]>0)
            printf("%d ", vetormaior[j]);//logo em seguida printar o números da maior combinação possívei(de tamanho variável tamanho[i])
    printf("\n");
}

    free(nums);
    free(k);

    return 0;
}