#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Estrutura para armazenar as informações de uma cidade
struct Cidade {
    
    char nome[100];          // Nome da cidade
    int populacao;           // População
    float area;              // Área em km²
    float pib;               // PIB em bilhões de unidades monetárias
    int pontosTuristicos;    // Número de pontos turísticos
};
// Estrutura para armazenar informações de um país
struct Pais {
    char nomePais[100];      // Nome do país
};

// Função para exibir as informações de uma cidade
void exibirCidade(struct Cidade cidade, char estado, int cidadeNumero, char nomePais[]) {
    // Gerar o código da carta com base no estado e cidade
    printf("Codigo da carta: %c%02d\n", estado, cidadeNumero);
    printf("Pais: %s\n", nomePais);
    printf("  Cidade: %s\n", cidade.nome);
    printf("    Populacao: %d habitantes\n", cidade.populacao);
    printf("    Area: %.2f km\n", cidade.area);
    printf("    PIB: %.2f bilhoes de unidades monetarias\n", cidade.pib);
    printf("    Pontos turisticos: %d\n", cidade.pontosTuristicos);
    printf("\n");
}


// Função para comparar cidades com base em um atributo específico
void compararCartas(struct Cidade cidade1, struct Cidade cidade2, int atributo) {
    switch (atributo) {
        case 1:  // Comparar População
            if (cidade1.populacao > cidade2.populacao) {
                printf("%s venceu! Populacao maior.\n", cidade1.nome);
            } else if (cidade1.populacao < cidade2.populacao) {
                printf("%s venceu! Populacao maior.\n", cidade2.nome);
            } else {
                printf("Empate na populacao!\n");
            }
            break;
        case 2:  // Comparar Área
            if (cidade1.area > cidade2.area) {
                printf("%s venceu! Area maior.\n", cidade1.nome);
            } else if (cidade1.area < cidade2.area) {
                printf("%s venceu! Area maior.\n", cidade2.nome);
            } else {
                printf("Empate na area!\n");
            }
            break;
        case 3:  // Comparar PIB
            if (cidade1.pib > cidade2.pib) {
                printf("%s venceu! PIB maior.\n", cidade1.nome);
            } else if (cidade1.pib < cidade2.pib) {
                printf("%s venceu! PIB maior.\n", cidade2.nome);
            } else {
                printf("Empate no PIB!\n");
            }
            break;
        case 4:  // Comparar Pontos turísticos
            if (cidade1.pontosTuristicos > cidade2.pontosTuristicos) {
                printf("%s venceu! Mais pontos turisticos.\n", cidade1.nome);
            } else if (cidade1.pontosTuristicos < cidade2.pontosTuristicos) {
                printf("%s venceu! Mais pontos turisticos.\n", cidade2.nome);
            } else {
                printf("Empate nos pontos turisticos!\n");
            }
            break;
        default:
            printf("Atributo invalido!\n");
    }
}

int main() {
   
    struct Pais estados[NUM_ESTADOS]; // Estados de A a H
    struct Cidade cidades[NUM_ESTADOS][NUM_CIDADES]; // Matriz de cidades

  

    // Preenchendo os dados das cidades
    for (int i = 0; i < NUM_ESTADOS; i++) {

         // Perguntar o nome do país
         printf("Digite o nome do pais do estado %c: ", 'A' + i);
         scanf("%s", estados[i].nomePais);   // Captura o nome do país

        for (int j = 0; j < NUM_CIDADES; j++) {

           

            printf("Cadastro da cidade %d do estado %c:\n", j + 1, 'A' + i);
            
            printf("Digite o nome da cidade: ");
            scanf("%s", cidades[i][j].nome);

            printf("Digite a populacao da cidade: ");
            scanf("%d", &cidades[i][j].populacao);

            printf("Digite a area da cidade (em km): ");
            scanf("%f", &cidades[i][j].area);

            printf("Digite o PIB da cidade (em bilhoes): ");
            scanf("%f", &cidades[i][j].pib);

            printf("Digite o numero de pontos turisticos: ");
            scanf("%d", &cidades[i][j].pontosTuristicos);

            printf("\n");
        }
    }

    // Exibir todas as cidades cadastradas
    printf("Cadastro das cidades:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            exibirCidade(cidades[i][j], 'A' + i, j + 1, estados[i].nomePais);   // Passa o nome do país
        }
    }

    int opcao, cidade1, cidade2, atributo;

    // Menu interativo
    do {
        printf("\nMenu de Comparacao de Cartas:\n");
        printf("1. Comparar duas cidades\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Escolha duas cidades para comparar:\n");
            printf("Digite o numero do pais (1 a 8) e o numero da cidade (1 a 4):\n");

            printf("Primeira cidade - Pais (1 a 8) e Cidade (1 a 4): ");
            scanf("%d %d", &cidade1, &cidade2);
            cidade1--;  // Ajusta o índice para 0 baseado
            cidade2--;  // Ajusta o índice para 0 baseado

            printf("Escolha o atributo para comparacao:\n");
            printf("1. Populacao\n");
            printf("2. Area\n");
            printf("3. PIB\n");
            printf("4. Pontos turisticos\n");
            printf("Escolha um atributo: ");
            scanf("%d", &atributo);

            // Comparar as cartas
            compararCartas(cidades[cidade1 / NUM_CIDADES][cidade1 % NUM_CIDADES], 
                           cidades[cidade2 / NUM_CIDADES][cidade2 % NUM_CIDADES], 
                           atributo);
        }
    } while (opcao != 2);

    return 0;
}
