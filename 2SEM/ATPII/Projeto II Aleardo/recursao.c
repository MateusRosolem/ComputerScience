#include <stdio.h>
#include <stdlib.h>
int cont=0,  vetormaior[150]={0}; //Variáveis de saída(numero de combinações e os vetores de conjuntos resultantes)



void recurs(int arr[], int data[], int start, int end, int index, int r, int k) //Função de Combinação de adições
{
  int i, j, soma=0;

    if (index == r) 
    {
        for(i=0;i<r;i++) soma+=data[i]; //Soma o conjunto atual pra ver se é == a Ki
        if(soma==k){
            if (vetormaior[r-1] < data[r-1]) { //Verifica se o último numero do anterior é maior que do atual
                for (j=0; j<r; j++) {
                    vetormaior[j] = data[j];    
                }            
            }  
        // for (j=0; j<r; j++)
        //     printf("%d ", data[j]);
        // printf("\n");
        cont++;
        return;
        }
            soma=0;
            return;
    }

    for (i=start; i<=end && end-i+1 >= r-index; i++) {
        data[index] = arr[i];
        recurs(arr, data, i+1, end, index+1, r, k);
    }

}


void combinacao(int arr[], int n, int r, int k){
    int data[r]; //Vetor pra guardar o atual conjunto de numeros
    recurs(arr,data,0,n-1,0,r,k);

}



int main(){
int i, j; //Variáveis contadoras
int n=0,m=0, *ki, *nums;//Variáveis de entrada

//ENTRADA DE DADOS
scanf("%d %d",&n, &m); //Quantidade de números que vão ser decompostos e a quantidade de números que vão ser usados na decomposição

nums=malloc(m*sizeof(int)); //1 10 11 21 27 33 34 46 49 61 62 67 73 77 79
ki=malloc(n*sizeof(int));    //148 206 14

for(i=0;i<m;i++)
    scanf("%d", &nums[i]); //Números(m vezes) que podem ser usados para compor o número maior
for(i=0;i<n;i++)
    scanf("%d", &ki[i]); //Números que querem que seja decompostos




//SAIDA DE DADOS
for(i=0;i<n;i++)// Faz uma função e printa de cada vez
{
    for(j=2; j<=m; j++)  //For para rodar as combinações começando somando de 2 em 2 conjuntos
    combinacao(nums,m,j,ki[i]);//Recursão

    if(cont==0) //se nao houver combinações
        printf("0\n");
    else
    {
        printf("%d ", cont);//Printa numero de combinações
        cont=0;

        j=0;
        while(vetormaior[j]!=0){ 
            printf("%d ", vetormaior[j]); //Printa os vetores usados na maior combinação que possui o maior valor
            vetormaior[j] = 0;
            j++;
        }    
        printf("\n");
    }
}

    free(nums);
    free(ki);
    free(cont);
    free(vetormaior);
    return 0;
}
