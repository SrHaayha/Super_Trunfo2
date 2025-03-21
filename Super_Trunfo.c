#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular a densidade demográfica
float calcularDensidadeDemografica(int populacao, float area) {
    return populacao / area;
}

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta, char nomePais[], int populacao, float area, float pib, int pontosTuristicos) {
    strcpy(carta->nomePais, nomePais);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->pontosTuristicos = pontosTuristicos;
    carta->densidadeDemografica = calcularDensidadeDemografica(populacao, area);
}

// Função para exibir o menu e obter a escolha do usuário
int exibirMenu(int escolhaAnterior) {
    int escolha;
    printf("\nEscolha o atributo para comparar:\n");
    if (escolhaAnterior != 1) printf("1 - População\n");
    if (escolhaAnterior != 2) printf("2 - Área\n");
    if (escolhaAnterior != 3) printf("3 - PIB\n");
    if (escolhaAnterior != 4) printf("4 - Pontos Turísticos\n");
    if (escolhaAnterior != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para comparar dois atributos
float compararAtributo(struct Carta carta1, struct Carta carta2, int atributoEscolhido) {
    float valor1, valor2;

    switch (atributoEscolhido) {
        case 1: // População
            printf("Atributo: População\n");
            valor1 = (float) carta1.populacao; // Conversão explícita para float
            valor2 = (float) carta2.populacao; // Conversão explícita para float
            break;
        case 2: // Área
            printf("Atributo: Área\n");
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3: // PIB
            printf("Atributo: PIB\n");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            valor1 = (float) carta1.pontosTuristicos; // Conversão explícita para float
            valor2 = (float) carta2.pontosTuristicos; // Conversão explícita para float
            break;
        case 5: // Densidade Demográfica (inverte a lógica)
            printf("Atributo: Densidade Demográfica (menor vence)\n");
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;
            break;
        default:
            printf("Atributo inválido!\n");
            return 0;
    }

    printf("%s: %.2f\n", carta1.nomePais, valor1);
    printf("%s: %.2f\n", carta2.nomePais, valor2);

    // Regra especial para Densidade Demográfica (menor valor vence)
    if (atributoEscolhido == 5) {
        return (valor1 < valor2) ? 1 : (valor1 > valor2) ? -1 : 0;
    }
    
    // Regra padrão: maior valor vence
    return (valor1 > valor2) ? 1 : (valor1 < valor2) ? -1 : 0;
}

// Função principal para realizar a comparação
void compararCartas(struct Carta carta1, struct Carta carta2) {
    int escolha1, escolha2;
    float resultado1, resultado2, soma1 = 0, soma2 = 0;

    // Primeira escolha de atributo
    escolha1 = exibirMenu(0);
    resultado1 = compararAtributo(carta1, carta2, escolha1);
    soma1 += (resultado1 == 1) ? 1 : 0;
    soma2 += (resultado1 == -1) ? 1 : 0;

    // Segunda escolha de atributo (não pode repetir o primeiro)
    escolha2 = exibirMenu(escolha1);
    resultado2 = compararAtributo(carta1, carta2, escolha2);
    soma1 += (resultado2 == 1) ? 1 : 0;
    soma2 += (resultado2 == -1) ? 1 : 0;

    // Exibir a soma dos pontos
    printf("\nSoma dos pontos:\n");
    printf("%s: %.0f\n", carta1.nomePais, soma1);
    printf("%s: %.0f\n", carta2.nomePais, soma2);

    // Determinar o vencedor
    if (soma1 > soma2) {
        printf("Resultado: %s venceu!\n", carta1.nomePais);
    } else if (soma1 < soma2) {
        printf("Resultado: %s venceu!\n", carta2.nomePais);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Cadastro das duas cartas
    struct Carta carta1, carta2;

    // Inicializando as cartas
    cadastrarCarta(&carta1, "Brasil", 213000000, 8515767.0, 14480.0, 30);
    cadastrarCarta(&carta2, "Argentina", 45000000, 2780400.0, 487.0, 15);

    // Comparando as cartas
    compararCartas(carta1, carta2);

    return 0;
}
