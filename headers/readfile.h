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
const char tokens[] = {'{', '}', '(', ')', 'q', '='};
const char ignore[] = {' '};

List* readfile(char *filename){
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
    List* tempList2 = defaultList();

    // Inicializa um loop 'while' percorrendo toda a cadeia de entrada do usuário, enquanto não for nulo
    // Através da variável character, coleta o dado da posição em que se encontra
    for(int i = 0; (character = fgetc(file)) != EOF; i++) {
        start:
        // Inicializa um loop 'for' percorrendo o vetor tokens, com a finalidade de identificar com caracteres comuns
        // Se o caracter for encontrado nos tokens, então realiza a verificação se ele se trata de um '{' ou '}', para controle
        if(character == tokens[0] || character == tokens[1] || character == tokens[2] || character == tokens[3]){
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

                // Retira o item da lista temporária
                popList(tempList);
            }
        } else if(character == tokens[4]){
            List* temp = defaultList();
            // Armazena o início de estado na lista
            Pair* state = defaultCreator(character, i);
            Pair* pair_state;

            // Coleta o próximo caracter e faz as devidas comparações, incrementando no contador 'i'
            for(character = fgetc(file); character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++){
                i++;

                // Armazena o caracter
                pair_state = defaultCreator(character, i);
                // printf("%c", state->first);
                // Adiciona o caracter na lista, com sua posição
                pushList(temp, pair_state);

                // Coleta o próximo caracter da cadeia de entrada
                character = fgetc(file);
            }
            
            // Verifica se as variáveis não são nulas
            if(temp->start->data == NULL){
                fprintf(stderr, "Erro ao alocar a memória\n");
                return NULL;
            }

            // Realiza a cópia do valor
            Pair* tempValue = createPair(createPair(state->first, ((Pair*)temp->start->data)->first), state->second);
            // printf("%c%c", *(char*)tempValue->first, *(char*)((Pair*)temp->start->data)->first);
            // strcpy(tempValue->first, character);
            // strcpy(tempValue->second, (char*)((Pair*)temp->start->data)->first);
            printf("(%c%c, %d)", *(char*)((Pair*)tempValue->first)->first, *(char*)((Pair*)tempValue->first)->second, *(int*)tempValue->second);
            pushList(tempList2, tempValue);

            // Limpa a lista
            for(int k = 0; k < getLength(temp); k++) popList(temp);
            free(temp);

            // pushList(tempList2, createPair(tempValue, *(int*)state->second));
            // printList(tempList2, false);

            // if(state != NULL) free(state);
            if(pair_state != NULL) free(pair_state);

            goto start;

            // for(i; character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++){         
            //     printf("%c", character);
            //     character = fgetc(file);
            //     printf("\nI: %d", i);
                
            //     // Insere o caracter na lista
            //     // pushList(tempList2, pair);

            //     // if(pair != ',') i++;

            //     // Pair* pair2 = createPair(nextCharacter, i);
                
            //     // Pair* pair = createPair(str, &nextCharacter);

            //     // printf("(%c%c)", ((char*)pair->first)[0], ((char*)pair->first)[1]);
            //     // pushList(tempList, pair);            
            //     // // Insere o par na lista, através de um nó próprio
            //     // pushList(list, pair);
            // }
        }
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
    printList(tempList, false);

    // Fecha o arquivo
    fclose(file);
    
    return list;
    exit(EXIT_SUCCESS);
}