// Problema C - Baixas na Cozinha

#include <stdio.h>
#include <assert.h>
#include <string.h>

// O Funcionario é constituido pela sua alcunha e pela sua assiduidade
struct Funcionario {
        char alcunha[20];
        int assiduidade;
};

int main() {
    // Recebe o numero de dias
    int N;
    assert(scanf("%d", &N) == 1);

    // Limpar buffer do teclado
    getchar();

    // Declaramos funcionario do tipo Funcionario
    struct Funcionario funcionario[40];
    
    // Conta numero de funcionarios que trabalharam naqueles dias
    int contador = 0;

    // Regista os nomes daquele dia
    char linha[1001];

    for (int i = 0; i < N; i++) {
        // Recebe a linha com os alcunhas
        if (fgets(linha,1001,stdin) != NULL) {

            // O *token é inicializado com um nome separado da linha quando encontra um espaço ou um paragrafo
            char *nome = strtok(linha, " \n");
            // Enquanto houve palavra para registar
            while (nome != NULL) {
                int j;
                // Percorre todos os funcionarios
                for (j = 0; j < contador; j++) {
                    // Caso o nome ja seja coincidente com algum adicionado, incrementamos a assiduidade
                    if (strcmp(funcionario[j].alcunha, nome) == 0) {
                        funcionario[j].assiduidade++;
                        break;
                    }
                }

                // Quando o nome nao foi adicionado (j == contador, terminou o ciclo)
                if (j == contador) {
                    // Copiamos a palavra em questao para um novo funcionario
                    strcpy(funcionario[contador].alcunha,nome);
                    // incializamos a sua assiduidade com 1, pois foi trabalhar
                    funcionario[contador].assiduidade = 1;
                    // o numero de funcionarios aumenta
                    contador++;
                }

                // Verifica a palavra seguinte
                nome = strtok(NULL, " \n");
            }
        }
    }

    /* Verificamos qual o menor valor de assiduidade de todos os funcionarios e a sua posiçao.
        Sempre que houver um valor mais pequeno, registamo-lo com a sua respetiva posiçao na struct funcionario
    */
    int minimoAssiduidade = 1000;
    int posicaoAssiduidade = 0;
    for (int i = 0; i < contador; i++) {
        if (minimoAssiduidade > funcionario[i].assiduidade) {
            minimoAssiduidade = funcionario[i].assiduidade;
            posicaoAssiduidade = i;
        }
    }

    // Imprimimos a alcunha do funcionario com menos valor de assiduidade, ou seja, faltou mais
    printf("%s\n", funcionario[posicaoAssiduidade].alcunha);
    
    return 0;
}