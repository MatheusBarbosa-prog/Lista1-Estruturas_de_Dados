#include <stdio.h>
#include <stdlib.h>

//Retornar um array com números de Fibbonacci <= max
//malloc aloca espaço inicial para o array
int *fib(int max) {
  int capacidade = 10;
  int *fib = (int *) malloc(capacidade * sizeof(int));

  if (fib == NULL) {
    printf("Erro ao alocar memória.\n");
    return NULL;
  }

  int a = 0, b = 1, c;
  int i = 0;

  //Adiciona 0
  if(a<=max) {
    fib[i++] = a;
  }

  //Adiciona 1
  //Insere os números <=max 
  while(b<=max){
    if(i>=capacidade) {
      capacidade *= 2;
      fib = (int *) realloc(fib, capacidade * sizeof(int));
      if (fib == NULL) {
        printf("Erro ao realocar memória.\n");
        return NULL;
      }
    }
    fib[i++] = b;
    c = a + b;
    a = b;
    b = c;
  }

  //Adiciona -1
  //realloc aumenta o tamanho do array
  if(i>=capacidade) {
    fib = (int *) realloc(fib, (capacidade + 1) * sizeof(int));
  }
  fib[i] = -1;

  return fib;
}

int main(void) {
  int max;
  printf("Digite o valor máximo: ");
  scanf("%d", &max);

  int *fibArray = fib(max);

  if (fibArray != NULL) {
    printf("Sequência de Fibonacci até %d:\n", max);

    for (int i = 0; fibArray[i] != -1; i++) {
      printf("%d ", fibArray[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(fibArray);
  }
  
  return 0;
}