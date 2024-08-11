#include <stdio.h>
#include <string.h>
int main()
{char a[1001];
char p[1001];
int i=0,k=0;
int aux;

do{scanf(" %c", &a[i]);
    if(a[i]=='{' || a[i]=='(' || a[i]=='[' || a[i]==']'|| a[i]==')' || a[i]=='}')
        {p[k]=a[i];

        }   

aux=0;
while(p[aux]!='\0')
    {printf("%c", p[aux]);
   printf("AI %c", a[aux]);
    aux++;
    }
    if(i!=0 && (p[k]==']'|| p[k]==')' || p[k]=='}') ){
        if(p[k]==']'  && p[k-1]=='[')
        {k=k-2;
        }
        else if(p[k]=='}'  && p[k-1]=='{')
        {k=k-2;
        }
        else if(p[k]==')'  && p[k-1]=='(')
        {k=k-2;
        }
        else
        {printf("N");
            return 0;
        }
    }
    k++;
    printf(" valor de i:%d", i);
    printf(" valor de k: %d\n", k);
    i++;
}while(a[i-1]!='\0');
printf("S");
return 0;
}