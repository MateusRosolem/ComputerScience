#include <stdio.h>

int main(){
char scpf[12], c;
int cpf[11], i;
int flag=0;

int soma=0;
int soma2=0;

printf("digite um CPF sem pontos e tracos\n");
scanf("%s", &scpf);

for(i=0; i<11; i++){
    c=scpf[i];
    cpf[i]=c-'0';
}



for(i=0;i<10;i++){
    if(cpf[i]!=cpf[i+1]){
        flag=1;
    }
}

if(flag==0){
    printf("cpf invalido\n");
}
else{
    printf("cpf valido\n");
}



for(i=0;i<9;i++){
soma+= cpf[i]*(10-i);
soma2+= cpf[i]*(11-i);
}
soma=soma*10;

if(soma%11==10){
    soma=0;
}

if(soma%11 ==cpf[9]){
    printf("digito verificado\n");
    }
    else{
        printf("cpf invalido\n");
        return 0;
    }


soma2+=cpf[9]*2;
soma2=soma2*10;

if(soma2%11 == cpf[10]){
    printf("CPF TOP\n");
}
else{
    printf("cpf errado brow\n");
}







    return 0;
}