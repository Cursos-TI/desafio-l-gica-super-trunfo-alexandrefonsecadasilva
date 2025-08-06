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

    // Cálculos carta 1
    if (carta1.area > 0)
        carta1.densidadePopulacional = carta1.populacao / carta1.area;
    else {
        carta1.densidadePopulacional = 0.0f;
        printf("⚠️ Atenção: Área da carta 1 é zero.\n");
    }

    if (carta1.populacao > 0)
        carta1.pibPerCapita = (carta1.pib * 1000000000.0) / carta1.populacao;
    else {
        carta1.pibPerCapita = 0.0f;
        printf("⚠️ Atenção: População da carta 1 é zero.\n");
    }

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

    // Cálculos carta 2
    if (carta2.area > 0)
        carta2.densidadePopulacional = carta2.populacao / carta2.area;
    else {
        carta2.densidadePopulacional = 0.0f;
        printf("⚠️ Atenção: Área da carta 2 é zero.\n");
    }

    if (carta2.populacao > 0)
        carta2.pibPerCapita = (carta2.pib * 1000000000.0) / carta2.populacao;
    else {
        carta2.pibPerCapita = 0.0f;
        printf("⚠️ Atenção: População da carta 2 é zero.\n");
    }

    printf("\n");

    // COMPARAÇÃO - Atributo fixo: POPULAÇÃO
    printf("🔎 Comparação de Cartas (Atributo: População)\n\n");

    printf("Carta 1 - %s (%c): %lu habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%c): %lu habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("\n🏆 Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\n🏆 Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\n🤝 Resultado: Empate! Ambas as cidades têm a mesma população.\n");
    }

    return 0;
}
