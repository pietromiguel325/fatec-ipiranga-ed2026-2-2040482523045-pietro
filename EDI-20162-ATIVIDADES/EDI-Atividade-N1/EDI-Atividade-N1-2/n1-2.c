#include <stdio.h>
#define tamanho_estoque 5
#define estoque_minimo 10

int estoque[tamanho_estoque];

void exibirCabecalho() {
    printf("========================================\n");
    printf("SISTEMA DE ESTOQUE - LOJA CONSTRUMAIS\n");
    printf("========================================\n");
}
void preencherEstoque(void) {
    int *p = estoque;
    int i;
    for(i=0; i<tamanho_estoque;i++) {
        printf("Quantidade do produto %d: ", i+1);
        scanf("%d", p + i);
    }
}
void exibirEstoque(int momento) {
    int *p = estoque;
    int i;
    if(momento == 0) {
        printf("\n-- Estoque Atual (antes da reposicao) --\n");
    }
    else {
        printf("\n-- Estoque final (apos reposicao) --\n");
    }
    for(i=0;i<tamanho_estoque;i++) {
        printf("Produto %d: %d\n",i+1, *(p+i));
    }
    printf("\n");
}
float calcularMediaEstoque(void) {
    int *p = estoque;
    int i;
    // p + i -> acessa o endereço, e retorna o endereço.
    // *(p + i) -> acessa o valor guardado no endereço, retorna o valor. 
    float soma = 0;
    for(i=0;i<tamanho_estoque;i++) {
        soma += *(p + i);
    }
    return soma / tamanho_estoque;
}
void simularReposicao(int quantidadeAtual, int reposicao) {
    int simulacao = quantidadeAtual + reposicao;
    printf("Simulacao para o produto 1: %d + %d = %d (nao aplicado ainda)\n", quantidadeAtual, reposicao, simulacao);
}
void aplicarReposicaoGeral(int reposicao) {
    int *p = estoque;
    int i;
    for(i=0;i<tamanho_estoque;i++) {
        (*(p+i) += reposicao);
    }
}
void identificarEstoqueCritico(int minimo) {
    int *p = estoque;
    int i, encontrado = 0;
    for(i=0;i<tamanho_estoque;i++) {
        if(*(p + i) < minimo) {
            printf("Produto %d esta em nivel critico: %d unidades (abaixo do minimo)\n", i+1, *(p +i));
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("O estoque esta regularizado\n");
    }
}
int main() {
    float media;
    int quant_reposicao;
    // Exibir Cabeçalho
    exibirCabecalho();

    // Preencher Estoque
    preencherEstoque();

    // Quantidade de Reposição
    printf("Quantidade de reposicao a aplicar: ");
    scanf("%d", &quant_reposicao);

    // Exibe o Estoque Inicial
    exibirEstoque(0);

    // Simulação de reposição (sem alterar no estoque)
    printf("-- Simulacao de reposicao (passagem or valor) --\n");
    simularReposicao(estoque[0], quant_reposicao);
    printf("Quantidade do produto 1 apos a simulacao (inalterada): %d\n", estoque[0]);

    // Aplicação real da reposicacao
    printf("\n-- Aplicacao real da reposicao (ponteiro interno ao vetor global) --\n");
    aplicarReposicaoGeral(quant_reposicao);
    printf("Reposicao de %d unidades aplicada a todos os produtos do estoque.\n", quant_reposicao);

    // Exibe o Estoque Final
    ExibirEstoque(1);

    // Exibe a média geral
    printf("-- Media geral do estoque --\n");
    media = calcularMediaEstoque();
    printf("Media final: %.2f\n unidades", media);

    // Analisa se o estoque está abaixo do mínimo
    printf("\n-- Analise de estoque critico (minimo = %d unidades) --\n", estoque_minimo);
    identificarEstoqueCritico(estoque_minimo);
    return 0;
}