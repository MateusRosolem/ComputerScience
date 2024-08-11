#include <stdio.h>
#include <math.h>
#include <string.h>

int i = 0, k = 0;

typedef struct
{
    char nome[21];
    double w;
    int x, y, z;
} planet;
planet planetas[10000];

double op1(char nomee1[21], char nomee2[21])
{
    i = 0, k = 0;
    while (strcmp(nomee1, planetas[i].nome) != 0)
    {
        i++;
    }
    while (strcmp(nomee2, planetas[k].nome) != 0)
    {
        k++;
    }
    int x[2] = {planetas[i].x, planetas[k].x}, y[2] = {planetas[i].y, planetas[k].y}, z[2] = {planetas[i].z, planetas[k].z};
    return sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2) + pow(z[1] - z[0], 2));
}

int op2(char nome[21])
{
    i = 0;
    while (strcmp(nome, planetas[i].nome) != 0)
    {
        i++;
    }
    return i;
}

double op3(char nome[21])
{
    i = 0;
    while (strcmp(nome, planetas[i].nome) != 0)
    {
        i++;
    }
    return planetas[i].w;
}

int main()
{
    int n, m, op, j;
    char nome1[21];
    char nome2[21];
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%s %lf %d %d %d", &planetas[i].nome, &planetas[i].w, &planetas[i].x, &planetas[i].y, &planetas[i].z);
    }

    for (j = 0; j < m; j++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%s %s", &nome1, &nome2);
            printf("%.2lf \n", op1(nome1, nome2));
        }
        else if (op == 2)
        {
            scanf("%s", &nome1);
            i = op2(nome1);
            printf("%d %d %d \n", planetas[i].x, planetas[i].y, planetas[i].z);
        }
        else if (op == 3)
        {
            scanf("%s", &nome1);
            printf("%.2lf \n", op3(nome1));
        }
    }
    return 0;
}
