#include <stdio.h>
#include <stdlib.h>

// Definindo cores ANSI para uso no terminal
#define AZUL "\033[1;34m"
#define VERMELHO "\033[1;31m"
#define RESET "\033[0m"

// Função para exibir as poltronas
void exibirPoltronas(char matriz[5][5]) {
    printf("\n-------------------------------------------------------------");
    printf("\n                      POLTRONAS                              ");
    printf("\n       A   B   C   D   E ");
    printf("\n     ---------------------");

    for (int i = 0; i < 5; ++i) {
        printf("\n  %i  |", i + 1);  // Exibe o número da linha
        for (int j = 0; j < 5; ++j) {
            // Usa cores para exibir poltronas disponíveis e reservadas
            if (matriz[i][j] == 'X') {
                printf(" %sX%s |", VERMELHO, RESET);
            } else {
                printf(" %s%c%s |", AZUL, matriz[i][j], RESET);
            }
        }
        printf("\n     ---------------------");
    }
    printf("\n-------------------------------------------------------------\n");
}

int main() {
    char continuar = 'S';
    char fileira;
    int linha, col, tipoPassagem, assento;
    char matriz[5][5] = {  // Inicializa todas as poltronas como disponíveis ('0')
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    while (continuar == 'S' || continuar == 's') {
        exibirPoltronas(matriz);  // Exibe a matriz de poltronas

        printf("Tipo de passagem (1-Executiva, 2-Econômica): ");
        scanf("%d", &tipoPassagem);

        if (tipoPassagem != 1 && tipoPassagem != 2) {
            printf("Tipo de passagem inválido! Tente novamente.\n");
            continue;
        }

        if (tipoPassagem == 1) {  // Plano executivo
            printf("\nVocê pode reservar até 3 assentos executivos (A, B ou C):\n");

            for (int i = 0; i < 3; i++) {
                printf("Escolha a fileira (A-C): ");
                scanf(" %c", &fileira);

                if (fileira < 'A' || fileira > 'C') {
                    printf("Fileira inválida! Tente novamente.\n");
                    i--;
                    continue;
                }

                col = fileira - 'A';  // Converte a fileira para o índice da coluna

                printf("Digite a linha (1-5): ");
                scanf("%d", &linha);

                if (linha < 1 || linha > 5) {
                    printf("Linha inválida! Tente novamente.\n");
                    i--;
                    continue;
                }

                linha--;  // Ajusta a linha para o índice correto

                if (matriz[linha][col] == 'X') {
                    printf("Esse assento já está ocupado! Escolha outro.\n");
                    i--;
                } else {
                    matriz[linha][col] = 'X';  // Reserva o assento
                    printf("Assento %c%d reservado com sucesso!\n", fileira, linha + 1);
                }
            }

        } else if (tipoPassagem == 2) {  // Plano econômico
            printf("\nDigite a fileira desejada (B-D): ");
            scanf(" %c", &fileira);

            if (fileira < 'B' || fileira > 'D') {
                printf("Fileira inválida! Tente novamente.\n");
                continue;
            }

            col = fileira - 'A';  // Converte a fileira para o índice da coluna

            printf("Digite a linha (1-5): ");
            scanf("%d", &linha);

            if (linha < 1 || linha > 5) {
                printf("Linha inválida! Tente novamente.\n");
                continue;
            }

            linha--;  // Ajusta a linha para o índice correto

            if (matriz[linha][col] == 'X') {
                printf("Esse assento já está ocupado! Escolha outro.\n");
            } else {
                matriz[linha][col] = 'X';  // Reserva o assento
                printf("Assento %c%d reservado com sucesso!\n", fileira, linha + 1);
            }
        }

        exibirPoltronas(matriz);  // Exibe a matriz atualizada

        printf("Deseja continuar reservando poltronas? (S/N): ");
        scanf(" %c", &continuar);
    }

    printf("\nObrigado por utilizar o sistema de reservas!\n");

    return 0;
}
