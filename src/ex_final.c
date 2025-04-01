#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 100
#define MAX_AUTOR 100

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
    int emprestado; // 0 = disponível, 1 = emprestado
} Livro;

void cadastrarLivro();
void listarLivros();
void emprestarLivro();
void removerLivro();

int main() {
    int opcao;
    
    do {
        printf("\n=== Sistema de Cadastro de Livros ===\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Emprestar Livro\n");
        printf("4. Remover Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer
        
        switch(opcao) {
            case 1: cadastrarLivro(); break;
            case 2: listarLivros(); break;
            case 3: emprestarLivro(); break;
            case 4: removerLivro(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastrarLivro() {
    FILE *arquivo = fopen("livros.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Livro novoLivro;
    printf("Digite o titulo: ");
    fgets(novoLivro.titulo, MAX_TITULO, stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = 0;

    printf("Digite o autor: ");
    fgets(novoLivro.autor, MAX_AUTOR, stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = 0;

    printf("Digite o ano de publicacao: ");
    scanf("%d", &novoLivro.ano);
    getchar();

    novoLivro.emprestado = 0; // Livro está disponível

    fwrite(&novoLivro, sizeof(Livro), 1, arquivo);
    fclose(arquivo);

    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros() {
    FILE *arquivo = fopen("livros.dat", "rb");
    if (!arquivo) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    Livro livro;
    printf("\n=== Lista de Livros ===\n");
    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        printf("Titulo: %s | Autor: %s | Ano: %d | Status: %s\n",
               livro.titulo, livro.autor, livro.ano, 
               livro.emprestado ? "Emprestado" : "Disponivel");
    }
    fclose(arquivo);
}

void emprestarLivro() {
    FILE *arquivo = fopen("livros.dat", "rb+");
    if (!arquivo) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    char tituloBusca[MAX_TITULO];
    printf("Digite o titulo do livro para emprestar: ");
    fgets(tituloBusca, MAX_TITULO, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = 0;

    Livro livro;
    int encontrado = 0;
    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        if (strcmp(livro.titulo, tituloBusca) == 0 && !livro.emprestado) {
            livro.emprestado = 1;
            fseek(arquivo, -sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, arquivo);
            printf("Livro emprestado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro nao encontrado ou ja emprestado.\n");
    }

    fclose(arquivo);
}

void removerLivro() {
    FILE *arquivo = fopen("livros.dat", "rb");
    if (!arquivo) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    char tituloBusca[MAX_TITULO];
    printf("Digite o titulo do livro para remover: ");
    fgets(tituloBusca, MAX_TITULO, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = 0;

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arquivo);
        return;
    }

    Livro livro;
    int encontrado = 0;
    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        if (strcmp(livro.titulo, tituloBusca) != 0) {
            fwrite(&livro, sizeof(Livro), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("livros.dat");
    rename("temp.dat", "livros.dat");

    if (encontrado) {
        printf("Livro removido com sucesso!\n");
    } else {
        printf("Livro nao encontrado.\n");
    }
}
