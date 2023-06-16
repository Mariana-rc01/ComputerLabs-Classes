// Problema C - Pedra Papel Tesoura

#include <stdio.h>
#include <assert.h>

int main () {

    int N; // numero de jogadas
    char inzel, cmd; //jogada da arquitetura inzel e jogada da arquitetura cmd, respetivamente
    int iGanhou = 0, empataram = 0, cGanhou = 0; //numero de jogadas ganhas pela inzel ou empate ou ganhas pela cmd

    assert (scanf("%d",&N) == 1); // regista quantas jogadas vao ser feitas
    getchar(); /*o \n está a ser guardado, pois não está a ser lido no scanf
    De modo que é necessário descartá-lo, usando assim a funçao getchar*/

    for (int i = 0; i < N; i++) {
        if (scanf("%c%c",&inzel, &cmd)) {
            if ((inzel == '@' && cmd == '*') || (inzel == '|' && cmd == '-') || (inzel == 'X' && cmd == '+'))
             empataram++;
            if ((inzel == '@' && cmd == '+') || (inzel == '|' && cmd == '*') || (inzel == 'X' && cmd == '-'))
             iGanhou++;
            if ((inzel == 'X' && cmd == '*') || (inzel == '@' && cmd == '-') || (inzel == '|' && cmd == '+'))
             cGanhou++;
        }
        getchar();
        /*Aqui também é necessário limpar o buffer de entrada, para que qualquer \n seja descartado
        podendo ler as jogadas seguintes corretamente*/
    }

    printf ("%d %d %d\n", iGanhou, cGanhou, empataram);
    return 0;
}