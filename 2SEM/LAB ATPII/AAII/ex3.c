#include <stdio.h>



int main(){
char pal[100];
int i=0;
int cons=0, CONS=0;

scanf(" %[^\n]", &pal);

while(pal[i]!='\0'){
    if(pal[i]>96 && pal[i]<123){
        if(pal[i]!='a' && pal[i]!='e' && pal[i]!='i' && pal[i]!='o' && pal[i]!='u'){
            cons++;
        }
    }
    else if(pal[i]>64 && pal[i]<91){
        if(pal[i]!='A' && pal[i]!='E' && pal[i]!='I' && pal[i]!='O' && pal[i]!='U' ){
            CONS++;
        }
    }
    i++;
}
printf("o numero de consoantes minusculas eh %d \n", cons);
printf("o numero de consoantes maiusculas eh %d \n", CONS);
printf("o numero de consoantes eh %d \n", CONS+cons);

    return 0;
}