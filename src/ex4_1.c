/*
 Crie um programa que leia as 3 notas de um aluno, calcule
a media e informe se o aluno foi aprovado ou reprovado.
A média minima para aprovação é 6. Utilize o float para
armazenar as notas e a media, e operadores relacionais para
comparar a media.
*/

#include <stdio.h>

int main() {
  float media, nota_1 = 0, nota_2 = 0, nota_3 = 0;
  printf("Digite a primeira nota: ");
  scanf("%f", &nota_1);

  printf("Digite a segunda nota: ");
  scanf("%f", &nota_2);

  printf("Digite a terceira nota: ");
  scanf("%f", &nota_3);

  media = (nota_1 + nota_2 + nota_3) / 3;
  printf("A media do aluno eh: %.2f\n", media);

  if (media >= 6) {
    printf("Aluno aprovado com: %.2f\n", media);
  }
  else {
    printf("Aluno esta reprovado\n");
  }

  return 0;
}