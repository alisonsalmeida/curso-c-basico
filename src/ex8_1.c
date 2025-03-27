/*
* Crie uma struct chamada Pessoa contendo os campos
* nome (string),
* idade (int)
* altura (float).
*
* Use alocação dinâmica para armazenar o nome e um ponteiro para manipular a struct.
* O programa deve:
    - Solicitar os dados do usuário.
    - Exibir os dados da pessoa.
    - Liberar a memória alocada.
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    int idade;
    float altura;
    char nome[];
} Pessoa;


int main() {
  Pessoa *pessoa;
  char buffer[100];

  printf("Digite o nome da pessoa: ");
  fgets(buffer, 100, stdin);

  // remove o \n do buffer
  buffer[strcspn(buffer, "\n")] = '\0';

  pessoa = (Pessoa *) malloc(sizeof(Pessoa) + strlen(buffer));
  strcpy(pessoa->nome, buffer);

  printf("Digite a idade da pessoa: ");
  scanf("%d", &pessoa->idade);

  printf("Digite a altura da pessoa: ");
  scanf("%f", &pessoa->altura);

  printf("O nome da pessoa eh: %s, tem %.2f metros e tem idade %d anos\n", pessoa->nome, pessoa->altura, pessoa->idade);
  free(pessoa);

  return 0;
}