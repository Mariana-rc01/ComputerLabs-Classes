// Problema B - Vigilância Eletrónica

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {
    // A - numero de pessoas a vigiar
    // N - numero de linhas que se seguem
    int A, N;

    assert(scanf("%d %d",&A, &N) == 2);

    // hora de chegada e de partida de cada linha
    // codigo do agente
    int C[N], P[N], Codigo[N];

    // login - regista quais agentes estiveram naquelas horas
    int login[24][A], nAgentes[24];

    // Inicializar as variaveis login e nAgentes
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < A; j++) {
            login[i][j] = 0;
        }
        nAgentes[i] = 0;
    }

    // Recebe cada linha com o codigo do agente, a hora de chegada e de partida
    for (int i = 0; i < N; i++) {
        assert(scanf("%d %d %d", &Codigo[i], &C[i], &P[i]) == 3);
        // Regista as horas que o agente esteve em vigilancia
        for(int j = C[i]; j <= P[i]; j++) {
            login[j][Codigo[i] - 1] = 1;
            nAgentes[j]++;
        }
    }

    // Para todas as horas vemos quais os agentes que estiveram na hora em questao
    for (int i = 0; i < 24; i++) {
        
        // m representa o codigo dos agentes
        int m = 1;
        if (nAgentes[i] >= 2) { // caso haja mais que um agente      
            // Imprime a hora
            printf("%d",i);
            // Imprime de forma ordenada os agentes que estiveram na hora i
            for (int k = 0; k < A; k++) {
                if (login[i][k] == 1) printf(" %d",m);
                m++;
            }
            printf("\n");
        }
    }
    return 0;
}