// Problema A - Biscoitos ou morte!

#include <stdio.h>
#include <assert.h>

int main () {
    int a, b, c, d, e;
    
    assert (scanf("%d %d %d %d %d",&a, &b, &c, &d, &e) == 5);
    //numero de biscoitos que cada soldado tem
    
    int maxPosicao = 1;
    int maxBiscoitos = 0;

    if (a >= maxBiscoitos) {
        maxBiscoitos = a;
        maxPosicao = 1;
    }

    if (b >= maxBiscoitos && b > a) {
        maxBiscoitos = b;
        maxPosicao = 2;
    }

    if (c >= maxBiscoitos && c > b) {
        maxBiscoitos = c;
        maxPosicao = 3;
    }

    if (d >= maxBiscoitos && d > c) {
        maxBiscoitos = d;
        maxPosicao = 4;
    }

    if (e >= maxBiscoitos && e > d) {
        maxBiscoitos = e;
        maxPosicao = 5;
    }

    /*
    Vamos verificando se o numero de biscoitos do soldado seguinte é superior ao anterior, caso seja
    entao é guardado como maximo de biscoitos o valor dele e a sua posiçao, caso contrario continua a 
    verificar as condiçoes.
    */

    printf ("%d\n", maxPosicao);
    return 0;
}
