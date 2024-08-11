// Bibliotecas inclusas
#include <stdio.h>
#include <string.h>

int main()
{
    // Declaração de variáveis para armazenar os números, palavras, contadores temporários(além dos ponteiros dos arquivos)
    FILE *fp1, *fp2, *fpfinal;
    int num=0,i=0,j=0;
    char pal[50], carac;

    // Leitura dos números do CODIGO.DAT 
    fp1 = fopen("codigos.dat", "r");

    // Leitura das palavras do PALAVRAS.DAT 
    fp2 = fopen("palavras.dat", "r");

    //Cria um arquivo (em modo escrita) LINHAS.DAT para armazenar os resultados de saída
    fpfinal= fopen("linhas.dat", "w");

    
while(feof(fp1)==0)
{     
    if(feof(fp2))//Verifica quando o arquivo das palavras chegou ao fim,sai do while principal e imprime o resto dos numeros
    {
        do
        {
        fscanf(fp1,"%d", &num);
        fprintf(fpfinal,"%d ", num);
        } while(feof(fp1)==0);
        break;

    }

    fscanf(fp1, "%d", &num);//Recebe e Imprime as palavras de acordo com o respectivo número
    if(num>0) //Maior que 0
    {
        for(i=0;i<num;i++)
        {
            if(feof(fp2))//Sai do for caso acabe as palavras no meio do print
                break;
            fscanf(fp2,"%s", pal);
            fprintf(fpfinal,"%s ",pal);
        }
        fprintf(fpfinal,"\n");
    }
    else if(num<0)//Menor que 0
    {
        for(i=0;i>num;i--)//Voltar os caracteres
        {
            if (i < 0)
            {
                fseek(fp2, -1, SEEK_CUR);
            }
            do
            {
                fseek(fp2, -1, SEEK_CUR);
                fscanf(fp2, "%c", &carac);
                if (carac != ' ')
                {
                    fseek(fp2, -1, SEEK_CUR);
                }
            } while (carac != ' ');
        }

        for(i=0;i>num;i--)//printar
        {

            fscanf(fp2,"%s", pal);
            fprintf(fpfinal,"%s ", pal);
            
        }
        fprintf(fpfinal,"\n");
    }
    else if(num==0) //Igual a 0
    {
        fprintf(fpfinal,"0 \n");
    }
}


while(feof(fp2)==0 && feof(fp1)!=0) //Verifica quando o arquivo dos codigos chegou ao fim, e imprime o resto das palavras
{
    if (j % 5 == 0 && j != 0)
    {
        fprintf(fpfinal, "\n");
    }
    fscanf(fp2,"%s", pal);
    fprintf(fpfinal,"%s ", pal);
    j++;
}

    // Fechamento dos arquivos abertos para leitura
    fclose(fp1);
    fclose(fp2);
    fclose(fpfinal);
    return 0;
}