#include <stdio.h>

//Função para calcular a soma dos divisores próprios de um número
int somaDivisores(int num){
  int soma = 0;

  printf("Divisores de %d: ", num);
  for(int i = 1; i <= num; i++) {
    if(num % i == 0) {
      printf(" %d ", i);
      soma += i;
    }
  }
  printf("\nSoma: %d\n\n", soma);
  return soma;
}

//Função para verificar se um número são amigavéis
void verificaAmigos(int num1, int num2) {
  int soma1 = somaDivisores(num1);
  int soma2 = somaDivisores(num2);

  if(soma1 == soma2 && soma2 == soma1) {
    printf("Os números %d e %d são amigos.\n", num1, num2);
  } else {
    printf("Os números %d e %d não são amigos.\n", num1, num2);
  }
}

//Funcão para verificar os pares amigaveis até um número n
void paresAmigos(int n) {
  printf("Pares de amigos até %d:\n\n", n);
  for(int i = 2; i <= n; i++) {
    int soma1 = somaDivisores(i);

    if (soma1 > i && soma1 <= n) {
      int soma2 = somaDivisores(soma1);
      
      if (soma2 == i) {
        printf("Par Amigável: %d e %d\n", i, soma1);
      }
    }
  }
}

int main(void) {
  int n;
  
  printf("Digite um número inteiro máximo para encontrar números amigáveis até o mesmo: ");
  scanf("%d", &n);

  paresAmigos(n);
  return 0;
}