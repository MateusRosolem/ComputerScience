#include <stdio.h>

int main()
{int i, n;
scanf("%d", &n);
int X[n], Y[n];

for(i=0;i<n;i++)
{
scanf("%d %d",&X[i], &Y[i]);
}

for(i=0;i<n;i++)
{
    if(X[i]+Y[i]%2==0)
    {
        printf("A\n");
    }else
    {
        printf("B\n");
    }
}
}