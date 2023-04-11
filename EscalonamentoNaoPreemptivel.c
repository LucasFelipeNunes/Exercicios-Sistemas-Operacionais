#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
int main(void){
	setlocale(LC_ALL, "Portuguese");
	int qtdProcessos = 0;
	float TME = 0, TMP = 0, somaTMP = 0, somaTME = 0, aux = 0;
	printf("Escalonamento nao-preemptivel FIFO E SJF de processos\nDigite a quantidade de processos: ");
	scanf("%d", &qtdProcessos);
	int processos[qtdProcessos];
	float tempoCriacao[qtdProcessos], tempoExecucao[qtdProcessos];
	for(int i = 0;i < qtdProcessos;i++){
		printf("\nDigite o tempo de criacao do processo P%d: ", i + 1);
		scanf("%f", &tempoCriacao[i]);
		printf("Digite o tempo de execucao do processo P%d: ", i + 1);
		scanf("%f", &tempoExecucao[i]);
		processos[i] = i + 1;
		for(int j = 0;j < i;j++){
			if(tempoCriacao[i] < tempoCriacao[j]){ //Se o tempo de criacao do atual for menor que algum anterior
				aux = tempoExecucao[i]; //trocar os elementos dos dois
				tempoExecucao[i] = tempoExecucao[j];
				tempoExecucao[j] = aux;
				aux = tempoCriacao[i];
				tempoCriacao[i] = tempoCriacao[j];
				tempoCriacao[j] = aux;
				aux = processos[i];
				processos[i] = processos[j];
				processos[j] = aux;
				aux = 0;
			}
		}
	}
	printf("\n\nOrdem de Execução");
	for(int i = 0;i < qtdProcessos;i++){
		printf("\nP%d\t%.2f\t%.2f", processos[i], tempoCriacao[i], tempoExecucao[i]);
		somaTMP = 0;
		somaTME = 0;
		for(int j = 0;j <= i;j++){
			somaTMP += tempoExecucao[j];
			if(j < i) somaTME += tempoExecucao[j];
		}
		TMP += (somaTMP - tempoCriacao[i] + tempoCriacao[0]) / qtdProcessos;
		TME += (somaTME - tempoCriacao[i] + tempoCriacao[0]) / qtdProcessos;
	}
	printf("\n\n\nPela metodologia FIFO (First In, First Out):\n\nTempo medio de processo (TMP): %.2f\nTempo medio de espera (TME): %.2f", TMP, TME);
	for(int i = 1;i < qtdProcessos;i++){
		for(int j = 0;j < i;j++){
			if(tempoExecucao[i] < tempoExecucao[j]){
				for(int k = 0;k < j;k++){
					aux += tempoExecucao[k];
				}
				if(aux > tempoCriacao[i]){
					aux = tempoExecucao[i];
					tempoExecucao[i] = tempoExecucao[j];
					tempoExecucao[j] = aux;
					aux = tempoCriacao[i];
					tempoCriacao[i] = tempoCriacao[j];
					tempoCriacao[j] = aux;
					aux = 0;
					aux = processos[i];
					processos[i] = processos[j];
					processos[j] = aux;
				}
			}
		}
	}
	TMP = tempoCriacao[0];
	TME = tempoCriacao[0];
	printf("\n\n\nOrdem de Execução");
	for(int i = 0;i < qtdProcessos;i++){
		printf("\nP%d\t%.2f\t%.2f", processos[i], tempoCriacao[i], tempoExecucao[i]);
		somaTMP = 0;
		somaTME = 0;
		for(int j = 0;j <= i;j++){
			somaTMP += tempoExecucao[j];
			if(j < i) somaTME += tempoExecucao[j];
		}
		TMP += (somaTMP - tempoCriacao[i]) / qtdProcessos;
		TME += (somaTME - tempoCriacao[i]) / qtdProcessos;
	}
	printf("\n\n\nPela metodologia SJF (Shortest Job First):\n\nTempo medio de processo (TMP): %.2f\nTempo medio de espera (TME): %.2f", TMP, TME);
}
