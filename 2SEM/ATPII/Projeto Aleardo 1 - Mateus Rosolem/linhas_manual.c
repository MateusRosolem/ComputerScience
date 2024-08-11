// Bibliotecas inclusas
#include <stdio.h>
#include <string.h>
#define n 10000

int main()
{
    // Declaração de variáveis para armazenar os números, palavras, contadores e outras variáveis auxiliares além dos ponteiros dos arquivos)
    int v[n];
    char s[n];
    int i = 0, j = 0, p = 0, totalpalavras = 0, totalcont = 0, palavras = 1, cont = 0, esp=0;
    FILE *fp1, *fp2, *fpfinal;

    // Leitura dos números do CODIGO.DAT e armazena em um vetor v[i] no arquivo principal
    fp1 = fopen("codigos.dat", "r");
    do
    {
        fscanf(fp1, "%d", &v[i]);
        i++;
        cont++;
    } while (feof(fp1) == 0);
    totalcont = cont;

    // Leitura das palavras do PALAVRAS.DAT e armazena em um vetor s[n] no arquivo principal
    i = 0;
    fp2 = fopen("palavras.dat", "r");
    do
    {
        fscanf(fp2, "%c", &s[i]);
        if (s[i] == ' ')
            palavras++;
        i++;
    } while (feof(fp2) == 0);
    totalpalavras=palavras;

    //Cria um arquivo LINHAS.DAT para armazenar os resultados de saída
    fpfinal= fopen("linhas.dat", "w");

    // Imprime as palavras de acordo com o respectivo número
    i = 0;
    while (palavras != 0 && cont != 0)
    {
        if (s[p] == '\0')
        {
            break;
        }
        if (v[i] > 0) // se número maior que zero
        {
            for (j = 0; j < v[i]; j++)
            {
                while (s[p] != ' ' && s[p] != '\0')
                {
                    fprintf(fpfinal,"%c", s[p]);
                    p++;
                }
                if (s[p] == ' ')
                {
                    fprintf(fpfinal," ");
                }
                p++;
                palavras--;
            }
            fprintf(fpfinal,"\n");
            cont--;
        }
        else if (v[i] < 0) // se numero < 0
        {
            p--;
            for (j = 0; j > v[i]; j--)
            {
                do
                {
                    p--;
                } while (s[p] != ' ');
                palavras++;
            }
            for (j = 0; j > v[i]; j--)
            {
                p++;
                while (s[p] != ' ' && s[p] != '\0')
                {
                    fprintf(fpfinal,"%c", s[p]);
                    p++;
                }
                if (s[p] == ' ')
                {
                    fprintf(fpfinal," ");
                }
                palavras--;
            }
            p++;
            cont--;
            fprintf(fpfinal,"\n");
        }
        else if (v[i] == 0) // se igual a zero
        {
            fprintf(fpfinal,"0 \n");
            cont--;
        }
        i++;
    }

    // Verificador de sobra de números ou palavras
    if (palavras == 0) // Sobram números, imprime os números
    {
        while (cont > 0)
        {
            fprintf(fpfinal,"%d ", v[totalcont - cont]);
            cont--;
            p++;
        }
    }
    else if (cont == 0) // Sobram Letras, impreme as palavras
    {
        for (j = 0; j < (totalpalavras - palavras); j++)
        {

            if(j%5==0 && j!=0)
            {
                fprintf(fpfinal,"\n");
            }
            while (s[p] != ' ')
            {
                if (s[p] == '\0')
                {
                    break;
                }
                fprintf(fpfinal,"%c", s[p]);
                p++;
            }
            if (s[p] == ' ')
            {
                fprintf(fpfinal," ");
                p++;
                esp++;
            }
        }
    }

    // Fechamento dos arquivos abertos para leitura
    fclose(fp1);
    fclose(fp2);
    fclose(fpfinal);
    return 0;
}