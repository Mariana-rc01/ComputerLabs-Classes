// Problema B - Códigos numéricos

#include <stdio.h>
#include <assert.h>

int main() {
    int nLinhas; // numero de Linhas

    assert(scanf("%d", &nLinhas) == 1);
    getchar(); //descarta o \n pendente
    
    int numero[nLinhas]; //codigo da fechadura
    char linha[nLinhas]; //cada linha
    char direcao; //comando de direção
    numero[0] = 5; //iniciamos sempre em 5

    for (int i = 0; i < nLinhas; i++) {

        if (i != 0) numero[i] = numero[i-1]; //o numero que vai iniciar a fazer as contas é o anterior

        if (fgets(linha,20,stdin) != NULL) { //comandos daquela linha
            // fgets lê uma linha de caracteres, stdin diz que a leitura
            // realiza-se a partir do buffer do teclado

            int j = 0;

            while (linha[j] != '\0') { //enquanto a string nao terminar
                direcao = linha[j];
                if (direcao == 'C' && numero[i] != 8 && numero[i] != 9 && numero[i] != 7)
                    numero[i]+=3;
                if (direcao == 'B' && numero[i] != 1 && numero[i] != 2 && numero[i] != 3)
                    numero[i]-=3;
                if (direcao == 'E' && numero[i] != 1 && numero[i] != 4 && numero[i] != 7)
                    numero[i]--;
                if (direcao == 'D' && numero[i] != 3 && numero[i] != 6 && numero[i] != 9)
                    numero[i]++;

                // as condiçoes são para quando tentam sair da parte numérica do keypad

                j++;
            }
        }
    }

    for(int k = 0; k < nLinhas; k++) {
        printf("%d",numero[k]); // imprime os numeros, sendo esta a linha com o código da fechadura
    }

    printf("\n");

    return 0;
}