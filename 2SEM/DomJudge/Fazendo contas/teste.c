#include <stdio.h>
#include <string.h>
int main()
{char a[1001];
char p[1001];
int i=0,k=0;


do{scanf(" %c", &a[i]);
    if(a[i]=='{' || a[i]=='(' || a[i]=='[' || a[i]==']'|| a[i]==')' || a[i]=='}')
        {p[k]=a[i];
        }   
    if(i!=0 && (p[k]==']'|| p[k]==')' || p[k]=='}') ){
        if(p[k]==']'  && p[k-1]=='[')
        {i=i-2;
        }
        else if(p[k]=='}'  && p[k-1]=='{')
        {i=i-2;
        }
        else if(p[k]==')'  && p[k-1]=='(')
        {i=i-2;
        }
        else
        {puts(p);
            printf("N");
            return 0;
        }
    }
    k++;
    i++;
    printf("valor de i:%d\n", i);
}while(a[i-1]!='\0');
printf("S");
return 0;
}