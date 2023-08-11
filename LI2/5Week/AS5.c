// Problema A - Burocracia Infernal

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

// Caso o elemento esteja no array, retorna 1, caso contrario retorna 0
int	search(int x, int a[], int n)	{
	int	i;
	for (i = 0;	i < n; i++) {
        if (a[i] == x) return 1;
    }
    return	0;
}

void imprimeOrdem(int s[], int tamanho, int n) {
    for (int i = 0; i < tamanho; i++) {
        if (i < tamanho - 1) printf("%d ",s[i]); // adiciona espaço para o seguinte numero
        else printf("%d", s[i]); // o ultimo elemento nao adiciona um espaço
    }
    if (n) printf(" CICLO INFERNAL\n"); // caso tenha chegado a um ciclo
    else printf("\n");
}


void verificaCiclo (int* s, int I) {
    // i é a posiçao do array, iniciando-se em I
    int i = I, acumulador[1000] = {I};

    // count é posiçao do acumulador que guarda a sucessão dos guichés visitados e o seu respetivo tamanho tambem
    int count = 1;

    while (1) {
        if (s[i-1] == 0) { // Caso a posiçao seja 0, os clientes param de se mover, terminando o ciclo
            imprimeOrdem(acumulador, count, 0);
            break;}
        else if (search(s[i-1], acumulador, count)) { // se o numero ja estiver no acumulador, entramos num ciclo
            imprimeOrdem(acumulador,count, 1); // imprime o array com CICLO INFERNAL
            break;}
        else { // caso contrario, adiciona-se o s[i] e continuamos a verificar ate que o ciclo termine ou seja infinito
            acumulador[count] = s[i-1];
            i = s[i-1];
            count++;
        }
    }
}

int main() {

    // numero de casos
    int N;
    assert(scanf("%d", &N) == 1);

    // nº de guiches, guiche inicial
    int I[N], K[N];

    // regista os numeros de cada linha
    int sequencia[N][1001];

    for (int i = 0; i < N; i++){

        assert(scanf("%d %d", &K[i], &I[i]) == 2);

        // regista o identificador do próximo guiché ou 0 se o demónio estiver a despachar clientes
        for (int k = 0; k < K[i]; k++) {
            assert(scanf("%d",&sequencia[i][k]) == 1);
        }
    }

    // verifica para cada linha qual o ciclo
    for (int i = 0; i < N; i++) {
        verificaCiclo(sequencia[i],I[i]);
    }

    return 0;
}
