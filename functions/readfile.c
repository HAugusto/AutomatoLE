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
            Data* data = createPair(createData(&character, CHAR), createData(&i, INT));

            pushList(list, data);
            
            // token[0] = '{' e token[2] = '('
            if(character == tokens[0] || character == tokens[2]) pushList(tempList, data);
            
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
        
        if(character == tokens[4]){
            List* temp = defaultList(); // Cria uma lista temporária usando a função defaultList()

            size_t value_len = 0; // Inicializa a variável value_len para armazenar o comprimento do valor
            char value[5] = {}; // Declara um array de caracteres value com tamanho 5 e o inicializa com zeros
            value[0] = character; // Define o primeiro caractere de value como o caractere atual
            int pos = i; // Armazena a posição atual em pos

            Pair* pair_state = defaultPair(); // Cria um par default usando a função defaultPair()

            int m;
            // Coleta o próximo caractere e faz as devidas comparações, incrementando no contador 'i'
            for(character = fgetc(file), m = 1; character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++, m++){
                i++;

                // Armazena o caractere
                pair_state = createPair(createData(&character, CHAR), createData(&i, INT)); // Cria um par com o caractere e sua posição
                value[m] = character; // Armazena o caractere no array value

                // Adiciona o caractere na lista, com sua posição
                pushList(temp, pair_state); // Adiciona o par na lista temp

                // Coleta o próximo caractere da cadeia de entrada
                character = fgetc(file); // Lê o próximo caractere do arquivo
            }

            // Mapeando o tamanho real do vetor
            for(int l = 0; value[l] != '\0'; l++) value_len++; // Calcula o comprimento real de value

            // Criando uma variável com base no tamanho real
            char* combined = (char*)malloc((value_len + 1) * sizeof(char)); // Aloca memória para a string combined

            // Copiando os dados para a variável definitiva
            for(int l = 0; value[l] != '\0'; l++) combined[l] = value[l]; // Copia os caracteres de value para combined
            
            // Verifica se as variáveis não são nulas
            if(temp->start->data == NULL){ // Verifica se o primeiro dado da lista temp é NULL
                fprintf(stderr, "Erro ao alocar a memória\n"); // Imprime uma mensagem de erro
                return NULL; // Retorna NULL
            }

            Data* newCombined = createData(&combined, STRING); // Cria um novo dado do tipo STRING com a string combined

            // Realiza a cópia do valor
            Pair* tempValue = createPair(newCombined, createData(&pos, INT)); // Cria um par com newCombined e a posição
            (char*)(((Data*)tempValue->first->data)->data);

            pushList(list, createPair(newCombined, createData(&pos, INT)));
            
            // Limpa a lista
            for(int k = 0; k < getListLength(temp); k++) popList(temp); // Remove todos os elementos da lista temp

            if(character == ','){ // Verifica se o caractere atual é uma vírgula
                while(character != EOF){ // Continua enquanto não chegar ao final do arquivo
                    // Coleta o próximo caractere da cadeia de entrada
                    i++;
                    character = fgetc(file); // Lê o próximo caractere do arquivo

                    if(character == tokens[1] || character == tokens[3] || character == tokens[4]) goto start; // Se o caractere for um dos tokens específicos, vai para o label start

                    // Coleta o elemento de transição
                    if(character != ' '){
                        printf("\nChar:%c, %d", character, i); // Imprime o caractere e sua posição
                    }

                    Data* data = createData(&combined, STRING); // Cria um dado do tipo STRING com a string combined
                    Pair* pair = createPair(data, createData(&character, CHAR)); // Cria um par com data e o caractere
                    pushList(list, createPair(pair, createData(&i, INT))); // Adiciona o par na lista list
                }
            }
            // Libera a memória alocada
            free(temp);
            
            // Retorna ao ponto de início
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
    
    // Imprime os elementos da lista
    printList(list);
    
    // Fecha o arquivo
    fclose(file);
     
    return list;
    exit(EXIT_SUCCESS);
}