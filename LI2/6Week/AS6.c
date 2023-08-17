// Problema A - Anagramas

#include <stdio.h>
#include <assert.h>

/* verifica: confirma se a string a é um anagrama da string p
Ideia: contar quantas vezes uma letra se repete em ambas strings
Sempre que aparece em _a_ incrementamos, sempre que aparece em _p_ decrementamos
De modo que, sempre que o valor for diferente de 0,
significa que nao aparece a mesma quantidade de vezes em _a_ e _p_.
*/
int verifica(char a[], char p[]) {
    int contaLetras[1000] = {0};

    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == ' ') continue;
        else contaLetras[a[i] - '0']++;
    }

    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] == ' ') continue;
        else contaLetras[p[i] - '0']--;
    }

    for (int i = 0; i < 1000; i++) {
        if (contaLetras[i] != 0) return -1;
    }
    return 1;
}

// Indica o maximo de um array de inteiros
int maximo(int a[], int n) {
    int maximo = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maximo) maximo = a[i];
    }
    return maximo;
}

// retira os valores -1, pois estes nao serao imprimidos
int retiraMenos1 (int a[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            a[j++] = a[i];
        }
    }
    return j;
}

// imprime as linhas que correspondem a um anagrama
void imprimeLinha (int a[], int n) {
    for (int j = 0; j < n; j++) {
        if (j < (n-1)) printf("%d ", a[j]);
        else printf("%d\n",a[j]);
    }
}

int main () {

    // nº de casos
    int N;
    assert(scanf("%d",&N) == 1);

    // nome do vilao
    char palavra[101], anagrama[101];

    // nº de possiveis candidatos para cada palavra, guarda se cada linha é um anagrama
    int K[N],guarda[N][101];

    for (int i = 0; i < N; i++) {

        assert(scanf("%d", &K[i]) == 1);
        getchar();
        
        if (fgets(palavra,sizeof(palavra),stdin) != NULL){
            for (int j = 0; j < K[i]; j++) {
                if (fgets(anagrama,sizeof(anagrama),stdin) != NULL){
                    if (verifica(anagrama, palavra) == -1) guarda[i][j] = -1;
                    // para determinar a linha
                    else guarda[i][j] = j*verifica(anagrama, palavra) + 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        // se o valor maximo da linha for -1, retorna apenas -1, porque nao foi encontrado nenhum anagrama
        if (maximo(guarda[i],K[i]) == -1) printf("-1\n");
        else {
            // imprimimos as linhas que sao anagramas
            int n = retiraMenos1(guarda[i], K[i]);
            imprimeLinha(guarda[i], n);
        }
    }

    return 0;
}