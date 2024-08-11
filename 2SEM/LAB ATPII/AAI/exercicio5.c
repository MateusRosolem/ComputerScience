#include <stdio.h>

int main(){
int v[18], a[3][6];
int i=0, j=0;
int *p;
p=&a;

for(i=0;i<18;i++){
    scanf("%d", &v[i]);
    *p=v[i];
    p++;
}
    return 0;
}