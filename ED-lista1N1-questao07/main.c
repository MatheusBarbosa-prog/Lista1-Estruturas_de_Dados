#include <stdio.h>

//Número máximo visitados
#define MAX 1000 

//Calculando a soma dos quadrados
int somaQuadrados(int n) {
  int soma = 0;
  while (n > 0) {
    soma += (n % 10) * (n % 10);
    n /= 10;
  }
  return soma;
}

//Verificando se o número é feliz
int ehFeliz(int n) {
  int visitados[MAX];
  int i = 0;

  while (n != 1) {
    //Verificando se o número já foi visitado
    for (int j = 0; j < i; j++) {
      if (visitados[j] == n) {
        return 0; //Falso
      }
    }

    //Adicionando o número aos visitados
    if(i < MAX) {
      visitados[i++] = n;
    }

    //Calculando a soma dos quadrados
    n = somaQuadrados(n);
  }
  return 1; //Verdadeiro número feliz 
}

int main(void) {
  int n;

  //Lendo o número
  printf("Digite um número: ");
  scanf("%d", &n);

  //Verificando se o número é feliz
  if (ehFeliz(n)){
    printf("%d é um número feliz.\n", n);
  } else {
    printf("%d não é um número feliz.\n", n);
  }
  
  return 0;
}