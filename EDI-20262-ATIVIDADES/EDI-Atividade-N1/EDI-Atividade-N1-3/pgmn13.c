/*
 * Disciplina: Estrutura de Dados
 * Prof. Verissimo
 * Objetivo do Programa: Gerenciamento de frota com alocacao dinamica e recursividade
 * Data: 31/08/2026
 * Autor: Pietro Miguel Simões de Oliveira
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALOR_PREMIUM 100.0

// 1. 
typedef struct {
    char placa[8];
    float valor;
} Veiculo;

// 3. 
void exibirCabecalho(void) {
    printf("================================================\n");
    printf("LAVA-RAPIDO BRILHO TOTAL - FILA DE ATENDIMENTO\n");
    printf("================================================\n");
}

// 4. 
void preencherFrota(Veiculo *frota, int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        printf("Placa do veiculo %d: ", i + 1);
        scanf("%s", (frota + i)->placa);
        printf("Valor do servico (R$): ");
        scanf("%f", &(frota + i)->valor);
    }
}

// 5. 
void exibirFrotaRecursivo(Veiculo *frota, int indice, int quantidade) {
    if (indice == quantidade) {
        return;
    }
    printf("%d) Placa: %s | Valor: R$ %.2f\n", indice + 1, frota[indice].placa, frota[indice].valor);
    exibirFrotaRecursivo(frota, indice + 1, quantidade);
}

// 6. 
float calcularValorTotalRecursivo(Veiculo *frota, int indice, int quantidade) {
    // CASO BASE: Quando o indice atinge a quantidade total (indice == quantidade), a recursao encerra e retorna 0.0f.
    if (indice == quantidade) {
        return 0.0f;
    }
    // PASSO RECURSIVO: Retorna o valor do veiculo atual somado ao resultado da chamada para o proximo elemento (indice + 1).
    return frota[indice].valor + calcularValorTotalRecursivo(frota, indice + 1, quantidade);
}

// 7. 
int buscarVeiculoRecursivo(Veiculo *frota, int indice, int quantidade, char placa[8]) {
    if (indice == quantidade) {
        return -1;
    }
    if (strcmp(frota[indice].placa, placa) == 0) {
        return indice;
    }
    return buscarVeiculoRecursivo(frota, indice + 1, quantidade, placa);
}

// 8. 
int contarPremiumRecursivo(Veiculo *frota, int indice, int quantidade) {
    if (indice == quantidade) {
        return 0;
    }
    if (frota[indice].valor >= VALOR_PREMIUM) {
        return 1 + contarPremiumRecursivo(frota, indice + 1, quantidade);
    } else {
        return contarPremiumRecursivo(frota, indice + 1, quantidade);
    }
}

int main() {
    int quantidade;

    // 3. 
    exibirCabecalho();

    // 2. 
    printf("Quantos veiculos serao atendidos hoje? ");
    scanf("%d", &quantidade);

    Veiculo *frota = (Veiculo *) malloc(quantidade * sizeof(Veiculo));

    if (frota == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // 4. 
    preencherFrota(frota, quantidade);

    // 5. 
    printf("\n--- Veiculos atendidos hoje ---\n");
    exibirFrotaRecursivo(frota, 0, quantidade);

    // 7. 
    printf("\n--- Busca recursiva por placa ---\n");
    char placaBusca[8];
    printf("Placa a ser pesquisada: ");
    scanf("%s", placaBusca);

    int pos = buscarVeiculoRecursivo(frota, 0, quantidade, placaBusca);

    if (pos != -1) {
        printf("Veiculo encontrado na posicao %d! Placa: %s | Valor: R$ %.2f\n", 
               pos + 1, frota[pos].placa, frota[pos].valor);
    } else {
        printf("Veiculo nao encontrado na frota.\n");
    }
    
    // Resumo final 
    printf("\n--- Resumo do dia ---\n");
    printf("Total de veiculos atendidos: %d\n", quantidade);
    
    // 8. 
    int totalPremium = contarPremiumRecursivo(frota, 0, quantidade);
    printf("Servicos premium (>= R$ 100.00): %d\n", totalPremium);
    
    // 6.
    float soma = calcularValorTotalRecursivo(frota, 0, quantidade);
    printf("Valor total arrecadado: R$ %.2f\n", soma);

    // Liberação e anulação do ponteiro
    free(frota);
    frota = NULL;
    printf("Memoria da frota liberada com sucesso. Sistema encerrado.\n");
    return 0;
}