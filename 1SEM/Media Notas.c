#include <stdio.h>
#define n 8 //numero de materias

int main(){
float , fisica=0, calculo=0, atp=0, discreta=0, logica=0, labatp=0, icc=0;
float p1[8], p2[8], proj=0;
float rel[2];
char signal[10];
float cr=0;




printf("Qual sua nota da P1 em Metodologia?\n");
scanf("%f", &p1[0]);
printf("Ja fez o Projeto? 's' ou 'n' \n");
scanf(" %c", &signal[0]);
if (signal[0]=='n'){         //Antes da P2
proj=(7-(0.6*p1[0]))/0.4;
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", proj);
}
else {       //com a nota da P2
printf("Qual sua nota do Projeto em Metodologia?\n");
scanf("%f", &proj);
met=0.6*p1[0]+0.4*proj;
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");


printf("Qual sua nota da P1 em Fisica?\n");
scanf("%f", &p1[1]);
printf("Qual sua nota do Relatorio1 em Fisica?\n");
scanf("%f", &rel[0]);
printf("Qual sua nota do Relatorio2 em Fisica?\n");
scanf("%f", &rel[1]);

printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[1]);
if (signal[1]=='n'){         //Antes da P2
p2[1]=(7-(0.4*p1[1])-0.2*((rel[0]+rel[1])/2))/0.4;
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[1]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em Fisica?\n");
scanf("%f", &p2[1]);
fisica=0.8*((p1[1]+p2[1])/2) + 0.2*((rel[0]+rel[1])/2);
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");


printf("Qual sua nota da P1 em Calculo?\n");
scanf("%f", &p1[2]);
printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[2]);
if (signal[2]=='n'){         //Antes da P2
p2[2]=(2*7)-p1[2];
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[2]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em Calculo?\n");
scanf("%f", &p2[2]);
calculo=(p1[2]+p2[2])/2;
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");


printf("Qual sua nota da P1 em ATP?\n");
scanf("%f", &p1[3]);
printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[3]);
if (signal[3]=='n'){         //Antes da P2
p2[3]=(7-(0.3*p1[3]))/0.7;
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[3]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em ATP?\n");
scanf("%f", &p2[3]);
atp=0.3*p1[3]+0.7*p2[3];
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");


printf("Qual sua nota da P1 em Discreta?\n");
scanf("%f", &p1[4]);
printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[4]);
if (signal[4]=='n'){         //Antes da P2
p2[4]=(2*7)-p1[4]; 
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[4]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em Discreta?\n");
scanf("%f", &p2[4]);
discreta=(p1[4]+p2[4])/2;
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");

printf("Qual sua nota da P1 em Logica?\n");
scanf("%f", &p1[5]);
printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[5]);
if (signal[5]=='n'){         //Antes da P2
p2[5]=(2*7)-p1[5]; 
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[5]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em Logica?\n");
scanf("%f", &p2[5]);
logica=(p1[5]+p2[5])/2;
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");


printf("Qual sua nota da P1 em LabATP?\n");
scanf("%f", &p1[6]);
printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[6]);
if (signal[6]=='n'){         //Antes da P2
p2[6]=(2*7)-p1[6]; 
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[6]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em LabATP?\n");
scanf("%f", &p2[6]);
labatp=(p1[6]+p2[6])/2;
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");


printf("Qual sua nota da P1 em ICC?\n");
scanf("%f", &p1[7]);
printf("Ja fez a P2? 's' ou 'n' \n");
scanf(" %c", &signal[7]);
if (signal[7]=='n'){         //Antes da P2
p1[7]=((3*7)-p1[7])/2; 
printf("pra ir com MEDIA 7, vc precisa de %f na P2\n", p2[7]);
}
else {       //com a nota da P2
printf("Qual sua nota da P2 em ICC?\n");
scanf("%f", &p2[7]);
icc=(p1[7]+2*p2[7])/3;
}
printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n");

printf("=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=\n");
    printf("Sua nota em Metodologia eh %f \n",met);
    printf("Sua nota em Fisica eh %f \n",fisica);
    printf("Sua nota em Calculo eh %f \n",calculo);
    printf("Sua nota em ATP eh %f \n",atp);
    printf("Sua nota em Discreta eh %f \n",discreta);
    printf("Sua nota em Logica eh %f \n",logica);
    printf("Sua nota em Lab ATP eh %f \n",labatp);
    printf("Sua nota em ICC eh %f \n", icc);
    printf("\n");
    cr=(met+fisica+calculo+atp+discreta+logica+labatp+icc)/n;
    printf("Seu coeficiente de rendimento foi: %f \n",cr);
    return 0;
}