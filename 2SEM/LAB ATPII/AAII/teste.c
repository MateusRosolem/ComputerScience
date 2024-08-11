#include <stdio.h>
#include <string.h>


int respInt[50]={0};
char respChar[50]={'\0'};
/*Faça um programa em C que receba uma frase e mostre as letras que se repetem, junto com
o número de repetições.*/

int main() {
    int i,j,l,k=0,flag=0,aux=0,tam,tam2;
    char frase[50],auxChar;

    scanf("%[^\n]",frase);

    tam = strlen(frase);
    for (i = 0; i < tam; i++) {
        for (j = 1+i; j < tam; j++) {
            if (frase[i]==frase[j]&&frase[i]!=32) {
                aux++;
            }
        }

        if (aux != 0) {
            if (k !=0) {
                for(l=0;l<k;l++) {
                    if (frase[i] == respChar[l]) {
                        flag=1;
                    }
                }

                if (!flag) {
                    respChar[k] = frase[i];
                    respInt[k] = aux;
                    k++;
                }
            } else {
                respChar[k] = frase[i];
                respInt[k] = aux;
                k++;
            }

        }
        aux=0;
        flag=0;
    }

    tam2=strlen(respChar);
    printf("As Letras repetidas sao: \n");
    for(i=0;i<tam2;i++) {
        printf("[%c] = [%d]\n",respChar[i],respInt[i]+1);
    }


}