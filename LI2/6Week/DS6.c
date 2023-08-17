// Problema D - Viva la Revolucion!
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    int id;
    int timestamp; // indica quando o pedido deve estar pronto
    int tconfecao; // tempo de confeçao
    int lucro; // lucro por cada pedido
} pedido;

// Função auxiliar para ordenar os pedidos pelo tempo final dos mesmos
// caso o tempo final seja o mesmo verifica qual tem tempo de ficar pronto menor
int compara(const void *a, const void *b) {
    const pedido *p1 = (const pedido *)a;
    const pedido *p2 = (const pedido *)b;
    int fimp1 = p1->timestamp + p1->tconfecao;
    int fimp2 = p2->timestamp + p2->tconfecao;
    if (fimp1 == fimp2) {
        return p1->timestamp - p2->timestamp;
    }
    return fimp1 - fimp2;
}

int main() {
    int N;
    // Lê a quantidade de pedidos a serem inseridos
    assert(scanf("%d", &N) == 1);

    // irao haver N-pedidos
    pedido pedidos[N];

    // Lê os dados de cada pedido
    for (int i = 0; i < N; i++) {
        assert(scanf("%d %d %d %d", &pedidos[i].id, &pedidos[i].timestamp, &pedidos[i].tconfecao, &pedidos[i].lucro) == 4);
    }

    // Ordena os pedidos pelo tempo final
    qsort(pedidos, N, sizeof(pedido), compara);

    // array que guarda os lucros maximos
    int lucros[N];
    lucros[0] = pedidos[0].lucro;

    // Preenche o array lucros com os lucros máximos
    for (int i = 1; i < N; i++) {
        int lucro = pedidos[i].lucro;
        int j = i-1;
        // verifica o ultimo pedido anterior que termina antes do inicio do pedido atual
        while (j >= 0 && (pedidos[j].timestamp + pedidos[j].tconfecao > pedidos[i].timestamp)) j--;

        // se o pedido anterior for valido, adicionamo-lo
        if (j >= 0) lucro += lucros[j];

        // atualiza o valor maximo do lucro
        if (lucro >= lucros[i-1]) lucros[i] = lucro;
        else lucros[i] = lucros[i-1];
    }
    
    // Imprime o lucro maximo obtido
    printf("%d\n", lucros[N-1]);

    return 0;
}

/*
Valores:
Input 1
6
1 10 7 2
2 3 3 1
3 8 4 3
4 13 5 2
5 20 7 4
6 21 9 2

Output 1
10
----------------------------
Input 2
5
1 110 110 5
2 407 86 14
3 320 72 6
4 226 121 16
5 373 40 6

Output 2
36
--------------------------
Input 3
5
1 218 76 15
2 267 96 17
3 104 104 19
4 334 173 12
5 485 164 20

Output 3
56
------------------------
Input 4
10
1 68 68 19
2 641 8 8
3 305 83 15
4 414 170 14
5 158 60 8
6 675 116 14
7 625 18 12
8 779 121 19
9 555 83 15
10 199 103 15

Output 4
103
--------------------------
Input 5
20
1 1390 133 18
2 1980 18 16
3 162 129 14
4 581 83 5
5 73 73 5
6 293 123 5
7 1736 119 12
8 634 143 18
9 806 92 10
10 1192 44 11
11 893 153 19
12 2158 34 18
13 122 17 5
14 1999 179 8
15 409 156 11
16 1851 125 15
17 1238 168 7
18 1559 149 15
19 1046 123 11
20 1520 41 15

Output 5
166
*/