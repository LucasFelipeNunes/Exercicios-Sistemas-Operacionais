#include<stdlib.h>
#include<stdio.h>

int main(void){
  int qtdprocessos;
  float TME, TMP, somaTMP, somaTME;
  printf("Escalonamento não-preemptível FIFO E SJF de processos\nDigite a quantidade de processos:");
  scanf("%d", &qtdProcessos);
  float tempoCriacao[qtdProcessos], tempoExecucao[qtdProcessos];
  for(int i = 0;i < qtdProcessos;i++){
    printf("\nDigite o tempo de criação do processo P%d:", i + 1);
    scanf("%f", &tempoCriacao[i]);
    printf("\nDigite o tempo de execução do processo P%d:", i + 1);
    scanf("%f", &tempoExecucao[i]);
    somaTMP = 0;
    somaTME = 0;
    for(int j = 0;j <= i;j++){
      somaTMP += tempoExecucao[j];
      if(j < i) somaTME += tempoExecucao[j]
    }
    TMP += (somaTMP - tempoCriacao[j]) / qtdProcessos;
    TME += (somaTME - tempoCriacao[j] / qtdProcessos;
  }
  printf("\nPela metodologia FIFO (First In, First Out):\n\nTempo médio de processo (TMP): %f\nTempo médio de espera (TME): %f", TMP, TME);
  
}
