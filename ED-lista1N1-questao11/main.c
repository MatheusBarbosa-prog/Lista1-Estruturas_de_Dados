#include <stdio.h>
#include <stdlib.h>

//Função para comparar duas fatias de um array
int compare(int *a, int *b, int inicio, int tam) {
  for (int i = 0; i < tam; i++) {
    if (a[inicio + i] != b[i]) {
        return 0;
      }
  }
  return 1;
}

//Verifica se um array é uma permutação circular
int isCircularPermutation(int *a, int *b, int tam) {
  //Duplica o array a
  int *a2 = (int *)malloc(2 * tam * sizeof(int));
  if (a2 == NULL) {
    printf("Erro ao alocar memória\n");
    return 0;
  }

  //Preenche a2 com duas cópias de a
  for (int i = 0; i < tam; i++) {
    a2[i] = a[i];
    a2[tam + i] = a[i];
  }

  //Verifica se b é uma fatia de a2
  for (int i = 0; i < tam; i++) {
    if (compare(a2, b, i, tam)) {
      free(a2);
      return 1; //Permitação
    }
  }
  free(a2);
  return 0;//Não é permutação
}

//Exemplo para não permutação
int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {5, 4, 3, 2, 1};
  int tam = 5;

  if (isCircularPermutation(a, b, tam)) {
    printf("b é uma permutação circular de a\n");
  } else {
    printf("b não é uma permutação circular de a\n");
  }
  
  return 0;
}