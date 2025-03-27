/*
 * crie uma programa em C que peça ao usuario um numero inteiro N
*  e calcule a soma dos pares de 1 ate N usando um laço for. Se o
*  usuario digitar um valor menor que 1, peça um novo valor usando
*  do while
 *
 *
*  */

#include <stdio.h>

int main() {
  int numero, soma = 0;

  do {
    printf("Digite um numero: ");
    scanf("%d", &numero);
  } while(numero < 1);

  // calular a soma dos pares, de 1 ate N
  for (int i = 1; i <= numero; i++) {
    if (i % 2 == 0) {
      soma = soma + i;
    }
  }

  printf("a soma de 1 ate %d eh: %d\n", numero, soma);
  return 0;
}