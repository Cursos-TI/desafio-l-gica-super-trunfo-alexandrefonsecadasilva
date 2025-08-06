#include <stdio.h>
#include <string.h>

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

// ==== Funções Auxiliares ====

void preencherCarta(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", carta->nomeCidade);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void calcularDensidade(Carta *carta) {
    carta->densidadePopulacional = (carta->area > 0) ? (carta->populacao / carta->area) : 0.0f;
}

void calcularPibPerCapita(Carta *carta) {
    carta->pibPerCapita = (carta->populacao > 0) ? ((carta->pib * 1000000000.0f) / carta->populacao) : 0.0f;
}

void calcularSuperPoder(Carta *carta) {
    float invDensidade = (carta->densidadePopulacional > 0) ? (1.0f / carta->densidadePopulacional) : 0.0f;

    carta->superPoder = carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita + invDensidade;
}

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

// Retorna o valor numérico do atributo selecionado
float obterValorAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        case 6: return c.pibPerCapita;
        case 7: return c.superPoder;
        default: return 0.0f;
    }
}

// Retorna 1 se o primeiro valor venceu, 2 se o segundo venceu, 0 se empate
int compararValores(float v1, float v2, int atributo) {
    if (atributo == 5)  // densidade: menor vence
        return (v1 < v2) ? 1 : (v2 < v1) ? 2 : 0;
    else
        return (v1 > v2) ? 1 : (v2 > v1) ? 2 : 0;
}

// ==== PROGRAMA PRINCIPAL ====

int main() {
    Carta carta1, carta2;

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

    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    int attr1 = 0, attr2 = 0;

    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("Digite (1 a 7): ");
    scanf("%d", &attr1);

    if (attr1 < 1 || attr1 > 7) {
        printf("❌ Opção inválida!\n");
        return 1;
    }

    // Menu dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 7; i++) {
        if (i != attr1) {
            switch (i) {
                case 1: printf("%d. População\n", i); break;
                case 2: printf("%d. Área\n", i); break;
                case 3: printf("%d. PIB\n", i); break;
                case 4: printf("%d. Pontos Turísticos\n", i); break;
                case 5: printf("%d. Densidade Populacional\n", i); break;
                case 6: printf("%d. PIB per Capita\n", i); break;
                case 7: printf("%d. Super Poder\n", i); break;
            }
        }
    }

    printf("Digite (1 a 7): ");
    scanf("%d", &attr2);

    if (attr2 < 1 || attr2 > 7 || attr2 == attr1) {
        printf("❌ Opção inválida ou repetida!\n");
        return 1;
    }

    // Obter os valores de cada atributo
    float val1_attr1 = obterValorAtributo(carta1, attr1);
    float val2_attr1 = obterValorAtributo(carta2, attr1);
    float val1_attr2 = obterValorAtributo(carta1, attr2);
    float val2_attr2 = obterValorAtributo(carta2, attr2);

    float soma1 = val1_attr1 + val1_attr2;
    float soma2 = val2_attr1 + val2_attr2;

    printf("\n=== Comparação das Cartas ===\n");
    printf("Cidade 1: %s\n", carta1.nomeCidade);
    printf("Cidade 2: %s\n", carta2.nomeCidade);
    printf("\nAtributo %d: %.2f x %.2f\n", attr1, val1_attr1, val2_attr1);
    printf("Atributo %d: %.2f x %.2f\n", attr2, val1_attr2, val2_attr2);
    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", carta1.nomeCidade, soma1);
    printf("%s: %.2f\n", carta2.nomeCidade, soma2);

    if (soma1 > soma2)
        printf("\n🏆 Vencedora: %s\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\n🏆 Vencedora: %s\n", carta2.nomeCidade);
    else
        printf("\n🤝 Resultado: Empate!\n");

    return 0;
}
