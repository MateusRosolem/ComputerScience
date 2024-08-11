#include <stdio.h>
  int quero=148;
  int soma=0;

void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
  int i, j;

    // if(index==r){
    //     for(j=0;j<r;j++)
    //     {
    //         if(soma<quero)
    //         soma+=data[j];
    //         else if(soma>quero)
    //         {
    //             soma-=data[j-1];
    //             soma+=data[j];
    //         }
    //         else{
    //             printf("[%d] ", data[j]);
    //             break;
    //         }
    //     }
    //     combinationUtil(arr, data, i+1, end, index+1, r);
    // }

  if (index == r && soma==quero )
  {
    for (j=0; j<r; j++)
      printf("%d ", data[j]);
    printf("\n");
    return;
  }
 
  for (i=start; i<=end && end-i+1 >= r-index; i++)//i=0, até n-1 e end-i+1>=r-index 
  {
    data[index] = arr[i];


    for(j=0;j<r;j++)
        {
            if(soma<quero)
            soma+=data[j];
            else if(soma>quero)
            {
                soma-=data[j-1];
                soma+=data[j];
            }
            else{
                printf("[%d] ", data[j]);
                break;
            }
        }

    combinationUtil(arr, data, i+1, end, index+1, r);
  }
}




void printCombination(int arr[], int n, int r)
{
  int data[r];
 
  combinationUtil(arr, data, 0, n-1, 0, r);
}



 
int main()
{
  int arr[] = {1, 10, 11, 21, 27, 33, 34, 46, 49, 61, 62, 67, 73, 77, 79};
  int r;// combinação de R elementos
  int n = sizeof(arr)/sizeof(arr[0]);

   for (r=1; r<=15; r++)
    printCombination(arr, n, r);
}