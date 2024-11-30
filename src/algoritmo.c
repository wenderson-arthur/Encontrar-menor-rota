#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include <limits.h>

#define CIDADE_INICIAL 4

int encontrarCidadeMaisProxima(int cidadeAtual, int visitada[TAMANHO_MATRIZ], int* matriz) {
    // Atribui o maior valor possivel p-ara 'distancia_minima' para garantir que qualquer distancia lida do arquivo seja menor
    int distancia_minima = INT_MAX;

    // Inicia com '-1' para indicar que nenhuma cidade foi visitada ainda
    int cidade_mais_proxima = -1;

    // Loop para iterar por todas as cidades
    for (int i = 0; i < TAMANHO_MATRIZ; i++) {
        // Verifica se cidade 'i' não foi visitada e se a distancia da cidade atual para 'i' é menor que a 'distancia_minima'
        if (visitada[i] != 1 && matriz[cidadeAtual * TAMANHO_MATRIZ + i] < distancia_minima) {
            // Se a distancia for menor, salva ela e o seu indice
            distancia_minima = matriz[cidadeAtual * TAMANHO_MATRIZ + i];
            cidade_mais_proxima = i;
        }
    }
    // Retorna o indice da cidade mais próxima não visitada
    return cidade_mais_proxima;
}

void encontrarRota(int cidade_atual, int* matriz, int visitada[], int rota[], int* distancia_total, int passo_atual) {
    // Verifica se todas as cidades foram visitadas
    if (passo_atual == TAMANHO_MATRIZ) {
        // Adicionar a distância de volta à cidade inicial
        *distancia_total += matriz[cidade_atual * TAMANHO_MATRIZ + CIDADE_INICIAL];
        // Retornar a São Luís
        rota[passo_atual] = CIDADE_INICIAL; 
        // Termina a recursão porque todas as cidades foram visitadas
        return;
    }

    // Encontra a proxima cidade mais próxima não visitada
    int proxima_cidade = encontrarCidadeMaisProxima(cidade_atual, visitada, matriz);
    // Verifica se foi possivel encontrar a próxima cidade
    if (proxima_cidade == -1) {
        printf("Erro: não foi possível encontrar a próxima cidade.\n");
        return;
    }

    // Marca a próxima cidade como visitada
    visitada[proxima_cidade] = 1;

    // Adiciona a próxima cidade à rota
    rota[passo_atual] = proxima_cidade;
    
    // Adiciona a distância da cidade atual para a próxima cidade a distância total
    *distancia_total += matriz[cidade_atual * TAMANHO_MATRIZ + proxima_cidade];

    // Chama a função recursivamente para continuar a encontrar a rota a partir da próxima cidade
    encontrarRota(proxima_cidade, matriz, visitada, rota, distancia_total, passo_atual + 1);
}

void algoritmo(int* matriz, Cidade* cidades) {
    // Array para indicar se uma cidade foi visitada
    int visitada[TAMANHO_MATRIZ] = {0};

    // Armazena a ordem das cidades na rota, o tamanho é 'TAMANHO_MATRIZ + 1' para que possa incluir o retorno a origem
    int rota[TAMANHO_MATRIZ + 1];

    // Variável para guardar a distância total da rota
    int distancia_total = 0;

    // Index 0 para começar de São Luís
    int cidade_atual = CIDADE_INICIAL;

    // Marca a cidade atual como visitada
    visitada[cidade_atual] = 1;

    // Define de onde começa a rota
    rota[0] = cidade_atual;

    // Chama a função para encontrar a rota a partir da cidade atual
    encontrarRota(cidade_atual, matriz, visitada, rota, &distancia_total, 1);

    // Imprimir a rota e a distância total
    printf("Rota: ");
    for (int i = 0; i <= TAMANHO_MATRIZ; i++) {
        printf("%s", cidades[rota[i]].nome);
        if (i < TAMANHO_MATRIZ) {
            printf(" → ");
        }
    }
    printf("\nDistância total: %d km\n", distancia_total);
}