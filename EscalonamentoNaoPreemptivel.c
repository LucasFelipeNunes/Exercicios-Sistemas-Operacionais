#include<stdlib.h>
#include<stdio.h>

int main(void){
	int qtdProcessos;
	float TME, TMP, somaTMP, somaTME;
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

}
