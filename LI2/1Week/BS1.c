// Problema B - Haja ordem!

#include <stdio.h>
#include <assert.h>

int main () {
    int a, b, c;
    
    assert (scanf("%d %d %d",&a, &b, &c) == 3);
    //alturas dos soldados

    if ((a >= b && b >= c) || (a <= b && b <= c)) printf("OK\n");
    else printf ("NAO\n");

    /*
    Caso as alturas sejam iguais ou estejam por ordem crescente ou decrescente, escreve OK.
    Caso contrario, escreve NAO.
    */

    return 0;
}