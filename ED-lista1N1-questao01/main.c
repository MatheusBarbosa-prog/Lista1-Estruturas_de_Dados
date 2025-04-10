#include <stdio.h>
#include <math.h>

//Para calculo do fatorial
int fatorial(int num) {
    int fat = 1;
    for (int i = 1; i <= num; i++) {
      fat *= i;
    }
    return fat;
}

//Calculando a primeira parte da questão(fatorial crescente)
int potencia_fatorial_crescente(int x, int n) {
  int fatcre = 1;
  for (int i = 1; i <= n; i++) {
    int fatorial_i = fatorial(i);//fatorial de i
    fatcre *= pow(x, fatorial_i);//potencia de x elevado ao fatorial_i
    }
  return fatcre;
}


//Calculando a segunda parte da questão(fatorial decrescente)
int potencia_fatorial_decrescente(int x, int n) {
  int fatdec = 1;
  for (int i = n; i >= 1; i--) {
    int fatorial_i = fatorial(i);
    fatdec *= pow(x, fatorial_i);
  }
  return fatdec;
}

int main() {
  int x_inicio, x_fim, n_inicio, n_fim;

  printf("Digite o valor inicial de x: ");
  scanf(" %d", &x_inicio);
  printf("Digite o valor final de x: ");
  scanf(" %d", &x_fim);

  printf("Digite o valor inicial de n: ");
  scanf(" %d", &n_inicio);
  printf("Digite o valor final de n: ");
  scanf(" %d", &n_fim);

  printf("\n-------TABELA DE VALORES(X FIXO E N VARIANDO-------\n");
  for (int x = x_inicio; x <= x_fim; x++) {
    printf("x = %d:\n", x);
    for (int n = n_inicio; n <= n_fim; n++) {
      int resultado_crescente = potencia_fatorial_crescente(x, n);
      int resultado_decrescente = potencia_fatorial_decrescente(x, n);

      printf("n = %d: Valor Crescente: %d, Valor Decrescente: %d\n", n, resultado_crescente, resultado_decrescente);
    }
  }

  // Tabela com n fixo e x variando
  printf("\n-------TABELA DE VALORES(N FIXO E X VARIANDO)-------\n");
  for (int n = n_inicio; n <= n_fim; n++) {
    printf("n = %d:\n", n);
    for (int x = x_inicio; x <= x_fim; x++) {
      int resultado_crescente = potencia_fatorial_crescente(x, n);
      int resultado_decrescente = potencia_fatorial_decrescente(x, n);
      printf("x = %d: Valor Crescente: %d, Valor Decrescente: %d\n", x, resultado_crescente, resultado_decrescente);
    }
  }

  return 0;
}