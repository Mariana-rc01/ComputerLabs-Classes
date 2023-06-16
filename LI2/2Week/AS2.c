// Problema A - Navegação baralhada

#include <stdio.h>
#include <assert.h>

int main () {

    int nCartas, carta; //numero de cartas utilizadas e a carta a ser usada no momento
    int posicaoX = 0, posicaoY = 0; //posição da Kaya

    assert (scanf("%d",&nCartas) == 1);

    for (int i = 1; i <= nCartas; i++) {
        assert (scanf("%d",&carta) == 1);
        if (carta % 4 == 0) posicaoX++;
        if (carta % 4 == 1) posicaoY--;
        if (carta % 4 == 2) posicaoY++;
        if (carta % 4 == 3) posicaoX--;
    }
    /*
    São imensas cartas, de modo que não vamos escrever o movimento para cada.
    Como apenas há 4 direçoes, estas vão-se repetir de forma consistente tendo
    em conta o resto da sua divisão inteira com 4, podendo então fazer da forma apresentada no ciclo for.
    */

    printf("%d %d\n", posicaoX, posicaoY);

    return 0;
}