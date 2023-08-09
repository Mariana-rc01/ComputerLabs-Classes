// Problema C - Compassos irrepetidos

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {

    // numero de linhas a serem lidas
    int N;

    // qual o numero do conjunto para aquela linha que vai ser preciso separar a string
    int X;

    // string de cada linha
    char nota[1001];

    // numero de linhas a serem lidas
    assert(scanf("%d", &N) == 1);

    // qual a posiçao do conjunto que as letras sao todas diferentes em cada linha
    // caso nao haja, terá valor -1 nessa linha
    int posicoes[N];

    for (int i = 0; i < N; i++) {

        assert(scanf("%d %s",&X, nota) == 2);

        // assume-se que nao existe nenhum conjunto com as letras todas diferentes
        posicoes[i] = -1;

        //tamanho da string da linha i
        int tamanho = strlen(nota);

        // vamos "curtar" a string de modo que so tenha os caracteres que inserimos
        char notas[tamanho];

        for(int a = 0; a < tamanho; a++) {
            notas[a] = nota[a];
        }

        // percorre cada conjunto de caracteres com tamanho X,
        // garantindo com j <= tamanho - X que nao ultrapassamos a string
        for (int j = 0; j <= tamanho-X; j++) {

            // assume-se que nao há letras repetidas no conjunto a analisar
            int letrasRepetidas = 1;

             //percorre aquele conjunto de letras e verifica se sao todas diferentes
            for (int k = j; k < j+X; k++) {
                for (int m = k+1; m < j+X; m++) {
                // compara a letra que está na posiçao k com as posiçoes seguintes ate que o conjunto termine
                    if (notas[k] == notas[m]) // quando há letra repetida
                        { letrasRepetidas = 0;
                          break;
                        }
                }
            }
            // nao havendo letras repetidas, a posicao da linha i é o valor j,
            // pois é no conjunto de X letras com inicio nesse valor que nao há repetiçao de letras
            if (letrasRepetidas) {posicoes[i] = j; break;}
        }
    }

    //imprime a posiçao de cada linha
    for (int n = 0; n < N; n++) {
        printf("%d\n",posicoes[n]);
    }

    return 0;
}