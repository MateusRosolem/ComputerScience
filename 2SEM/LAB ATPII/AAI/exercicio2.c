#include <stdio.h>

int main(){
int inscricao, idade, sexo, anoexper;
int experientesm=0, experientesf=0, idososm=0, totalm=0, idadem=0;
float percent=0;


while(1==1){
    printf("qual numero de inscricao?\n");
    scanf(" %d", &inscricao);
    if(inscricao==0) break;
    printf("qual sua idade?\n");
    scanf(" %d", &idade);
    printf("qual seu sexo? (1-masculino ou 2-feminino)\n");
    scanf(" %d", &sexo);
    printf("quantos anos de experiência tem?\n\n");
    scanf(" %d", &anoexper);
    //t com problem n ordem que vc fala as alturas

    if(sexo==1){
    totalm++;
        if(anoexper>2)
            idadem+=idade;
            experientesm++;
        if(idade>45)
            idososm++;
    }
    else{
        if(idade<35 && anoexper!=0)
            experientesf++;
    }

}
percent=idososm/totalm;


printf("\n");
printf("\nA idade media dos homens com mais de 2 anos de experiencia no servico eh de %d\n", idadem/experientesm);
printf("A porcentagem dos homens com mais de 45 anos entre o total de homens eh de %.2f %\n", percent*100);
printf("O numero de mulheres que tem idade inferior a 35 e com experiencia de ervico eh de %d\n", experientesf);
    return 0;
}