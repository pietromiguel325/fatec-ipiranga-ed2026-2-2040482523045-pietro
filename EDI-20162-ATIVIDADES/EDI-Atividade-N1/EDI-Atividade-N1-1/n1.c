#include <stdio.h>
# define tamanho_turma 5

// Função que Exibi o cabeçalho
void exibirCabecalho() {
    printf("================================\n");
    printf("SISTEMA DE NOTAS - TURMA ADS\n");
    printf("================================\n");
}
// O vetor como parâmetro da função é um ponteiro que guarda o endereço do primeiro elemento (&vetor[0])
// Função iterativa que calcula e retorna a média aritmética das notas
float calcular_media(float vetor[], int tamanho) { // Recebe o vetor (passado por referência nativa) e seu tamanho
    int i; 
    float media, soma = 0; // Inicializa soma com 0 para evitar lixo de memória
    for(i=0;i<tamanho;i++) {
        soma += vetor[i]; // Acumula a soma de cada nota do vetor
    }
    media = soma / tamanho; // Calcula a média aritmética
    return media; // Retorna o valor da média
}

// Função com passagem por valor
void simular_ajuste(float notaOriginal, float bonus) { // Recebe cópias da primeira nota e do bônus
    float simulacao = notaOriginal + bonus; // Calcula a simulação sem alterar a variável original
    printf("Simulacao para o aluno 1: %.2f + %.2f = %.2f\n", notaOriginal, bonus, simulacao); // Exibe o resultado 
}

// Função que altera o valor original diretamente na memória
void aplicar_bonus(float *nota, float bonus) { // Recebe o ponteiro (endereço de memória) da nota e o bônus
    *nota += bonus; // altera o falor guardado no endereço
}

int main() {
    float vet[tamanho_turma];
    float media, bonus;
    int i;

    exibirCabecalho();

    // Laço para preenchimento do vetor de notas
    for(i=0;i<tamanho_turma;i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &vet[i]);
    }
    printf("Informe o valor do bonus a aplicar: ");
    scanf("%f", &bonus);

    printf("\n");
    media = calcular_media(vet, 5);
    printf("--- Media da turma antes do ajuste ---\n");
    printf("Media inicial: %.2f\n", media);

    // Demonstração da passagem por valor 
    printf("\n--- Simulacao do ajuste (passagem por valor) ---\n");
    simular_ajuste(vet[0], bonus);
    printf("Nota do aluno 1 apos a simulacao (inalterada): %.2f\n", vet[0]);

    // Aplicação do bônus em cada nota 
    printf("\nAplicacao real do bonus (passagem por referencia) ---\n");
    printf("Bonus de %.2f aplicado a todas as notas da turma.\n", bonus);
    for(i=0;i<tamanho_turma;i++) {
        aplicar_bonus(&vet[i], bonus); // Envia o endereço de memória da posição atual do vetor
    }

    // Exibe as notas finais com o bonus
    printf("\n--- Notas finais da turma ---\n");
    for(i=0;i<tamanho_turma;i++) {
        printf("Aluno %d: %.2f\n",i+1, vet[i]);
    }

    // Faz a média com os valores das notas atualizado
    printf("\n--- Media da turma apos o ajuste ---\n");
    media = calcular_media(vet, 5);
    printf("Media final: %.2f", media);
    return 0;
}