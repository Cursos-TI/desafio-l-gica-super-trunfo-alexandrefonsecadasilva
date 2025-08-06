#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n🔎 Comparação de Cartas\n");
    printf("Carta 1: %s (%c)\n", c1.nomeCidade, c1.estado);
    printf("Carta 2: %s (%c)\n", c2.nomeCidade, c2.estado);

    switch (opcao) {
        case 1:
            printf("\n[Atributo: População]\n");
            printf("%s: %lu habitantes\n", c1.nomeCidade, c1.populacao);
            printf("%s: %lu habitantes\n", c2.nomeCidade, c2.populacao);

            if (c1.populacao > c2.populacao)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Resultado: Empate!\n");
            break;

        case 2:
            printf("\n[Atributo: Área]\n");
            printf("%s: %.2f km²\n", c1.nomeCidade, c1.area);
            printf("%s: %.2f km²\n", c2.nomeCidade, c2.area);

            if (c1.area > c2.area)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.area > c1.area)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Resultado: Empate!\n");
            break;

        case 3:
            printf("\n[Atributo: PIB]\n");
            printf("%s: %.2f bilhões\n", c1.nomeCidade, c1.pib);
            printf("%s: %.2f bilhões\n", c2.nomeCidade, c2.pib);

            if (c1.pib > c2.pib)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.pib > c1.pib)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Resultado: Empate!\n");
            break;

        case 4:
            printf("\n[Atributo: Pontos Turísticos]\n");
            printf("%s: %d pontos\n", c1.nomeCidade, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.nomeCidade, c2.pontosTuristicos);

            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Resultado: Empate!\n");
            break;

        case 5:
            printf("\n[Atributo: Densidade Populacional]\n");
            printf("%s: %.2f hab/km²\n", c1.nomeCidade, c1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", c2.nomeCidade, c2.densidadePopulacional);

            if (c1.densidadePopulacional < c2.densidadePopulacional)
                printf("🏆 Vencedora: %s (menor densidade)\n", c1.nomeCidade);
            else if (c2.densidadePopulacional < c1.densidadePopulacional)
                printf("🏆 Vencedora: %s (menor densidade)\n", c2.nomeCidade);
            else
                printf("🤝 Resultado: Empate!\n");
            break;

        default:
            printf("❌ Opção inválida! Escolha de 1 a 5.\n");
    }
}

int main() {
    Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Digite a população: ");
    scanf("%lu", &carta1.populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    if (carta1.area > 0)
        carta1.densidadePopulacional = carta1.populacao / carta1.area;
    else
        carta1.densidadePopulacional = 0.0f;

    if (carta1.populacao > 0)
        carta1.pibPerCapita = (carta1.pib * 1000000000.0) / carta1.populacao;
    else
        carta1.pibPerCapita = 0.0f;

    printf("\n");

    // Cadastro da Carta 2
    printf("Cadastro da Carta 2:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%3s", carta2.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Digite a população: ");
    scanf("%lu", &carta2.populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    if (carta2.area > 0)
        carta2.densidadePopulacional = carta2.populacao / carta2.area;
    else
        carta2.densidadePopulacional = 0.0f;

    if (carta2.populacao > 0)
        carta2.pibPerCapita = (carta2.pib * 1000000000.0) / carta2.populacao;
    else
        carta2.pibPerCapita = 0.0f;

    printf("\n");

    // Menu interativo
    int escolha;
    printf("📋 Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional (menor vence)\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}
