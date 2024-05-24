#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <string.h>

#include "../headers/tokens.h"
#include "../headers/data_type.h"
#include "../headers/data.h"
#include "../headers/pair.h"
#include "../headers/node.h"
#include "../headers/list.h"
#include "../headers/state.h"

#include "state_creator.c"

#include "clearBuffer.c"
#include "readfile_function.c"

/*
    Função: readfile
    Função destinada a abrir, tratar exceções e realizar a leitura de um arquivo,
    retornando caractere por caractere, individualmente    
*/

List* readfile(char *filename){
    FILE* file = readfileFunction(filename);

    // Inicialização de variavéis
    char character;
    int checker_tokens = 0, count_tokens = 0;
    
    // Verifica se o arquivo indicado é uma entrada válida
    if(file == NULL){
        printf("Nenhum arquivo válido encontrado...\n");
        exit(EXIT_FAILURE);
    }

    // Cria as listas iniciais
    List* list = defaultList();
    List* tempList = defaultList();
    List* tempList2 = defaultList();

    // Inicializa um loop 'for' percorrendo toda a cadeia de entrada do usuário, enquanto não for nulo
    // Através da variável character, coleta o dado da posição em que se encontra
    for(int i = 0; (character = fgetc(file)) != EOF; i++) {
        start:

        // Inicializa um loop 'for' percorrendo o vetor tokens, com a finalidade de identificar com caracteres comuns
        // Se o caracter for encontrado nos tokens, então realiza a verificação se ele se trata de um '{' ou '}', para controle
        if(character == tokens[0] || character == tokens[1] || character == tokens[2] || character == tokens[3] || character == tokens[5]){
            // Cria um par inicial para armazenar o caracter com sua devida posição, inserindo-o na lista
            Data* data1 = createData(&character, CHAR);
            Data* data2 = createData(&i, INT);

            Pair* pair = createPair(data1, data2);

            pushList(list, pair);
            
            // token[0] = '{' e token[2] = '('
            if(character == tokens[0] || character == tokens[2]) pushList(tempList, createPair(createData(&character, CHAR), createData(&i, INT)));
            
            // token[1] = '}' e token[3] = ')'11
            if(character == tokens[1] || character == tokens[3]){
                // Coleta o último dado na lista temporária
                Node* tempNode = getListNode(list, tempList->end);

                // Indica o caracter inicial do elemento atual
                ((Pair*)tempNode->data)->next = list->end;
                ((Pair*)list->end->data)->previous = tempNode;

                // Retira o item da lista temporária
                popList(tempList);
            }
        }      
        
        // Se o caracter for encontrado nos tokens e for o caracter 'q'
        State* state = defaultState();
        Pair* pair = defaultPair();
        
        if(character == tokens[4]){
            pair = StateCreator(file, character, i);
            i = *(int*)((Data*)pair->second)->data;
            printf("%d", i);
        }

        // Data* state = createData(createPair(createData(combined, STRING), createData(&start_position, INT)), STATE);
        // printf("Aqui: %c", ((Data*)state->data)->data);
    }

    // Libera memória da lista temporária
    freeList(tempList);
    
    // Verifica se o arquivo está na formatação correta através da lista temporária
    if(tempList->start != NULL && tempList->end != NULL){
        printf("\nA formatação do arquivo de entrada está incorreta...");
        exit(EXIT_FAILURE);
    }

    // printNode(getListPosition(list, 5));
    // printNode(getListNode(list, ((Pair*)getListPosition(list, 5)->data)->next));
    printList(list, false);

    // classifier(list);
    
    // Fecha o arquivo
    fclose(file);
    
    return list;
    exit(EXIT_SUCCESS);
}