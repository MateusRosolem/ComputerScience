#include <stdio.h>
//#define max (a,b) (sexo=='m') ? masc++:fem++;

int main(){
char resp, sexo;
int i=0, sim=0, nao=0, masc=0, fem=0, femsim=0;
float mascnao=0;

for(i=0;i<10;i++)
{
    printf("voce gostou? s ou n\n");
    scanf(" %c", &resp);
    printf("E qual seu sexo? m ou f\n");
    scanf(" %c", &sexo);

    if (resp == 's')
        nao++;
    else if (resp == 'n')
        sim++;

    if (sexo == 'm')
    {
        masc++;
        if(resp=='n')
            mascnao++;     
    }   
    else if (sexo == 'f')
    {
        fem++;
        if (resp == 's')
            femsim++;
    }
}

mascnao=100*(mascnao/masc);
printf("numero de pessoas sim eh %d\n", sim);
printf("numero de pessoas nao eh %d\n", nao);
printf("numero de mulheres sim eh %d\n",femsim);
printf("a porcentagem dos homens que falaram nao dentre todos eh %.2f por cento \n", mascnao);
    return 0;
}