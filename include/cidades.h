
#ifndef __CIDADES_H_
#define __CIDADES_H_

typedef struct __cidade__ {
    char nome[50];    
} Cidade;

Cidade* ler_cidades(const char *nome_arquivo, int quant_cidades);
void liberar_cidades(Cidade *cidades);

#endif