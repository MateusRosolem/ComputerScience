#include <stdio.h>

int primo (int n){
    for(int i=2;i<=n/2;i++){
    if(n%i==0){
        return 0;
    }
    }
    return 1;
}


int main(){
    int n=12;
    printf("%d",primo(n));


    return 0;
}