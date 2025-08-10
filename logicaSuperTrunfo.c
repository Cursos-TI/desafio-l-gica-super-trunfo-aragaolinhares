#include <stdio.h>

// Estrutura para armazenar dados da carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Cadastro da carta:\n");
    printf("Estado (2 letras): ");
    scanf("%2s", carta->estado);
    printf("Código da carta: ");
    scanf("%9s", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nome);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta->pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula densidade demográfica e PIB per capita
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao;
}

// Função para obter o nome do atributo baseado na opção
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica (menor vence)";
        case 6: return "PIB per Capita";
        default: return "Atributo Inválido";
    }
}

// Função para obter o valor do atributo de uma carta
float valorAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return -1.0f; // erro
    }
}

// Função para comparar um atributo entre duas cartas
// Retorna 1 se c1 vence, 2 se c2 vence, 0 empate
int compararAtributo(Carta c1, Carta c2, int opcao) {
    float val1 = valorAtributo(c1, opcao);
    float val2 = valorAtributo(c2, opcao);

    if (opcao == 5) { // Densidade demográfica: menor vence
        if (val1 < val2) return 1;
        else if (val2 < val1) return 2;
        else return 0;
    } else { // Maior vence para os demais
        if (val1 > val2) return 1;
        else if (val2 > val1) return 2;
        else return 0;
    }
}

int main() {
    Carta carta1, carta2;
    int op1, op2;
    int pontos1 = 0, pontos2 = 0;

    // Cadastro das cartas
    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);
    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    // Escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    for (int i = 1; i <= 6; i++) {
        printf("%d - %s\n", i, nomeAtributo(i));
    }
    printf("Opção: ");
    scanf("%d", &op1);

    // Escolha do segundo atributo, diferente do primeiro
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != op1) {
                printf("%d - %s\n", i, nomeAtributo(i));
            }
        }
        printf("Opção: ");
        scanf("%d", &op2);
        if (op2 == op1) {
            printf("Erro: atributo igual ao primeiro. Escolha outro.\n");
        }
    } while (op2 == op1);

    // Comparação do primeiro atributo
    int vencedor1 = compararAtributo(carta1, carta2, op1);
    float val1_1 = valorAtributo(carta1, op1);
    float val1_2 = valorAtributo(carta2, op1);

    // Comparação do segundo atributo
    int vencedor2 = compararAtributo(carta1, carta2, op2);
    float val2_1 = valorAtributo(carta1, op2);
    float val2_2 = valorAtributo(carta2, op2);

    // Exibição dos resultados
    printf("\n--- Resultado da comparação ---\n");

    printf("%s: %.2f vs %.2f -> ", nomeAtributo(op1), val1_1, val1_2);
    if (vencedor1 == 1) printf("Vence: %s\n", carta1.nome);
    else if (vencedor1 == 2) printf("Vence: %s\n", carta2.nome);
    else printf("Empate\n");

    printf("%s: %.2f vs %.2f -> ", nomeAtributo(op2), val2_1, val2_2);
    if (vencedor2 == 1) printf("Vence: %s\n", carta1.nome);
    else if (vencedor2 == 2) printf("Vence: %s\n", carta2.nome);
    else printf("Empate\n");

    // Soma dos pontos
    pontos1 = (vencedor1 == 1 ? 1 : 0) + (vencedor2 == 1 ? 1 : 0);
    pontos2 = (vencedor1 == 2 ? 1 : 0) + (vencedor2 == 2 ? 1 : 0);

    printf("\n--- Resultado Final ---\n");
    if (pontos1 > pontos2) {
        printf("Vencedor Geral: %s\n", carta1.nome);
    } else if (pontos2 > pontos1) {
        printf("Vencedor Geral: %s\n", carta2.nome);
    } else {
        printf("Empate Geral!\n");
    }

    return 0;
}
