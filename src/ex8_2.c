/*
Crie uma struct chamada Aluno, contendo:
    nome (string alocada dinamicamente)
    matricula (int)
    nota (float).

O programa deve: Solicitar ao usuário quantos alunos deseja cadastrar.
Criar um array dinâmico de Aluno. Permitir que o usuário insira os dados de cada aluno.
Exibir a lista de alunos e suas notas.

Liberar a memória antes de encerrar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
      int matricula;
      float nota;
      char nome[];
} Aluno;

int main() {
  int qtd_alunos = 0;
  int total_alunos = 0;

  printf("Digite a quantidade de alunos: ");
  scanf("%d", &qtd_alunos);
  getchar();

  Aluno *alunos = malloc(qtd_alunos * sizeof(Aluno));
  if (alunos == NULL) {
    printf("Erro alocando memoria");
    return 1;
  }

  while (total_alunos < qtd_alunos) {
    char buffer[100];
    printf("Digite o nome do aluno: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    Aluno *a = malloc(sizeof(Aluno) + strlen(buffer));
    strcpy(a->nome, buffer);

    printf("Digite a nota do aluno: ");
    scanf("%f", &a->nota);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &a->matricula);

    Aluno *_temp_alunos = realloc(alunos, qtd_alunos * (sizeof(Aluno) + strlen(buffer)));
    if (_temp_alunos == NULL) {
      printf("Erro alocando memoria");
      return 1;
    }

    alunos = _temp_alunos;
    total_alunos++;
  }

  for (int i = 0; i < qtd_alunos; i++) {
    printf("Aluno %s, matricula: %d, note: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].nota);
  }
}