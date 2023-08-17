// Problema C - Barafunda na Cozinha!

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char dificuldade;
    int preco;
} pedido;

/*
Criterios:
- Escolher sempre os mais caros;
- Escolher os mais faceis, A - mais facil, E - mais dificil;
- Escolher por ordem de pedidos sempre que tem o mesmo preço e dificuldade.

Funçao criterios:
A funçao recebe dois ponteiros genericos que apontam para 2 elementos
da lista que irao ser comparados. Nao conhecemos o tipo portanto os ponteiros sao declarados como void*.

A funçao devolve 0 se os pedidos forem iguais.
Devolve um valor positivo se o p1 pedido for maior que o p2. (logo p2 vem primeiro)
Devolve um valor negativo se o p1 for menor que o p2. (logo p1 vem primeiro)
*/

int criterios (const void *a, const void *b) {

    //convertemos os ponteiros para ponteiros do tipo pedido
    pedido *p1 = (pedido *) a;
    pedido *p2 = (pedido *) b;

    // designamos os numeros dos pedidos, dificuldades e preco da seguinte forma:
    int numero1 = p1->numero;
    int numero2 = p2->numero;
    char dificuldade1 = p1->dificuldade;
    char dificuldade2 = p2->dificuldade;
    int preco1 = p1->preco;
    int preco2 = p2->preco;

    // se os precos forem iguais, comparamos as dificuldades
    if (preco1 == preco2) {
        // se as dificuldades forem iguais comparamos o numero dos pedidos
        if (dificuldade1 == dificuldade2)
            // 0 se forem iguais, > 0 numero2 for maior que o numero1 (1º p2), < 0 caso contrario (1º p1)
            return numero1 - numero2;
        // se as dificuldades forem diferentes, > 0 se a dificuldade2 for maior (1º p2), < 0 caso contrario (1º p1)
        else return (dificuldade1 - '0') - (dificuldade2 - '0');
    }
    // retornar preco mais elevado, <0 se o pedido1 for mais caro (1º p1), caso contrario (1º p2)
    else return preco2 - preco1;
}

int main () {

    // numero de pedidos
    int N;
    assert(scanf("%d",&N) == 1);

    // temos N-pedidos
    pedido p[N];

    // registamo-los
    for (int i = 0; i < N; i++) {
        assert(scanf("%d %c %d", &p[i].numero, &p[i].dificuldade, &p[i].preco) == 3);
    }

    /* Ordenamos os funcionarios seguindo os diversos criterios.
    Se a funçao criterios devolver um valor == 0, entao os elementos sao iguais.
    Se devolver um valor <0, significa que o primeiro elemento deve ser ordenado antes do segundo elemento.
    Caso contrario (valor>0), o segundo elemento deve ser ordenado antes do primeiro elemento.*/
    qsort (p, N, sizeof(pedido), criterios);

    // imprimimos os pedidos ordenados segundo os criterios pedidos
    for (int i = 0; i < N; i++) {
        printf("%d %c %d\n", p[i].numero, p[i].dificuldade, p[i].preco);
    }
    return 0;
}
