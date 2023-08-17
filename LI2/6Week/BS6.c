// Problema B - Contratando Cozinheiros

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char alcunha[20];
    int altura;
    int peso;
} funcionario;

/* Criteiros a seguir:
Pesos:
1º - peso 90kg
2º - mais perto dos 90 kg e mais pesados
3º - mais perto dos 90 kg e menos pesados
4º - menos pesados
Caso tenham o mesmo peso:
- mais altos
Caso tenham o mesmo peso e a mesma altura:
- ordem alfabetica

Funçao criteirios:
A funçao recebe dois ponteiros genericos que apontam para 2 elementos
da lista que irao ser comparados. Nao conhecemos o tipo portanto os ponteiros sao declarados como void*.

A funçao devolve 0 se os funcionarios forem iguais.
Devolve um valor positivo se o p1 funcionario for maior que o p2. (logo p2 vem primeiro)
Devolve um valor negativo se o p1 for menor que o p2. (logo p1 vem primeiro)
*/

int criterios (const void *p1, const void *p2) {

    /*convertemos os ponteiros para ponteiros do tipo funcionario
    (pois é o tipo dos elementos da lista que estamos a ordenar)*/
    funcionario *f1 = (funcionario *) p1;
    funcionario *f2 = (funcionario *) p2;

    // designamos os pesos, alturas e alcunhas com algo mais simples
    int peso1 = f1->peso;
    int peso2 = f2->peso;
    int altura1 = f1->altura;
    int altura2 = f2->altura;
    char *alcunha1 = f1->alcunha;
    char *alcunha2 = f2->alcunha;

    // se os pesos forem iguais, comparamos as alturas
    if (peso1 == peso2) {
        // se as alturas forem iguais comparamos as alcunhas
        if (altura1 == altura2)
            // 0 se forem iguais, > 0 se a alcunha1 > alcunha2 em termos lexicais (1º p2), < 0 caso contrario (1º p1)
            return strcmp(alcunha1, alcunha2);
        // se as alturas forem diferentes, > 0 se a altura2 for maior, < 0 caso contrario
        else return altura2 - altura1;
    }
    // se o p1 tiver o peso ideal, este vem primeiro
    else if (peso1 == 90) return -1;
    // se o p2 tiver o peso ideal, vem primeiro
    else if (peso2 == 90) return 1;
    else {
        // se a distancia ao peso ideal (90kg) for diferente
        if (abs(90-peso1) != abs(90-peso2))
            // devolvemos > 0 se o p1 tiver mais diferença (1º p2) ou < 0 caso contrario (1º p1)
            return abs(90-peso1) - abs(90-peso2);
            // se a distancia ao peso ideal for igual e as alturas tambem
        else if (altura1 == altura2)
        // 0 se forem iguais, > 0 se a alcunha1 > alcunha2 em termos lexicais (1º p2), < 0 caso contrario (1º p1)
            return strcmp(alcunha1, alcunha2);
        // devolvemos >0 se a altura2 for maior (1º p2) e <0 caso contrario (1º p1)
        else return altura2 - altura1;
    }
}

int main() {

    // numero de cozinheiros
    int N;
    assert(scanf("%d", &N) == 1);

    // iremos ter N-funcionarios
    funcionario f[N];

    // regista a alcunha de cada funcionario, bem como o seu peso e altura
    for (int i = 0; i < N; i++) {
        assert(scanf("%s %d %d", f[i].alcunha, &f[i].peso, &f[i].altura) == 3);
    }

    /* Ordenamos os funcionarios seguindo os diversos criterios.
    Se a funçao criterios devolver um valor == 0, entao os elementos sao iguais.
    Se devolver um valor <0, significa que o primeiro elemento deve ser ordenado antes do segundo elemento.
    Caso contrario (valor>0), o segundo elemento deve ser ordenado antes do primeiro elemento.*/
    qsort (f, N, sizeof(funcionario), criterios);

    // imprimimos os funcionarios ja ordenados
    for (int i = 0; i < N; i++) {
        printf("%s %d %d\n", f[i].alcunha, f[i].peso, f[i].altura);
    }

    return 0;
}
