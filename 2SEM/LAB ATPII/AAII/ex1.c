#include <stdio.h>
#include <string.h>
/*Este programa deve permitir incluir alunos no arquivo criado, lembrando que não podem existir dois alunos 
com o mesmo número. Além disso, deve permitir alterar as notas dos alunos do arquivo criado.*/


typedef struct{
    int numero;
    char nome[20];
    char curso[20];
    float nota1;
    float nota2;
}reg;



void adicionar(FILE *fp){
    int numero;
    char nome[20];
    char curso[20];
    float nota1;
    float nota2;

fp=fopen("ALUNOS.DAT", "a");

printf("Digite o numero do aluno\n");
scanf("%d", &numero);
fprintf(fp,"%d\n", numero);

printf("Digite o nome do aluno\n");
scanf(" %s", &nome);
fprintf(fp,"%s\n", nome);

printf("Digite o curso do aluno\n");
scanf(" %s", &curso);
fprintf(fp,"%s\n", curso);

printf("Digite a nota 1 do aluno\n");
scanf("%f", &nota1);
fprintf(fp,"nota1%.1f\n", nota1);

printf("Digite a nota 2 do aluno\n");
scanf("%f", &nota2);
fprintf(fp,"nota2%.1f\n", nota2);

fclose(fp);
}






void mudarnota(FILE *fp){
    reg alunos[1000];
    int j,i=0;
    char nome[10];

    fp = fopen("ALUNOS.dat", "r");
    while(!feof(fp)) {
        fscanf(fp,"%d", &alunos[i].numero);
        fscanf(fp,"%s", &alunos[i].nome);
        fscanf(fp,"%s", &alunos[i].curso);
        fscanf(fp,"%f %f",&alunos[i].nota1,&alunos[i].nota2);
        i++;
    }
    fclose(fp);


    fp = fopen("ALUNOS.dat", "w");
    printf("Digite o nome do aluno que vai trocar as notas:\n");
    scanf("%s", nome);

    for(j=0;j<i;j++) {
        if(strcmp(nome,alunos[j].nome) == 0) {
            printf("Digite as notas N1 e N2\n");
            scanf("%f %f",&alunos[j].nota1,&alunos[j].nota2);
        }
    }

    for(j=0;j<i;j++){
        fprintf(fp,"%d",alunos[j].numero);
        fprintf(fp,"%s",alunos[j].nome);
        fprintf(fp,"%s",alunos[j].curso);
        fprintf(fp,"%.1f\n%.1f ",alunos[j].nota1,alunos[j].nota2);
    }
    fclose(fp);

}

int main(){
FILE *fp1;
int op;

fp1=fopen("ALUNOS.DAT", "w");

while(op!=3){
    printf("O que deseja fazer?\n1 - Adicionar aluno\n2 - Mudar Registro\n3 - Sair\n");
    scanf("%d", &op);

    switch (op){
    case 1:adicionar(fp1);break;
    case 2:mudarnota(fp1);break;
    case 3:break;
    default:break;
    }
}

fclose(fp1);
    return 0;
}