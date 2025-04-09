#include <stdio.h>
#include <string.h>

int main() {
    // Informações das cartas
    char estado1, estado2;
    char carta1[4], carta2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    unsigned int pontoTuristicos1, pontoTuristicos2;

    // Cadastro da carta 1
    printf("--------BEM VINDO AO JOGO SUPER TRUNFO--------\n\n");
    printf("Registre a carta 1\n\n");

    printf("Escolha uma Letra de (A a H): ");
    scanf(" %c", &estado1);

    printf("Escolha um número de (01 a 04): ");
    scanf("%3s", carta1);

    getchar(); // limpar buffer

    printf("Digite uma cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("População da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Pontos turísticos da cidade: ");
    scanf("%u", &pontoTuristicos1);

    // Cadastro da carta 2
    printf("\nRegistre a carta 2\n\n");

    printf("Escolha uma Letra de (A a H): ");
    scanf(" %c", &estado2);

    printf("Escolha um número de (01 a 04): ");
    scanf("%3s", carta2);

    getchar();

    printf("Digite uma cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("População da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Pontos turísticos da cidade: ");
    scanf("%u", &pontoTuristicos2);

    // Cálculo de atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Mostrar cartas
    printf("\nCARTA 1 - %s:\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos turísticos: %u\n", pontoTuristicos1);
    printf("Densidade populacional: %.2f hab/km²\n", densidade1);

    printf("\nCARTA 2 - %s:\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos turísticos: %u\n", pontoTuristicos2);
    printf("Densidade populacional: %.2f hab/km²\n", densidade2);

    int atributo1, atributo2;
    float valor1Carta1 = 0, valor1Carta2 = 0;
    float valor2Carta1 = 0, valor2Carta2 = 0;

    // Escolha do primeiro atributo
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    scanf("%d", &atributo1);

    // Menu dinâmico (sem repetir o mesmo atributo)
    printf("\nEscolha o segundo atributo para comparação:\n");
    if (atributo1 != 1) printf("1 - População\n");
    if (atributo1 != 2) printf("2 - Área\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turísticos\n");
    if (atributo1 != 5) printf("5 - Densidade Populacional\n");

    scanf("%d", &atributo2);

    if (atributo1 == atributo2) {
        printf("Você escolheu o mesmo atributo duas vezes. Encerrando...\n");
        return 1;
    }

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1:
            valor1Carta1 = populacao1;
            valor1Carta2 = populacao2;
            break;
        case 2:
            valor1Carta1 = area1;
            valor1Carta2 = area2;
            break;
        case 3:
            valor1Carta1 = pib1;
            valor1Carta2 = pib2;
            break;
        case 4:
            valor1Carta1 = pontoTuristicos1;
            valor1Carta2 = pontoTuristicos2;
            break;
        case 5:
            valor1Carta1 = densidade1;
            valor1Carta2 = densidade2;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1:
            valor2Carta1 = populacao1;
            valor2Carta2 = populacao2;
            break;
        case 2:
            valor2Carta1 = area1;
            valor2Carta2 = area2;
            break;
        case 3:
            valor2Carta1 = pib1;
            valor2Carta2 = pib2;
            break;
        case 4:
            valor2Carta1 = pontoTuristicos1;
            valor2Carta2 = pontoTuristicos2;
            break;
        case 5:
            valor2Carta1 = densidade1;
            valor2Carta2 = densidade2;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1;
    }

    // Apresentação dos valores usados
    printf("\nComparação dos atributos:\n");
    printf("%s: %.2f e %.2f\n", 
        atributo1 == 1 ? "População" :
        atributo1 == 2 ? "Área" :
        atributo1 == 3 ? "PIB" :
        atributo1 == 4 ? "Pontos Turísticos" : "Densidade Populacional", 
        valor1Carta1, valor1Carta2
    );

    printf("%s: %.2f e %.2f\n", 
        atributo2 == 1 ? "População" :
        atributo2 == 2 ? "Área" :
        atributo2 == 3 ? "PIB" :
        atributo2 == 4 ? "Pontos Turísticos" : "Densidade Populacional", 
        valor2Carta1, valor2Carta2
    );

    // Regras: menor para densidade, maior para os outros
    float pontos1 = 0, pontos2 = 0;

    // Comparar primeiro atributo
    if (atributo1 == 5) {
        pontos1 += (valor1Carta1 < valor1Carta2) ? 1 : 0;
        pontos2 += (valor1Carta2 < valor1Carta1) ? 1 : 0;
    } else {
        pontos1 += (valor1Carta1 > valor1Carta2) ? 1 : 0;
        pontos2 += (valor1Carta2 > valor1Carta1) ? 1 : 0;
    }

    // Comparar segundo atributo
    if (atributo2 == 5) {
        pontos1 += (valor2Carta1 < valor2Carta2) ? 1 : 0;
        pontos2 += (valor2Carta2 < valor2Carta1) ? 1 : 0;
    } else {
        pontos1 += (valor2Carta1 > valor2Carta2) ? 1 : 0;
        pontos2 += (valor2Carta2 > valor2Carta1) ? 1 : 0;
    }

    // Soma dos valores brutos para desempate
    float soma1 = valor1Carta1 + valor2Carta1;
    float soma2 = valor1Carta2 + valor2Carta2;

    printf("\nSoma dos atributos:\n%s: %.2f\n%s: %.2f\n", cidade1, soma1, cidade2, soma2);

    // Resultado final
    if (soma1 > soma2)
        printf("\nA carta vencedora é: %s!\n", cidade1);
    else if (soma2 > soma1)
        printf("\nA carta vencedora é: %s!\n", cidade2);
    else
        printf("\nEmpate!\n");

    return 0;
}
