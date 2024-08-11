#include <stdio.h>

int main(){
char pal[100];
int i=0, esp=1;

scanf(" %[^\n]", &pal);

while(pal[i]!='\0'){
    if(pal[i]==' ')
        esp++;
    i++;
}
printf("a quantidade de espacos eh %d\n", esp);

    return 0;
}