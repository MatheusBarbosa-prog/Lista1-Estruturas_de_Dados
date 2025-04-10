#include <stdio.h>
#include <math.h>

//Verificando se n é um número de Armstrong
int isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = 0;

  // Contando o número de dígitos
  int temp = n;

  while (temp > 0) {
    digits++;
    temp /= 10;
  }

  // Calculando a soma dos dígitos elevados à potência do número de dígitos
  // função pow é usada para elevar um número à potência de outro
  temp = n;
  while (temp > 0) {
    int digit = temp % 10;
    sum += pow(digit, digits);
    temp /= 10;
  }
  return sum == original;
}


int main(void) {
  printf("Números de Armstrong entre 1 e 100:\n");

  for (int i = 1; i <= 100; i++) {
    if (isArmstrong(i)) {
      printf("%d\n", i);
    }
  }
  printf("\n");
  
  return 0;
}