#include <stdio.h>
#include <stdlib.h>
#include "cidades.h"
#include <assert.h>

Cidade* ler_cidades(const char *nome_arquivo, int quant_cidades) {
    // Verifica se um arquivo válido foi passado na função
    assert(nome_arquivo);

    // Abre o arquivo pra leitura e verifica se a abertura deu certo
    FILE *arquivoCidades = fopen(nome_arquivo, "r");
    if (arquivoCidades == NULL) {
        printf("Erro ao abrir o arquivo de cidades!\n");
        return NULL;
    }

    // Aloca um vetor para as cidades e verifica se a alocação foi bem sucedida
    Cidade *cidades = (Cidade *)malloc(quant_cidades * sizeof(Cidade));
    assert(cidades);

    // Lê uma string do arquivo e armazena no membro 'nome' no indice 'i' da instância 'Cidade' no vetor 'cidades'
    for (int i = 0; i < quant_cidades; i++) {
        fscanf(arquivoCidades, "%49s", cidades[i].nome);
    }

    // Fecha o arquivo depois de todas as operações realizadas e retorna o vetor preenchido
    fclose(arquivoCidades);
    return cidades;
}

void liberar_cidades(Cidade *cidades)
{
    assert(cidades);
    free(cidades);
}