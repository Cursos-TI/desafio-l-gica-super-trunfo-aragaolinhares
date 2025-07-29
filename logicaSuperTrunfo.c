#include <stdio.h>

int main() {
    // Variáveis da Carta 1
    char estado1[3];
    char codigo1[10];
    char nomeCidade1[100];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // Variáveis da Carta 2
    char estado2[3];
    char codigo2[10];
    char nomeCidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    int opcao;

    // Entrada de dados da Carta 1
    printf("Carta 1:\n");
    printf("Estado: ");
    scanf("%s", estado1);

    printf("Código: ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1e9) / populacao1;

    // Entrada de dados da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: ");
    scanf("%s", estado2);

    printf("Código: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Menu de seleção do atributo
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (MENOR vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Digite a opção (1-6): ");
    scanf("%d", &opcao);

    printf("\n--- Comparação entre %s e %s ---\n", nomeCidade1, nomeCidade2);

    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %d habitantes\n", nomeCidade1, populacao1);
            printf("%s: %d habitantes\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);
            if (area1 > area2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (area2 > area1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("%s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            if (pib1 > pib2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Pontos Turísticos:\n");
            printf("%s: %d pontos\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);
            if (densidade1 < densidade2)
                printf("Resultado: %s venceu (menor densidade)!\n", nomeCidade1);
            else if (densidade2 < densidade1)
                printf("Resultado: %s venceu (menor densidade)!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6:
            printf("PIB per Capita:\n");
            printf("%s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("%s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2)
                printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pibPerCapita2 > pibPerCapita1)
                printf("Resultado: %s venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida. Tente novamente com um número de 1 a 6.\n");
    }

    return 0;
}
