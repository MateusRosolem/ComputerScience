#include <stdio.h>

int cont=0, k=1,j=0, m=0,n=0;





void printar(int *discox)
{
    int i=0;
    while(discox[i]!=22)
    {
        printf("%d ", discox[i]);
        i++;
    }
    if(discox[0]==22)
        printf("0");
}

void hanoi(int n, int org[20], int aux[20], int dst[20], int cont,int i)
{
    while(cont!=k)
    {
        if(n==1)
        {
            //printf("%d\n", org[i-1]);
            printf("1\n");
            dst[m]=org[i];
            org[i]=22;
            i--;
            m++;
            cont++;
        }
        else
        {
            printf("passou auqi");
           // printf("%d\n", org[i-1]);
            hanoi(n-1, org[20], dst[20], aux[20], cont,i);
            printf("ELSE\n");
            dst[m]=org[i];
            org[i]=22;
            i--;
            m++;
            cont++;
            hanoi(n-1, aux[20], org[20], dst[20], cont,i);
            // printf("%d|%d|%d\n", org, aux, dst);
        }
    }
    printar(org[20]);
    printf("\n");
    printar(aux[20]);
    printf("\n");
    printar(dst[20]);
}



int main(){
int o[20]={22}, a[20]={22}, d[20]={22}, i=0;

scanf("%d %d", &n, &k);

p1 = malloc(n * sizeof(int));


for(i=1;i<=n;i++)
    o[i-1]=i;
hanoi(n, o[20], a[20], d[20], cont,i);


    return 0;
}