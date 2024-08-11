#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 2 

//printf(FALTA ARRUMAR  ORDENACAO POR SALDO)

int main(){
	float mediah=0;
	float mediam=0;

	int indexidade=0;
	int indexlimite=0;
	
	float maiorm=0;
	float menorm=0;
	
	float menorh=0;
	float maiorh=0;
	
	int indexclienteneg[n];
    int saldos[n];
    float aux;
    int indiceaux;
	
    int i=0;
	srand( (unsigned)time(NULL));
	



typedef struct dat{
	int dia;
	int mes;
	int ano;
	}dataab;

typedef struct cont{
	int nconta;
	dataab data;
	float saldo;
	int lim_esp;
	}contacliente;
	
typedef struct dados_pessoais{
	char nome[50];
	char sobrenome[50];
	char sexo;
	contacliente conta;
	}clientex;


clientex cliente[n];



//entrada
for(int i=0;i<n;i++){
	printf("Qual seu nome?");
	scanf(" %[^\n]s", &cliente[i].nome);
	printf("Qual seu sobrenome?");
	scanf(" %[^\n]s", &cliente[i].sobrenome);
	printf("Qual seu sexo? 'm' ou 'f'?");
	scanf(" %c", &cliente[i].sexo);
	printf("qual o DIA MES e ANO da abertura da conta?(nascimento)");
	scanf("%d %d %d", &cliente[i].conta.data.dia, &cliente[i].conta.data.mes, &cliente[i].conta.data.ano);




	//tratamento de dados ABERTURA CONTA-> IDADE
	cliente[i].conta.data.dia=30-cliente[i].conta.data.dia;
	if(cliente[i].conta.data.mes>=7){
		cliente[i].conta.data.mes=(12-cliente[i].conta.data.mes)+7;
		cliente[i].conta.data.ano=2021-cliente[i].conta.data.ano;
	}
	else{
		cliente[i].conta.data.mes=7-cliente[i].conta.data.mes;
		cliente[i].conta.data.ano=2022-cliente[i].conta.data.ano;
	}
	
	printf("(vc tem %d anos %d meses e %d dias)", cliente[i].conta.data.ano,  cliente[i].conta.data.mes,  cliente[i].conta.data.dia);
	printf("\n");

	if(i==0){
	indexidade=i;
	}
	else if(cliente[i].conta.data.ano>cliente[i-1].conta.data.ano && cliente[i].conta.data.mes>cliente[i-1].conta.data.mes && cliente[i].conta.data.dia>cliente[i-1].conta.data.dia){
		indexidade=i; 
	}


	cliente[i].conta.lim_esp=(rand()%10)+1000;
	if(i==0){
	indexlimite=i;
	}
	else if(cliente[i].conta.lim_esp>cliente[i-1].conta.lim_esp){
		indexlimite=i;
	}




	printf("qual seu saldo?");
	scanf("%f", &cliente[i].conta.saldo);
    saldos[i]=i;

	if(cliente[i].conta.saldo<0){
	indexclienteneg[i]=i;
	}
    else{
        indexclienteneg[i]=0;
    }

}
//index saldo[i]
//ordenar cliente[index]saldo

//ORDENAÇÃO
for (int k = 1; k < n; k++){
    aux=cliente[k].conta.saldo;
    indiceaux=saldos[k];
	for (i=k-1; i >= 0 && aux<cliente[i].conta.saldo; i--){
		saldos[i+1]=saldos[i]; 
	}
    saldos[i+1]=indiceaux;
}
//saldos qu eh vetor de INDEX fica desordenado, mas a indexação dele vai ser ordenada pelo saldos crescentes



//PROCESSAMENTO 
for(int i=0; i<n;i++){

	if(cliente[i].sexo =='m'){
		if(i==0){
			maiorh=cliente[i].conta.saldo;
			menorh=cliente[i].conta.saldo;
		}
		else if(cliente[i].conta.saldo>maiorh){
			maiorh=cliente[i].conta.saldo;
		}
		else if(cliente[i].conta.saldo<menorh){
			menorh=cliente[i].conta.saldo;
		}// PODERIA NAO USAR ISSO PRA SABER QUEM EH O MENOR E O MAIOR E FAZER DEPOIS DE ORDENAR POR ORDEM CRESCENTE O SALDO DOS CLIENTES
		mediah+=cliente[i].conta.saldo;
	}

	else{
		if(i==0){
			maiorm=cliente[i].conta.saldo;
			menorm=cliente[i].conta.saldo;
		}
		else if(cliente[i].conta.saldo>maiorm){
			maiorm=cliente[i].conta.saldo;
		}
		else if(cliente[i].conta.saldo<menorm){
			menorm=cliente[i].conta.saldo;
		}
		mediam+=cliente[i].conta.saldo;
	}

}


//SAIDA
	printf("\n");
	printf("MAIOR SALDO HOMENS:%f", maiorh);
	printf("\n");
	mediah=mediah/n;
	printf("SALDO MEDIO HOMENS:%f", mediah);
	printf("\n");
	printf("MENOR SALDO HOMENS:%f", menorh);
	printf("\n");

	printf("MAIOR SALDO MULHERES:%f", maiorm);
	printf("\n");
	mediam=mediam/n;
	printf("SALDO MEDIO MULHERES:%f", mediam);
	printf("\n");
	printf("MENOR SALDO MULHERES:%f", menorm);
	printf("\n");

	printf("O cliente mais antigo eh: %s", cliente[indexidade].nome);
	printf("\n");

	printf("O cliente maior limite especial eh: %s",cliente[indexlimite].nome);
	printf("\n");

	printf("Clientes com saldo negativo: ");
	printf("\n");

	for(int j=0;j<n;j++){
        if(indexclienteneg[j]!=0){
		    printf("  Cliente %s com saldo negativo", cliente[indexclienteneg[j]].nome);
		    printf("\n");
        }
	}
	printf("\n");


	printf("saldo bancario em ordem crescente:");
	printf("\n");
	for(int j=0;j<n;j++){
		printf(" Saldo cliente %s , TOTAL:%f", cliente[saldos[j]].nome, cliente[saldos[j]].conta.saldo);
		printf("\n");
	}




	
	return 0;
	}