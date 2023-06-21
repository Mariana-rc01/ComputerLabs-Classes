// Problema A - Mensagens semi-secretas

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {

    //ordem para reordenar a mensagem com numero maximo de posiçoes
    char posicaoLetrasMax[9];

    //quantas letras ficam em cada bloco
    int nLetras;
    
    //mensagem original com numero maximo de caracteres
    char mensagem[1001];

    //termina de registar as posiçoes e a mensagem quando é feito um \n
    if (scanf("%s[^\n]",posicaoLetrasMax) == 1 && scanf("%s[^\n]",mensagem) == 1) {
        
        // quantas letras vai haver efetivamente em cada bloco
        nLetras = strlen(posicaoLetrasMax);

        // novo array com o valor correto de quantas posiçoes de ordenaçao existem
        int posicaoLetras[nLetras];

        // "copia-se" os valores do array subtraindo o valor '0' da tabela de ASCII
        //para termos numero inteiro
        for (int i = 0; i < nLetras; i++) {
            posicaoLetras[i] = posicaoLetrasMax[i] - '0';
        }

        // quantos caracteres existem na mensagem a ser cifrada
        int tamanhoMensagem = strlen(mensagem);

        // mensagem cifrada
        char mensagemReordenada[1001] ;

        // posiçoes da mensagemReordenada
        int k = 0;
        // percorre todas as posiçoes
        for(int i = 0; i < nLetras; i++) {
            /* para cada posiçao posicaoLetras[i], vemos qual o caracter que corresponde na mensagem
            original, adicionando cada caracter encontrado na mensagemReordenada
            o j+=nLetras, para que veja a letra em cada bloco da posiçao i
            */
            for(int j = posicaoLetras[i]-1; j < tamanhoMensagem; j += nLetras) {
                mensagemReordenada[k] = mensagem[j];
                k++;
            }
        }

        // resultado: mensagem reordenada, percorrendo o array da mesma
        for(int m = 0; m < tamanhoMensagem; m++) {
            printf("%c", mensagemReordenada[m]);
        }

        printf("\n");
    }
    return 0;
}