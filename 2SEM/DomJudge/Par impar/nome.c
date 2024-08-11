#include <stdio.h>

int main()
{int i, n, X, Y;
scanf("%d", &n);

for(i=0;i<n;i++)
{scanf("%d %d", &X, &Y);
    if((X+Y)%2==0)
    {
        printf("A\n");
    }else
    {
        printf("B\n");
    }
}
return 0;
}