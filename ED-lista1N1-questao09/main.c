#include <stdio.h>

//Verificando se o número é perfeito
int isPerfect(int n) {
  int sum = 0;

//loop para somar os divisores de 1 até n/2
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) {
        sum += i;
    }
  }
  return sum == n;
}


int main(void) {
  printf("Números perfeitos entre 1 e 100000:\n");

  //loop para verificar os números perfeitos
  for (int i = 1; i <= 100000; i++){
    if (isPerfect(i)){
      printf("%d\n", i);
    }
  }
  
  return 0;
}