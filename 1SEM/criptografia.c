#include <stdio.h> 

int main () {
    int x;
    int a,b;
    int c,d;
    char frase[50];
    int cripto[50];
    int descripto[50];
    int i,n;
    char carac;
    int aux;
    
printf("digte a frase desejada\n");
scanf("%s", &frase);

printf("digite o A e B para a funcao ax+b \n");
scanf("%i %i", &a, &b);




printf("\n sua frase digitada em numeros eh: \n");
for(i=0; frase[i]!='\0'; i++){
    carac=frase[i];
    cripto[i]=carac-97;
    printf("%d ", cripto[i]);
}

printf("\n sua frase digitada em numeros criptografados eh: \n");
for(aux=i, i=0; aux!=i; i++){
    cripto[i]=(a*cripto[i]+b)%26;
    printf("%d ", cripto[i]);
}

printf("\n sua frase digitada em frase criptografada eh: \n");
for(i=0; aux!=i; i++){
    cripto[i]+=97;
    printf("%c ", cripto[i]);
}
printf("\n");
printf("\n");


printf("\n sua frase criptografada digitada em numeros eh: \n");
for(i=0; frase[i]!='\0'; i++){
    cripto[i]=cripto[i]-97;
    printf("%d ", cripto[i]);
}

printf("\n");
printf("\n");

for( i=0; (a*c)%26!=1 ;i++){
    c=i;
}
for( i=0; ((a*d)+b)%26!=0 ;i++){
    d=i;
}
printf("\nsua funcak inversa eh %dx+%d \n", c,d);

printf("\n sua frase DEScriptografada digitada em numeros eh: \n");
for(i=0; frase[i]!='\0'; i++){
    cripto[i]=(c*cripto[i]+d)%26;
    printf("%d ", cripto[i]);
}
printf("\n sua frase digitada em frase DEScriptografada eh: \n");
for(i=0; aux!=i; i++){
    cripto[i]+=97;
    printf("%c ", cripto[i]);
}


//trasnformar os numeros de cima  em outros numeros, jogando na formula e depois mod 26( e depois fazer numero+97(pra transformar em ascii mas criptografado))

//feito

//transformar as letras em numeros-97(que é do 0 ao 25),depois jogar na formula inversa e fazer mod 26,depois trasn e só ai transformar os numeros 


    










    return 0;
}