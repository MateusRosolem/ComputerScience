#include <stdio.h>

int main(){
int alturah2=0;
int alturam2=0;
int altura=0;
char sexo1;
int malta, mbaixa;
int halto, hbaixo;
int media=0;
int homens=0;
float percent;
int n=0, mulheres=0;


for(int x=0; x<6; x++){
n++;


printf("qual sua altura em cm?\n");
scanf(" %d", &altura);
printf("qual seu sexo? <m> ou <f> ?\n");
scanf(" %c", &sexo1);
//t com problem n ordem que vc fala as alturas

if(sexo1=='f'){
    media+=altura;
    mulheres++;

    if(alturam2==0){
        alturam2=altura;
        }
    else{
        if(altura>=alturam2){
            malta=altura;
        }
        else{
            mbaixa=altura;
        }
    }
}
    else{
    homens++;
    if(alturah2==0){
        alturah2=altura;
    }
    else{
    if(altura>alturah2){
        halto=altura;
    }
    else{
        hbaixo=altura;
    }
    }
}

}

percent=(homens/n)-((n-homens)/n);
percent=percent*100;
media=media/mulheres;


printf("\n");
printf("a mulher mais baixa e mais alta tem %i e %i de altura\n", mbaixa, malta);
printf("o homem mais baixo e mais alto tem %i e %i de altura\n", hbaixo, halto);
printf("a altura media das mulheres eh %i\n", media); //ok
printf("o numero de homens eh %i\n", homens); //ok
printf("a diferença percentual entre homens e mulheres eh  %f %\n", percent); //ok
    return 0;
}