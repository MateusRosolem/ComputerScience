#include <stdio.h>



int main(){
char pal[100];
int i=0;
int vog=0, VOG=0;

scanf(" %[^\n]", &pal);

while(pal[i]!='\0'){
    if(pal[i]=='a' || pal[i]=='e' || pal[i]=='i' || pal[i]=='o' || pal[i]=='u' ){
        vog++;
    }
    if(pal[i]=='A' || pal[i]=='E' || pal[i]=='I' || pal[i]=='O' || pal[i]=='U' ){
        VOG++;
    }
    i++;
}

printf("o numero de vogais minusculas eh %d \n", vog);
printf("o numero de vogais maiusculas eh %d \n", VOG);
printf("o numero de vogais eh %d \n", VOG+vog);

    return 0;
}