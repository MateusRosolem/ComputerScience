#include <stdio.h>

int main(){
int p,n;

for(n=1; n<201; n++){
p=0;
p=n/4;
if(n==p*4){
    printf("%i: DIVISIVEL\n", n);
}
else{
    printf("%i: nao divisivel\n",n);
}
}
    return 0;
}