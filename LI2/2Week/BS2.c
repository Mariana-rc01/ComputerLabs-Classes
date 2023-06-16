// Problema B - Brincadeiras com elevadores

#include <stdio.h>
#include <assert.h>

int main() {

    int C, A, N, botao;

    assert(scanf("%d %d %d", &C, &A, &N) == 3); 
    /* Andar que começou (C)
    Total de andares (A)
    Numero de comandos (N)*/

    for (int i=1; i <= N; i++) {
        assert(scanf("%d", &botao) == 1);
        if (C + botao >= A)  C = A;
        else if (C + botao <= 0) C = 0;
        else C += botao;

    }
    /* Se C + botao > A, fica em A, se C + botao < 0, fica em 0.
    Se o Joao se encontra no topo do predio, não pode subir mais.
    O mesmo se passa quando se encontra no piso 0, não podendo descer mais.
    */

    printf ("%d\n", C);
    return 0;

}