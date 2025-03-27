/*
Calculadora de soma
descrição: Peça ao usuario dois numeros e exiba a soma entre eles

Como compilar:
gcc src/ex2_1.c -o bin/ex2_1

Executar:
./bin/ex2_1

*/

#include <stdio.h>

int main() {
  int number_1, number_2;

  printf("Digite o primeiro numero: ");
  scanf("%d", &number_1);

  printf("Digite o segundo numero: ");
  scanf("%d", &number_2);

  printf("A soma entre %d e %d eh: %d", number_1, number_2, number_1 + number_2);
}