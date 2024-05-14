#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "pair.h"

/*
    Função: readfile
    Função destinada a abrir, tratar exceções e realizar a leitura de um arquivo,
    retornando caractere por caractere, individualmente    
*/

typedef enum {
    false, true
} bool;

// Inicializa uma cadeia de caracteres definidos como 'tokens' no sistema
const char tokens[] = {'M', ' ', '=', '{', '}', '(', ')'};

int *readfile(char *filename){
    // Define a linguagem do sistema para Português, permitindo acentuações
    setlocale(LC_ALL, ("Portuguese"));
    
    // Cria uma instância de FILE
    FILE *file;

    // Abre o arquivo com a função de leitura
    file = fopen(filename, "r");

    // Inicialização de variavéis
    char character;
    int checker_tokens = 0, count_tokens = 0;
    
    // Verifica se o arquivo indicado é uma entrada válida
    if(file == NULL){
        printf("Nenhum arquivo válido encontrado...\n");
        exit(EXIT_FAILURE);
    }
    
    // Inicializa um loop 'while' percorrendo toda a cadeia de entrada do usuário, enquanto não for nulo
    // Através da variável character, coleta o dado da posição em que se encontra
    while((character = fgetc(file)) != EOF) {
        bool checker = true;
        
        // Inicializa um loop 'for' percorrendo o vetor tokens, com a finalidade de identificar com caracteres comuns
        for(int i = 0; i < (sizeof(tokens)/sizeof(tokens[0])); i++){
            // Se o caracter for encontrado nos tokens, então realiza a verificação se ele se trata de um '{' ou '}', para controle
            if(character == tokens[i]){
                if(character == tokens[3]){
                    // Cria par(valor, posição)
                    count_tokens++;
                    checker_tokens++;
                    checker != checker;
                } else if(character == tokens[4]){
                    checker_tokens--;
                    checker != checker;
                }
            }
        }

        if(checker && checker == 0){
            printf("%c", character);
        } else {
            printf("");
        }
    }

    fclose(file);
    exit(EXIT_SUCCESS);
}