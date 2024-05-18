#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "list.h"
#include "pair.h"
#include "node.h"
#include "../functions/clearBuffer.c"

/*
    Função: readfile
    Função destinada a abrir, tratar exceções e realizar a leitura de um arquivo,
    retornando caractere por caractere, individualmente    
*/

// Inicializa uma cadeia de caracteres definidos como 'tokens' no sistema
const char tokens[] = {'{', '}', '(', ')'};

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

    List* list = defaultList();
    List* tempList = defaultList();

    // Inicializa um loop 'while' percorrendo toda a cadeia de entrada do usuário, enquanto não for nulo
    // Através da variável character, coleta o dado da posição em que se encontra
    for(int i = 0;(character = fgetc(file)) != EOF; i++) {
        // Inicializa um loop 'for' percorrendo o vetor tokens, com a finalidade de identificar com caracteres comuns
        for(int j = 0; j < (sizeof(tokens)/sizeof(tokens[0])); j++){
            // Se o caracter for encontrado nos tokens, então realiza a verificação se ele se trata de um '{' ou '}', para controle
            if(character == tokens[j]){
                pushList(list, defaultCreator(character, i));

                if(character == tokens[0] || character == tokens[2]) pushList(tempList, defaultCreator(character, i));
                if(character == tokens[1] || character == tokens[3]) popList(tempList);
            }
        }
    }

    if(tempList->start != NULL && tempList->end != NULL){
        printf("\nA formatação do arquivo de entrada está incorreta...");
        exit(EXIT_FAILURE);
    }
    printList(list, false);
    // freeList(list);
    
    fclose(file);
    exit(EXIT_SUCCESS);
}