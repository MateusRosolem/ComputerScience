#include <stdio.h>
int cont=0;
int soma=0;
int quero=148;

int *vetormaior;


void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
  int i, j, k;

    

    if (index == r)
    {
    //printf("Oi");
        // printf("[%d] [%d]\n",data[j], arr[end]);
        // if(data[0]==arr[end-2])
        //     return;

    for(k=0;k<r;k++)
        soma+=data[k];
    if(soma==quero){
        for (j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        cont++;


        if(vetormaior[0]==0)
            for(j=0;j<r;j++) vetormaior[j]=data[j];
        else
        {
            j=0;
            while(vetormaior[j]!=0) j++;

            if(j==r &&vetormaior[j]<data[j])
                for(j=0;j<r;j++) vetormaior[j]=data[j];
            else if(j<r)
                for(j=0;j<r;j++) vetormaior[j]=data[j];
        }


        return;
    }
    else 
        soma=0;
    }

    //printf("[%d] [%d]\n",data[j-1], arr[end-1]);
    //if(data[j]==arr[end])
      //  printf(" ");
        //return;
 
  for (i=start; i<=end && end-i+1 >= r-index; i++)
  {
    data[index] = arr[i];
    combinationUtil(arr, data, i+1, end, index+1, r);
  }

}

void printCombination(int arr[], int n, int r)
{
  int data[r];
  combinationUtil(arr, data, 0, n-1, 0, r);
    //printf("oi");
}
 
int main()
{
  int arr[] = {1, 10, 11, 21, 27, 33, 34, 46, 49, 61, 62, 67, 73, 77, 79};
  int r;
  int n = sizeof(arr)/sizeof(arr[0]);
  int m=15;
  int i=0;
  vetormaior=calloc(m,sizeof(int));
  
   for (r=4; r<15; r++)
    printCombination(arr, n, r);
    printf("\n%d ", cont);
    i=0;
    while(vetormaior[i]!=0)
    {
        printf("%d ", vetormaior[i]);
        i++;
    }
}