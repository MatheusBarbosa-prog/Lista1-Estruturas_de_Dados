#include <stdio.h>

//Definição do valor máximo
#define MAX 20 

//Função que calcula o fatorial(long long usado para evitar overflow)
unsigned long long fatorial(int n) {
  unsigned long long fat = 1;
  for (int i = 2; i <= n; i++) {
    fat *= i;
  }
  return fat;
}

//Função que calcula o fatorial duplo
unsigned long long fatorialDuplo(int n) {
  unsigned long long fat = 1;
  for (int i = n; i >= 1; i -= 2) {
    fat *= i;
  }
  return fat;
}


int main(void) {
  //Declaração dos arrays de tamanho 21 pois de 0 a 20 temos 21 elementos
  unsigned long long fatoriais[MAX + 1];
  unsigned long long fatorial_Duplo[MAX + 1];
  unsigned long long diferenca[MAX + 1];

  //for para preenchimento dos arrays calculando e armazenando os valores de 1 a 20
  for (int i = 1; i <= MAX; i++) {
    fatoriais[i] = fatorial(i);
    fatorial_Duplo[i] = fatorialDuplo(i);
    diferenca[i] = fatoriais[i] - fatorial_Duplo[i];
  }

  //Tabela com fatorial e fatorial duplo
  printf("------TABELA FATORIAL E FATORIAL DUPLO------\n");
  printf("n\tFatorial\tFatorial Duplo\n");
  printf("--------------------------------------------\n");

  for (int i = 1; i <= MAX; i++) {
    printf("%d\t%llu\t\t%llu\n", i, fatoriais[i], fatorial_Duplo[i]);
  }

  //Tabela com a diferença entre fatorial e fatorial duplo
  printf("\n------TABELA DIFERENCA------\n");
  printf("n\tFatorial\tFatorial Duplo\tDiferenca\n");
  printf("--------------------------------------------\n");

  for (int i = 1; i <= MAX; i++) {
    printf("%d\t%llu\t\t%llu\t\t%llu\n", i, fatoriais[i], fatorial_Duplo[i], diferenca[i]);
  }
  return 0;
}