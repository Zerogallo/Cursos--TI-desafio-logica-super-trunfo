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
void exibirCidade(struct Cidade cidades, char estado, int cidadeNumero, char nomePais[]) {
    // Gerar o código da carta com base no estado e cidade
    printf("Codigo da carta: %c%02d\n", estado, cidadeNumero);
    printf("Pais: %s\n", nomePais);
    printf("  Cidade: %s\n", cidades.nome);
    printf("    Populacao: %d habitantes\n", cidades.populacao);
    printf("    Area: %.2f km\n", cidades.area);
    printf("    PIB: %.2f bilhoes de unidades monetarias\n", cidades.pib);
    printf("    Pontos turisticos: %d\n", cidades.pontosTuristicos);
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
         printf("\n");

        for (int j = 0; j < NUM_CIDADES; j++) {

           

            printf("Cadastro da cidade %d do estado %c:\n", j + 1, 'A' + i);
            
            printf("Digite o nome da cidade: ");
            scanf("%s", cidades[i][j].nome);
            printf("\n");

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

    int opcao, pais1, pais2, cidade1, cidade2, atributo;

// Menu interativo
do {
    
    printf("\nMenu de Comparacao de Cartas:\n");
    printf("\n");
    printf("1. Comparar duas Cartas\n");
    printf("2. Sair\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1) {
        // Escolher as cidades para comparação
        printf("Escolha duas Cartas para comparar:\n");
        // Exibir países e suas cidades
        for (int i = 0; i < NUM_ESTADOS; i++) {
            printf("\nPais %d: %s\n\n", i + 1, estados[i].nomePais);
            for (int j = 0; j < NUM_CIDADES; j++) {
                // Gerar o código da carta, que é composto pelo estado (A, B, C, ...) e número da cidade (1 a 4)
                printf("  (Carta: %c%02d) Cidade %d: %s ", 
                        'A' + i,  // 'A' + i gera a letra correspondente ao estado
                        j + 1,  // j + 1 gera o número da cidade (1 a 4)
                        j + 1, 
                        cidades[i][j].nome);
                        
            }
            printf("\n");
        }
        printf("\n");

        // Primeira cidade - Escolher país e cidade
        do {
            printf("Primeira Carta - Digite o numero do pais (1 a 8): ");
            scanf("%d", &pais1);
    
            // Verifica se o número está dentro do intervalo válido
            if (pais1 < 1 || pais1 > 8) {
                printf("Numero invalido! Por favor, digite um numero entre 1 e 8.\n");
            }
    
        } while (pais1 < 1 || pais1 > 8);  // Repete até o número ser válido
        pais1--;  // Ajusta para o índice 0
        printf("\n");

       
        do {
            printf("Escolha a cidade do pais %s (1 a 4): ", estados[pais1].nomePais);
            scanf("%d", &cidade1);
    
            // Verifica se o número está dentro do intervalo válido
            if (cidade1 < 1 || cidade1 > 4) {
                printf("Numero invalido! Por favor, Escolha a cidade do pais %s (1 a 4): \n", estados[pais1].nomePais);
            }
    
        } while (cidade1 < 1 || cidade1 > 4);  // Repete até o número ser válido
        cidade1--;  // Ajusta para o índice 0
        printf("Escolha a cidade %s  ",cidades[pais1][cidade1].nome);

        printf("\n");

        // Segunda cidade - Escolher país e cidade
      
        do {
            printf("Segunda Carta - Digite o numero do pais (1 a 8): ");
            scanf("%d", &pais2);
    
            // Verifica se o número está dentro do intervalo válido
            if (pais2 < 1 || pais2 > 8) {
                printf("Numero invalido! Por favor, digite um numero entre 1 e 8.\n");
            }
    
        } while (pais2 < 1 || pais2 > 8);  // Repete até o número ser válido
        pais2--;  // Ajusta para o índice 0
        printf("\n");

       
        do {
            printf("Escolha a cidade do pais %s (1 a 4): ", estados[pais1].nomePais);
            scanf("%d", &cidade2);
    
            // Verifica se o número está dentro do intervalo válido
            if (cidade2 < 1 || cidade2 > 4) {
                printf("Numero invalido! Por favor, Escolha a cidade do pais %s (1 a 4): \n", estados[pais2].nomePais);
            }
    
        } while (cidade2 < 1 || cidade2 > 4);  // Repete até o número ser válido
        cidade2--;  // Ajusta para o índice 
        printf("Escolha a cidade %s  ", cidades[pais2][cidade2].nome);
        printf("\n");
        

        printf("   %s, %s   &   %s, %s   \n", 
            estados[pais1].nomePais, cidades[pais1][cidade1].nome, 
            estados[pais2].nomePais, cidades[pais2][cidade2].nome);

        printf("\n");

        // Escolher o atributo para comparação
        do{

            printf("Escolha o atributo para comparacao:\n");
            printf("\n");
            printf("1. Populacao\n");
            printf("2. Area\n");
            printf("3. PIB\n");
            printf("4. Pontos turisticos\n");
            printf("\n");
            printf("Escolha um atributo: ");
            scanf("%d", &atributo);
            printf("\n");

            if (atributo < 1 || atributo > 4) {
                printf("Numero invalido! Por favor, digite um numero entre 1 e 4.\n");
            }
            // Comparar as cartas
            compararCartas(cidades[pais1][cidade1], cidades[pais2][cidade2], atributo);
        }while (opcao != 4);

    }

    if (opcao < 1 || opcao > 2) {
        printf("Numero invalido! Por favor, digite um numero entre 1 e 2.\n");
    }
} while (opcao != 2);

return 0;
}
