#include <stdio.h>
#include <stdlib.h>

int main(){
int n, m, i,j,k, *a, x,y, menor=0;


scanf("%d %d", &n , &m);//linhas e colunas e M regioes que vao ser verificadas
a=malloc(n*n*sizeof(int));
for(i=0;i<n*n;i++){
        scanf("%d", &a[i]);
}



for(k=0;k<m;k++){
  scanf("%d %d", &x, &y);// começa na linha e coluna A e termina na linha e coluna B

  for(i=x-1;i<=y-1;i++){
    for(j=x-1;j<=y-1;j++){
      if(menor==0)
          menor=a[(i*n) + j];
      if(menor>a[(i*n) + j]){
          menor=a[(i*n) + j];
      }
    }
  }
  printf("%d \n", menor);// menor valor encontrado
  menor=0;
}
    return 0;
}