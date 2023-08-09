// Problema B - Repetições épicas

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {

    int N; // numero de linhas a serem lidas

    // palavra de cada linha
    char palavra[1001];

    assert(scanf("%d",&N) == 1);

    // letra repetidas em cada linha
    char letras[N];

    for (int i = 0; i < N; i++) {

        assert(scanf("%s", palavra) == 1);

        //tamanho da palavra da linha i
        int tamanho = strlen(palavra);

        // para cada posiçao j, verifica se há mais algum caracter seguinte igual ao que esta na sua posiçao
        for (int j = 0; j < tamanho; j++) {
            for(int k = j+1; k < tamanho; k++) {
                //caso haja, sabemos que é esse o caracter e nao é preciso continuar a verificar
                if (palavra[j] == palavra[k]) {letras[i] = palavra[j]; break;}
            }
        }
    }

    //imprime a letra repetida de cada linha
    for (int m = 0; m < N; m++) {
        printf("%c",letras[m]);
    }

    printf("\n");

    return 0;
}