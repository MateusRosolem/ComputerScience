#include <stdio.h>
#include <math.h>

int main()
{int p[3]={0,0,0}, n, k=0, i;
scanf("%d %d", &n, &k);

p[0]=n;
if(n%2==0)
    i=0;
else
    i=1;
if(k!=0)
{p[1+i]++;
    p[0]--;
    k--;
    printf("%d %d %d\n", p[0], p[1], p[2]);




while(k>0 && k>=(pow(2,n))/2)
{if(k>0)  
    {
        p[2-i]++;
        p[0]--;
        k--;
    }
    printf("%d %d %d\n", p[0], p[1], p[2]);

    if(k>0)
    {
        p[2-i]++;
        p[1+i]--;
        k--;
    }
    printf("%d %d %d\n", p[0], p[1], p[2]);
    printf("\n");

}
    p[2]++;
    p[0]--;
    k--;

while(k>0)
{if(k>0)  
    {

    }
    printf("%d %d %d\n", p[0], p[1], p[2]);

    if(k>0)
    {
        p[2-i]++;
        p[1+i]--;
        k--;
    }
    printf("%d %d %d\n", p[0], p[1], p[2]);
    printf("\n");

}





}
printf("\n");
printf("%d %d %d\n", p[0], p[1], p[2]);
return 0;
}