// Problema A - Canções alternadas

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {

    int N; // numero de linhas a serem lidas
    
    assert(scanf("%d", &N) == 1);

    // descarta qualquer caracter pendente no buffer do teclado
    getchar();

    // conta quantas palavras compostas por consoantes alternadas com vogais existem
    int contador[N];

    // cada linha pode ter no maximo 1000 caracteres
    char linha[1001];

    for (int i = 0; i < N; i++) {

        contador[i] = 0;

        if (fgets(linha,1001,stdin) != NULL) { //linha i
            
            // cada palavra é separada por um espaço ou por um paragrafo (palavra final)
            // usando a funçao strtok que separa a linha por um desses caracteres
            char *palavra = strtok (linha, " \n");

            // analisa cada palavra
            while (palavra != NULL) {

                // quantos caracteres a palavra tem
                int tamanho = strlen (palavra);

                // indica se a ultima letra foi consoante = 0 ou a ultima letra foi vogal = 0
                // e assume-se que a palavra é alternada
                int consoante = 0, vogal = 0, alternado = 1;

                // percorre-se a palavra
                for(int j = 0; j < tamanho; j++) {

                    // forma mais simples de analisar a letra que está na posiçao j da palavra
                    // inves de estar sempre a escrever palavra[j] na linha seguinte
                    char c = palavra[j];

                    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') { // a letra analisada c é uma vogal
                        if (consoante == 0) {consoante = 1; vogal = 0;}
                        /* se a letra anterior é uma consoante:
                        - c é uma vogal (vogal = 0)
                        - c nao é consoante (consoante = 1, a ultima letra deixa de ser uma consoante)*/
                        else {alternado = 0; break;}
                        // a letra anterior é uma vogal e portanto nao podem haver duas vogais seguidas
                        // terminando assim a comparaçao
                    }
                    else { // c é uma consoante
                        if (vogal == 0) {vogal = 1; consoante = 0;}
                        /* se a letra anterior é uma vogal:
                        - c é uma consoante (consoante = 0)
                        - c nao é vogal (vogal = 1, a ultima letra deixa de ser uma vogal)*/
                        else {alternado = 0; break;} 
                        // a letra anterior é uma consoante e portanto nao podem haver duas consoantes seguidas
                        // terminando assim a comparaçao
                    }
                }
                // se depois de percorrer a palavra nao tiver havido nenhumas vogais ou consoantes seguidas,
                // entao o contador é incrementado
                if (alternado == 1) contador[i]++;

                /* como acabamos de ver a palavra, usamos strtok com NULL para que continue
                 a ver as palavras restantes onde parou, ou seja, continua a analisar a linha
                 a partir da palavra ja vista e separa ja a proxima palavra.*/
                palavra = strtok(NULL, " \n");
            }
        }
    }

    // imprime-se quantas palavras alternadas haviam em cada linha
    for (int j = 0; j < N; j++) {
        printf("%d\n",contador[j]);
    }

    return 0;
}