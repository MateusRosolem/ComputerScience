#include <stdio.h>

int romanopradec(char *numromano)
{
    int soma=0,i=0,j=0,v[30],cont=0;

    while(numromano[i]!='\0')
    {
    
        if(numromano[i]=='M')
        {    v[j]=1000;
            j++;
        }else if(numromano[i]=='D')
        {    v[j]=500;
            j++;
        }else if(numromano[i]=='C')
        {    v[j]=100;
            j++;
        }else if(numromano[i]=='L')
        {    v[j]=50;
            j++;
        }else if(numromano[i]=='X')
        {    v[j]=10;
            j++;
        }else if(numromano[i]=='V')
        {    v[j]=5;
            j++;
        }else if(numromano[i]=='I')
        {    v[j]=1;
            j++;
        }

        if(v[i]>v[i-1] && i!=0 )
        {   
            soma-=v[i-1];
            soma+=(v[i]-v[i-1]);
        }
        else{
            soma+=v[i];
        } 

        i++;
    }
    return soma;
}



void decimalprarom(int numero)
{
int i=0, cont=0;
char romano[20]="";

    while (numero != 0)
    {
        if (numero >= 1000)
        {
            numero = numero - 1000;
            romano[cont] = 'M';
            cont++;
        }
        else if (numero >= 900) 
        {
            numero = numero - 900;
            romano[cont] = 'C';
            romano[cont+1] = 'M';
            cont += 2;
        }
        else if (numero >= 500)
        {
            numero = numero - 500;
            romano[cont] = 'D';
            cont++;
        }
        else if (numero >= 400) 
        {
            numero = numero - 400;
            romano[cont] = 'C';
            romano[cont+1] = 'D';
            cont += 2;
        }
        else if (numero >= 100)
        {
            numero = numero - 100;
            romano[cont] = 'C';
            cont++;
        }
        else if (numero >= 90) 
        {
            numero = numero - 90;
            romano[cont] = 'X';
            romano[cont+1] = 'C';
            cont += 2;
        }
        else if (numero >= 50)
        {
            numero = numero - 50;
            romano[cont] = 'L';
            cont++;
        }
        else if (numero >= 40) 
        {
            numero = numero - 40;
            romano[cont] = 'X';
            romano[cont+1] = 'L';
            cont += 2;
        }
        else if (numero >= 10)
        {
            numero = numero - 10;
            romano[cont] = 'X';
            cont++;
        }
        else if (numero >= 9) 
        {
            numero = numero - 9;
            romano[cont] = 'I';
            romano[cont+1] = 'X';
            cont += 2;
        }
        else if (numero >= 5)
        {
            numero = numero - 5;
            romano[cont] = 'V';
            cont++;
        }
        else if (numero >= 4) 
        {
            numero = numero - 4;
            romano[cont] = 'I';
            romano[cont+1] = 'V';
            cont += 2;
        }
        else if (numero >= 1)
        {
            numero = numero - 1;
            romano[cont] = 'I';
            cont++;
        }
    }
    printf("%s\n", romano);
}


int main(){
int n, i=0,c=0 ,somaromanos=0,j=0,num=0, numromano=0;
char romano[15]="";


scanf("%d", &n);
for(i=0;i<n;i++)
{
    scanf("%d", &c);
    if(c==1)
    {
        scanf("%s", romano);
        numromano=romanopradec(romano);
        printf("%d\n",numromano);
        somaromanos+=numromano;
    }
    else if(c==2)
    {
        scanf("%d", &num);
        decimalprarom(num);
    }
}
printf("%d\n", somaromanos);
    return 0;
}