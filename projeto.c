// NOME: Arthur Carbajo de Souza      RA: 32327961
// NOME: Guilherme Rainho Geraldo     RA: 32342543

#include <stdio.h>

// Imprimir um polinômio na tela:
void imprimirPolinomio(int coeficientes[], int grau) {
    int i;
    for (i = grau; i >= 0; i--) {
        if (coeficientes[i] != 0) {
            if (i != grau) {
                if (coeficientes[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" ");
                }
            }
            if (i == 0 || coeficientes[i] != 1) {
                printf("%d", coeficientes[i]);
            }
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
        }
    }
    printf("\n");
}

// Calcular o valor do polinomio 1 com um "X" determinado:
int calcularValorPolinomio(int coeficientes[], int grau, int x) {
    int resultado = 0;
    int potenciaX = 1;
    int i;

    for (i = 0; i <= grau; i++) {
        resultado += coeficientes[i] * potenciaX;
        potenciaX *= x;
    }

    return resultado;
}

// Somar os dois polinômios: 
void somarPolinomios(int polinomio1[], int polinomio2[], int resultado[], int grau1, int grau2) {
    int tamanhoResultado = (grau1 > grau2 ? grau1 : grau2) + 1;
    int i;

    for (i = 0; i <= tamanhoResultado; i++) {
        resultado[i] = 0;
        if (i <= grau1) {
            resultado[i] += polinomio1[i];
        }
        if (i <= grau2) {
            resultado[i] += polinomio2[i];
        }
    }
}

// Multiplicar os dois polinômios: 
void multiplicarPolinomios(int polinomio1[], int polinomio2[], int resultado[], int grau1, int grau2) {
    int tamanhoResultado = grau1 + grau2 + 1;
    int i, j;

    for (i = 0; i <= tamanhoResultado; i++) {
        resultado[i] = 0;
        for (j = 0; j <= grau1; j++) {
            if (i - j >= 0 && i - j <= grau2) {
                resultado[i] += polinomio1[j] * polinomio2[i - j];
            }
        }
    }
}

int main() {
    int grau1, grau2;

    // Entrada de dados: 
    printf("Digite o grau do primeiro polinomio: ");
    scanf("%d", &grau1);

    printf("Digite o grau do segundo polinomio: ");
    scanf("%d", &grau2);

    int polinomio1[grau1 + 1];
    int polinomio2[grau2 + 1];
    int resultadoSoma[grau1 + grau2 + 1];
    int resultadoMultiplicacao[grau1 + grau2 + 1];

    int i;

    // Entrada dos coeficientes do primeiro polinômio: 
    printf("\nDigite os coeficientes do primeiro polinomio (do termo independente ao termo de maior grau):\n");
    for (i = 0; i <= grau1; i++) {
        scanf("%d", &polinomio1[i]);
    }

    // Entrada dos coeficientes do segundo polinômio: 
    printf("\nDigite os coeficientes do segundo polinomio (do termo independente ao termo de maior grau):\n");
    for (i = 0; i <= grau2; i++) {
        scanf("%d", &polinomio2[i]);
    }

    // Apresentação de dados: 
    printf("\nPolinomio 1: ");
    imprimirPolinomio(polinomio1, grau1);

    printf("\nPolinomio 2: ");
    imprimirPolinomio(polinomio2, grau2);

    int x;
    printf("\nDigite o valor de x para avaliar o polinomio 1: ");
    scanf("%d", &x);

    int resultadoAvaliacao = calcularValorPolinomio(polinomio1, grau1, x);
    printf("Resultado da avaliacao do polinomio 1 em x=%d: %d\n", x, resultadoAvaliacao);

    somarPolinomios(polinomio1, polinomio2, resultadoSoma, grau1, grau2);
    printf("\nResultado da adicao: ");
    imprimirPolinomio(resultadoSoma, grau1 + grau2);

    multiplicarPolinomios(polinomio1, polinomio2, resultadoMultiplicacao, grau1, grau2);
    printf("\nResultado da multiplicacao: ");
    imprimirPolinomio(resultadoMultiplicacao, grau1 + grau2);

    return 0;
}