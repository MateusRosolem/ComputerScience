#include <stdio.h>
#include <string.h>

int main(){
char pal[100];
char rep[100][2];
int tam=0;
int i=0,j=0,k=0;
int flag=0;

for(i=0;i<100;i++){
    rep[i][1]=0;
}

scanf(" %[^\n]", &pal);
tam=strlen(pal);

for(i=0;i<tam;i++){
    for(j=i+1;j<tam;j++){
        k=0;
        while(k<tam){
            if(pal[i]==rep[k][0])
                flag=1;
            k++;
        }
        if(flag==0 && pal[i]==pal[j] && pal[j]!=' '){
            rep[i][0]=pal[i];
            rep[i][1]++;
            }
        flag=0;
    }
}


for(i=0;i<tam;i++){
    if(rep[i][1]>0)
        printf("letra:[%c] quant %d\n", rep[i][0], rep[i][1]+1);
}


    return 0;
}