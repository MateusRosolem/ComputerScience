#include <stdio.h>
#include <stdlib.h>
int n, cont=0, *p1, *p2, *p3;
int qntd[3]={0};

void hanoi(int org, int dst, int aux, int quantidade, int max){
  int *porg, *pdst, i;

  if (cont<max)
  {
    if(quantidade == 1)
    {
        qntd[org]--;
        qntd[dst]++;

        switch (org)
        {   
            case 0:porg = p1; break;
            case 1:porg = p2; break;
            case 2:porg = p3; break;
        }

        switch (dst)
        {   
            case 0:pdst = p1; break;
            case 1:pdst = p2; break;
            case 2:pdst = p3; break;
        }

        i = 0;
        while(!porg[i])
            i++;

        porg[i] = 0;
        pdst[i] = 1;

        cont++;
    }
    else
    {
        hanoi(org, aux, dst, quantidade-1, max);
        hanoi(org, dst, aux, 1, max);
        hanoi(aux, dst, org, quantidade-1, max);
    }
  }
}


void printar(int *p)
{   int find, i;
    
    find=0;    
    for (i=0;i<n; i++)
    {   
        if (p[i] == 1)
        {   
            printf("%d ", i+1);
            find=1;
        }
        else if (i == n-1 && p[i] == 0 && !find)
            printf("0");
    }
    printf("\n");

}




int main()
{   
    int k, i;

    scanf("%d %d", &n, &k);
    qntd[0] = n;

    p1=malloc(n*sizeof(int));
    p2=malloc(n*sizeof(int));
    p3=malloc(n*sizeof(int));

    for (i=0; i<n; i++)
    {   
        p1[i] = 1;
        p2[i] = p3[i] = 0;
    }

    hanoi(0, 2, 1, n, k);
            
    printar(p1);
    printar(p2);
    printar(p3);



    return 0;
}

