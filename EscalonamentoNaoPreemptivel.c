#include<stdlib.h>
#include<stdio.h>

int main(void){
	int qtdProcessos;
	float TME, TMP, somaTMP, somaTME, aux;
	printf("Escalonamento nao-preemptivel FIFO E SJF de processos\nDigite a quantidade de processos: ");
	scanf("%d", &qtdProcessos);
	float tempoCriacao[qtdProcessos], tempoExecucao[qtdProcessos];
	for(int i = 0;i < qtdProcessos;i++){
		printf("\nDigite o tempo de criacao do processo P%d: ", i + 1);
		scanf("%f", &tempoCriacao[i]);
		printf("Digite o tempo de execucao do processo P%d: ", i + 1);
		scanf("%f", &tempoExecucao[i]);
		somaTMP = 0;
		somaTME = 0;
		for(int j = 0;j <= i;j++){
			somaTMP += tempoExecucao[j];
			if(j < i) somaTME += tempoExecucao[j];
		}
		TMP += (somaTMP - tempoCriacao[i]) / qtdProcessos;
		TME += (somaTME - tempoCriacao[i]) / qtdProcessos;
	}
	printf("\nPela metodologia FIFO (First In, First Out):\n\nTempo medio de processo (TMP): %f\nTempo medio de espera (TME): %f", TMP, TME);
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
				}
				aux = 0;
			}
		}
	}
	printf("\n\n\n%f %f %f %f\n\n\n", tempoExecucao[0], tempoExecucao[1], tempoExecucao[2], tempoExecucao[3]);
	TMP = 0;
	TME = 0;
	for(int i = 0;i < qtdProcessos;i++){
		somaTMP = 0;
		somaTME = 0;
		for(int j = 0;j <= i;j++){
			somaTMP += tempoExecucao[j];
			if(j < i) somaTME += tempoExecucao[j];
		}
		TMP += (somaTMP - tempoCriacao[i]) / qtdProcessos;
		TME += (somaTME - tempoCriacao[i]) / qtdProcessos;
	}
	printf("\nPela metodologia SJF (Shortest Job First):\n\nTempo medio de processo (TMP): %f\nTempo medio de espera (TME): %f", TMP, TME);
}
