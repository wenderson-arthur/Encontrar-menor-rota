#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <assert.h>

int *ler_arquivo(char *nome_arquivo, int quantidade_de_cidades)
{
    // Verificar se o argumento é válido antes de abrir o arquivo para leitura
    assert(nome_arquivo);

    // Abrindo arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL)
    {
        printf("Este arquivo não existe!\n");
        return NULL;
    }

    // Aloca uma matriz unidimensional e verifica se a alocação de memória foi bem sucedida
    int *matriz = (int *)malloc(sizeof(int) * (quantidade_de_cidades * quantidade_de_cidades));
    assert(matriz);

    // Dois loops for para ler linhas e colunas do arquivo e armazenar na matriz 
    for (int i = 0; i < quantidade_de_cidades; i++)
    {
        for (int j = 0; j < quantidade_de_cidades; j++)
        {
            fscanf(arquivo, "%d", &matriz[i * quantidade_de_cidades + j]);
        }
    }

    // Fecha o arquivo depois de todas as operações realizadas e retorna a matriz preenchida
    fclose(arquivo);
    return matriz;
}

void liberar_matriz(int *matriz)
{
    assert(matriz);
    free(matriz);
}