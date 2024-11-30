
#ifndef __ALGORITMO_H_
#define __ALGORITMO_H_

#include "matriz.h"
#include "cidades.h"

int encontrarCidadeMaisProxima(int cidadeAtual, int visitada[TAMANHO_MATRIZ], int* matriz);
void encontrarRota(int cidade_atual, int* matriz, int visitada[], int rota[], int* distancia_total, int passo_atual);
void algoritmo(int *matriz, Cidade *cidades);

#endif