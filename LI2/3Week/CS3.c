// Problema C - Invasão em fila indiana

#include <stdio.h>
#include <assert.h>

int main() {
    int N; // numero de casos
    int K; // numero de anoes naquela linha
    int maior, altura = 0;

    assert(scanf("%d",&N) == 1); // numero de casos que vao apresentar
    int contador[N]; //quantos anoes estao visiveis em cada linha

    for (int i = 0; i < N; i++) {
        assert(scanf("%d",&K) == 1); //numero de anoes naquela linha
        maior = 0;
        contador[i] = 0;
        for (int j = 0; j < K; j++) {
            assert(scanf("%d",&altura) == 1);
            if (altura > maior) {contador[i]++; maior = altura;}
            // caso a altura seja superior, entao esta passa a ser a maior e o contador aumenta, pois o anao fica visivel
        }
    }

    for (int i = 0; i < N; i++) {
        printf ("%d\n",contador[i]); // imprime quantos anoes estao visiveis em cada linha
    }

    return 0;
}