#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_NOME 30
#define TAM_TIPO 20

// Estrutura para representar um item
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                if (totalItens < MAX_ITENS) {
                    printf("\n--- Adicionar Item ---\n");

                    printf("Nome: ");
                    fgets(mochila[totalItens].nome, TAM_NOME, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0'; // remover \n

                    printf("Tipo: ");
                    fgets(mochila[totalItens].tipo, TAM_TIPO, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar();

                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                } else {
                    printf("Mochila cheia! Não é possível adicionar mais itens.\n");
                }
                break;

            case 2:
                if (totalItens == 0) {
                    printf("A mochila está vazia!\n");
                } else {
                    char nomeRemover[TAM_NOME];
                    int encontrado = 0;

                    printf("\n--- Remover Item ---\n");
                    printf("Nome do item a remover: ");
                    fgets(nomeRemover, TAM_NOME, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Desloca os itens para preencher o espaço
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Item não encontrado.\n");
                    }
                }
                break;

            case 3:
                printf("\n--- Itens na Mochila ---\n");
                if (totalItens == 0) {
                    printf("A mochila está vazia.\n");
                } else {
                    printf("%-30s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-30s %-20s %-10d\n",
                            mochila[i].nome,
                            mochila[i].tipo,
                            mochila[i].quantidade);
                    }
                }
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
