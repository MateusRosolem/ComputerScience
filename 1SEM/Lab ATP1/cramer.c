#include <stdio.h>

int main(){
    int a[3][3];
    int b[3][1];
    int x[3][1];
    //ax=b

    int mx[3][3];
    int my[3][3];
    int mz[3][3];

    int det=0, dp=0, ds=0;
    int detx=0,dety=0,detz=0;
    int i=0;


//LER MATRIZ A
    for(i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("digite um valor para matriz a na posicao [%d] [%d]", i, j);
            scanf("%d", &a[i][j]);

        }
    }

//LER MATRIZ B
        for( i=0;i<3;i++){
            printf("digite um valor para matriz b na posicao [%d] [0]", i);
            scanf("%d", &b[i][0]);
    }

//determinante
    //dp
    i=0;
        for(int j=0;j<3;j++){
            if(j==2){
                dp+=a[i][j]*a[i+1][j-2]*a[i+2][j-1];
            }
            else if (j==1){
                dp+=a[i][j]*a[i+1][j+1]*a[i+2][j-1];
            }
            else{
            dp+=a[i][j]*a[i+1][j+1]*a[i+2][j+2];
            }

            printf("valor dp[%d] \n", dp);
        }
printf("valor dp total[%d]\n", dp);

//ds
i=0;
        for(int j=2;j>-1;j--){
            if(j==0){
                ds+=a[i][j]*a[i+1][j+2]*a[i+2][j+1];
            }
            else if (j==1){
                ds+=a[i][j]*a[i+1][j-1]*a[i+2][j+1];
            }
            else{
            ds+=a[i][j]*a[i+1][j-1]*a[i+2][j-2];
            }
            
            printf("valor ds[%d] \n", ds);
        }
printf("valor ds total[%d]\n", ds);


det=dp-ds;
printf("valor det total[%d]\n", det);
printf("\n");



//CRAMER


    //DETX 
dp=0;
ds=0;

    for(i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mx[i][j]=a[i][j];
        }
    }
    mx[0][0]=b[0][0];
    mx[1][0]=b[1][0];
    mx[2][0]=b[2][0];


i=0;
        for(int j=0;j<3;j++){
            if(j==2){
                dp+=mx[i][j]*mx[i+1][j-2]*mx[i+2][j-1];
                printf("valor dp3:[%d] \n", dp);
            }
            else if (j==1){
                dp+=mx[i][j]*mx[i+1][j+1]*mx[i+2][j-1];
                printf("valor dp2::[%d] \n", dp);
            }
            else{

                dp+=mx[i][j]*mx[i+1][j+1]*mx[i+2][j+2];
                printf("valor dp1:[%d] \n", dp);
            }

            
        }
printf("valor dp totalX[%d]\n", dp);

//ds
        for(int j=2;j>-1;j--){
            if(j==0){
                ds+=mx[i][j]*mx[i+1][j+2]*mx[i+2][j+1];
            }
            else if (j==1){
                ds+=mx[i][j]*mx[i+1][j-1]*mx[i+2][j+1];
            }
            else{
            ds+=mx[i][j]*mx[i+1][j-1]*mx[i+2][j-2];
            }
            
            printf("valor ds[%d] \n", ds);
        }
printf("valor ds totalX[%d]\n", ds);

detx=dp-ds;
printf("valor detX total[%d]\n", detx);



    //DETY 
dp=0;
ds=0;

    for(i=0;i<3;i++){
        for(int j=0;j<3;j++){
            my[i][j]=a[i][j];
        }
    }
    my[0][1]=b[0][0];
    my[1][1]=b[1][0];
    my[2][1]=b[2][0];


i=0;
        for(int j=0;j<3;j++){
            if(j==2){
                dp+=my[i][j]*my[i+1][j-2]*my[i+2][j-1];
                printf("valor dp3:[%d] \n", dp);
            }
            else if (j==1){
                dp+=my[i][j]*my[i+1][j+1]*my[i+2][j-1];
                printf("valor dp2::[%d] \n", dp);
            }
            else{

                dp+=my[i][j]*my[i+1][j+1]*my[i+2][j+2];
                printf("valor dp1:[%d] \n", dp);
            }

            
        }
printf("valor dp totaly[%d]\n", dp);

//ds
        for(int j=2;j>-1;j--){
            if(j==0){
                ds+=my[i][j]*my[i+1][j+2]*my[i+2][j+1];
            }
            else if (j==1){
                ds+=my[i][j]*my[i+1][j-1]*my[i+2][j+1];
            }
            else{
            ds+=my[i][j]*my[i+1][j-1]*my[i+2][j-2];
            }
            
            printf("valor ds[%d] \n", ds);
        }
printf("valor ds totaly[%d]\n", ds);

dety=dp-ds;
printf("valor dety total[%d]\n", dety);



    //DETZ 
dp=0;
ds=0;

    for(i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mz[i][j]=a[i][j];
        }
    }
    mz[0][2]=b[0][0];
    mz[1][2]=b[1][0];
    mz[2][2]=b[2][0];


i=0;
        for(int j=0;j<3;j++){
            if(j==2){
                dp+=mz[i][j]*mz[i+1][j-2]*mz[i+2][j-1];
                printf("valor dp3:[%d] \n", dp);
            }
            else if (j==1){
                dp+=mz[i][j]*mz[i+1][j+1]*mz[i+2][j-1];
                printf("valor dp2::[%d] \n", dp);
            }
            else{

                dp+=mz[i][j]*mz[i+1][j+1]*mz[i+2][j+2];
                printf("valor dp1:[%d] \n", dp);
            }

            
        }
printf("valor dp totalz[%d]\n", dp);

//ds
        for(int j=2;j>-1;j--){
            if(j==0){
                ds+=mz[i][j]*mz[i+1][j+2]*mz[i+2][j+1];
            }
            else if (j==1){
                ds+=mz[i][j]*mz[i+1][j-1]*mz[i+2][j+1];
            }
            else{
            ds+=mz[i][j]*mz[i+1][j-1]*mz[i+2][j-2];
            }
            
            printf("valor ds[%d] \n", ds);
        }
printf("valor ds totalz[%d]\n", ds);

detz=dp-ds;
printf("valor detz total[%d]\n", detz);

printf("\n");
printf(" a matriz x eh");
x[0][0]=detx/det;
x[1][0]=dety/det;
x[2][0]=detz/det;
for(int j=0;j<3;j++){
    printf("[%d]", x[j][0]);
}
    return 0;
}