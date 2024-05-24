#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <string.h>
#include "../headers/list.h"
#include "../headers/pair.h"
#include "../headers/node.h"
#include "../headers/data.h"
#include "clearBuffer.c"
#include "classifier.c"

/*
    Função: readfile
    Função destinada a abrir, tratar exceções e realizar a leitura de um arquivo,
    retornando caractere por caractere, individualmente    
*/

// Inicializa uma cadeia de caracteres definidos como 'tokens' no sistema
const char tokens[] = {'{', '}', '(', ')', 'q', '='};
const char ignore[] = {' ', ','};

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
            Pair* pair = createPair(&character, &i);
            
            // Insere o par na lista, através de um nó próprio
            pushList(list, pair);
            
            // token[0] = '{' e token[2] = '('
            if(character == tokens[0] || character == tokens[2]){
                pushList(tempList, createPair(&character, &i));
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

            size_t value_len = 0;
            char value[5] = {};
            value[0] = character;

            // Armazena o início de estado na lista
            Pair* state = createPair(&character, &i);
            Pair* pair_state;

            int m;
            // Coleta o próximo caracter e faz as devidas comparações, incrementando no contador 'i'
            for(character = fgetc(file), m = 1; character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++, m++){
                i++;

                // Armazena o caracter
                pair_state = createPair(&character, &i);
                value[m] = character;
                printf("\nPAR > %c\n", ((char*)pair_state->first)[0]);

                // printf("%c", state->first);

                // Adiciona o caracter na lista, com sua posição
                pushList(temp, pair_state);

                // Coleta o próximo caracter da cadeia de entrada
                character = fgetc(file);
            }

            // Mapeando o tamanho real do vetor
            for(int l = 0; value[l] != '\0'; l++) value_len++;

            // Criando uma variável com base no tamanho real
            char* combined = (char*)malloc((sizeof(strlen(value) + 1)));

            // Copiando os dados para a variável definitiva
            for(int l = 0; value[l] != '\0'; l++) combined[l] = value[l];
            // for(int l = 0; combined[l] != NULL; l++) printf("%s", combined);
            
            // Verifica se as variáveis não são nulas
            if(temp->start->data == NULL){
                fprintf(stderr, "Erro ao alocar a memória\n");
                return NULL;
            }

            // Realiza a cópia do valor
            Pair* tempValue = createPair(createPair(state->first, ((Pair*)temp->start->data)->first), state->second);

            printf("ESTOU AQUI > ('%c', %d)\n", ((char*)((Pair*)tempValue->first)->first)[0], ((int*)tempValue->second)[0]);

            // Limpa a lista
            for(int k = 0; k < getLength(temp); k++) popList(temp);
            
            if(character == ','){
                while(character != EOF){
                    // Coleta o próximo caracter da cadeia de entrada
                    i++;
                    character = fgetc(file);

                    if(character == tokens[1] || character == tokens[3] || character == tokens[4]) goto start;

                    // Coleta o elemento de transição
                    if(character != ' '){
                        printf("\nChar:%c, %d", character, i);
                    }
                    Data* data = defaultData(combined, 4);
                    Pair* pair = createPair(data, &character);
                    pushList(list, createPair(pair, &i));
                }

                // for(character; character != tokens[1] && character != tokens[3] && character != EOF; i++){
                //     if(character != " " || character != tokens[4]){
                //         // Coleta o próximo caracter da cadeia de entrada
                //         // dataPair = createPair(character, i);
                //         character = fgetc(file);
                //         printf("\nChar:%c, %d", character, i);
                //     }
                // }
            }

            free(temp);

            if(state != NULL) free(state);
            if(pair_state != NULL) free(pair_state);

            goto start;
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
    // printList(list, false);
    // printf("%s%c", ((Pair*)tempList2->start->data)->first, ((Pair*)tempList2->start->data)->second);

    // classifier(list);
    
    // Fecha o arquivo
    fclose(file);
    
    return list;
    exit(EXIT_SUCCESS);
}