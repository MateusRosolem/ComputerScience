#include <stdio.h>

int main(){
int n, n1=1, n2=1, num=0;

for(n=1; n<16;n++){

if(num==0 || num==1){
    printf("1\n");
}
else{
    n2=n1;
    n1=num-1;
    num=n1+n2;
    printf("%i\n",num);
}

num++;
}

    return 0;
}

//1 1 2 3 5 8