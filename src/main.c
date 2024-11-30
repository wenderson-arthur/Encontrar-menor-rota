#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"

int main(int argc, char const *argv[])
{

    int *matriz = ler_arquivo("distancias.txt", TAMANHO_MATRIZ);

    Cidade *cidades = ler_cidades("cidades.txt", TAMANHO_MATRIZ);

    algoritmo(matriz, cidades);

    liberar_matriz(matriz);
    liberar_cidades(cidades);

    return 0;
}