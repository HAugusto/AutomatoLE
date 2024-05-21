#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <string.h>
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
                Pair* pair = defaultCreator(character, i);
                
                // Insere o par na lista, através de um nó próprio
                pushList(list, pair);
                
                // token[0] = '{' e token[2] = '('
                if(character == tokens[0] || character == tokens[2]){
                    pushList(tempList, defaultCreator(character, i));
                }

                // token[1] = '}' e token[3] = ')'
                if(character == tokens[1] || character == tokens[3]){
                    // Coleta o último dado na lista temporária
                    Node* tempNode = getListNode(list, tempList->end);
                    // printPair(tempPair); // ('{', 4)

                    ((Pair*)tempNode->data)->next = list->end;
                    ((Pair*)list->end->data)->previous = tempNode;
                    // printNode(getListNode(list, ((Pair*)tempNode->data)));
                    // printNode(tempPair->next->previous);
                    // printNode(getListNode(list, getListNode(list, ((Node*)tempPair))));
                    // ((Pair*)list->end->data)->previous = getListNode(list, tempPair);
                    // printNode(tempPair->first);
                    popList(tempList);
                }
            }
        }
    }

    if(tempList->start != NULL && tempList->end != NULL){
        printf("\nA formatação do arquivo de entrada está incorreta...");
        exit(EXIT_FAILURE);
    }

    printList(list, false);
    printNode(getListNode(list, ((Pair*)list->start->next->data)->next->previous));
    // freeList(list);
    
    fclose(file);
    exit(EXIT_SUCCESS);
}