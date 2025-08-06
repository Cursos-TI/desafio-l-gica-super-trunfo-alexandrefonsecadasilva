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
    float superPoder;
} Carta;

// Função para preencher dados de uma carta
void preencherCarta(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", carta->nomeCidade); // evita estouro de buffer

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Calcula densidade populacional
void calcularDensidade(Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0.0f;
}

// Calcula PIB per capita
void calcularPibPerCapita(Carta *carta) {
    if (carta->populacao > 0)
        carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;
    else
        carta->pibPerCapita = 0.0f;
}

// Calcula o Super Poder
void calcularSuperPoder(Carta *carta) {
    float inversoDensidade = 0.0f;
    if (carta->densidadePopulacional != 0.0f) {
        inversoDensidade = 1.0f / carta->densidadePopulacional;
    }

    carta->superPoder = carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita +
                        inversoDensidade;
}

// Exibe uma carta
void mostrarCarta(Carta c, int num) {
    printf("\n--- Carta %d ---\n", num);
    printf("Cidade: %s (%c)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

// Comparador interativo via switch
void compararCartas(Carta c1, Carta c2, int opcao) {
    switch (opcao) {
        case 1:
            printf("\n[Atributo: População]\n");
            printf("%s: %lu\n", c1.nomeCidade, c1.populacao);
            printf("%s: %lu\n", c2.nomeCidade, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Empate!\n");
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
                printf("🤝 Empate!\n");
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
                printf("🤝 Empate!\n");
            break;

        case 4:
            printf("\n[Atributo: Pontos Turísticos]\n");
            printf("%s: %d\n", c1.nomeCidade, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nomeCidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Empate!\n");
            break;

        case 5:
            printf("\n[Atributo: Densidade Populacional (menor vence)]\n");
            printf("%s: %.2f hab/km²\n", c1.nomeCidade, c1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", c2.nomeCidade, c2.densidadePopulacional);
            if (c1.densidadePopulacional < c2.densidadePopulacional)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.densidadePopulacional < c1.densidadePopulacional)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Empate!\n");
            break;

        case 6:
            printf("\n[Atributo: Super Poder]\n");
            printf("%s: %.2f\n", c1.nomeCidade, c1.superPoder);
            printf("%s: %.2f\n", c2.nomeCidade, c2.superPoder);
            if (c1.superPoder > c2.superPoder)
                printf("🏆 Vencedora: %s\n", c1.nomeCidade);
            else if (c2.superPoder > c1.superPoder)
                printf("🏆 Vencedora: %s\n", c2.nomeCidade);
            else
                printf("🤝 Empate!\n");
            break;

        default:
            printf("❌ Opção inválida. Tente novamente.\n");
    }
}

int main() {
    Carta carta1, carta2;

    // Cadastro e cálculo
    printf("Cadastro da Carta 1:\n");
    preencherCarta(&carta1);
    calcularDensidade(&carta1);
    calcularPibPerCapita(&carta1);
    calcularSuperPoder(&carta1);

    printf("\nCadastro da Carta 2:\n");
    preencherCarta(&carta2);
    calcularDensidade(&carta2);
    calcularPibPerCapita(&carta2);
    calcularSuperPoder(&carta2);

    // Exibir cartas
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    // Menu
    int escolha;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. Super Poder\n");
    printf("Digite sua opção (1 a 6): ");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}
