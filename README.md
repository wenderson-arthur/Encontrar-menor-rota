# ENTREGA DE VACINAS

Problema resolvido na disciplina de Linguagem de Programação I da UFMA, com o objetivo de encontrar a menor rota entre as 15 maiores cidades do Maranhão, passando por elas uma única vez para fazer uma distribuição de vacinas (situação hipotética).

## DESCRIÇÃO

O programa utiliza uma abordagem de heurística gulosa para determinar a rota com a menor distância total, visitando cada cidade exatamente uma vez antes de retornar à cidade de origem. Essa abordagem faz escolhas imediatas com base na menor distância disponível, sem considerar possíveis rotas futuras mais curtas entre outras cidades. Esse algoritmo é a forma mais simples de resolver esse problema.

## FUNCIONALIDADES

- Encontrar a melhor rota entre as cidades especificadas.
- Calcular a distância total dessa rota.
- Exibir a rota escolhida.

## USO

Para executar o código, é necessário preparar dois arquivos:
1. 'distancias.txt': Contém uma matriz de distâncias onde cada linha representa as distâncias de uma cidade para as outras, incluindo a si mesma como origem.
Exemplo:
0 1 2 3
1 0 3 4
2 3 0 7
3 4 7 0

2. 'cidades.txt': Lista as cidades em ordem começando da cidade de origem da rota
Exemplo:
Cidade_Origem
Cidade_A
Cidade_B
Cidade_C

Certifique-se de que os nomes das cidades não contenham espaços e sejam separados por '_'.