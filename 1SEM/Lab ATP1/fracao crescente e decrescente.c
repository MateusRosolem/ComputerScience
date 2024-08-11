#include <stdio.h>

int main(){
    float n;
    float s=0;

    printf("diga um valor de n\n");
    scanf("%f", &n);

    for(int i=1, j=0; i<=n; i++, j++){
        s+=(n-j)/i;
    
        printf("fracao %f\n", s);
    }
 printf("%f", s);

    return 0;
}