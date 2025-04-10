#include <stdio.h>
#include <math.h>

//Cálculo do maximo divisor comum
int mdc(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

//Verificação se o número é primo
int primo(int n) {
  if (n < 2) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

//Calcular a^b mod n usando exponenciação
int modExp(int a, int b, int n){
  int result = 1;
  a = a % n;
  while (b > 0) {
    if (b % 2 == 1) 
      result = (result * a) % n;
    a = (a * a) % n;
    b = b / 2;
  }
  return result;
}

//Verificação se n é um número de Carmichael
int carmichael(int n) {
  if (n < 2 || primo(n)) return 0; //Numeros menores que 2 e primos não são carmichael

  for (int a = 2; a < n; a++) {
    if (mdc(a, n) == 1 && modExp(a, n - 1, n) != 1)
      return 0;
  }
  return 1;
}


int main(void) {
  int n;
  
  printf("Digite um número inteiro: ");
  scanf("%d", &n);

  printf("\nCarmichael de 2 até %d: ", n);
  for (int i = 2; i <= n; i++) {
    if (carmichael(i)) {
      printf(" %d ", i);
    }
  }
  return 0;
}