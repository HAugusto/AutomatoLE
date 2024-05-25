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
            // Cria uma outra lista temporárias
            List* temp = defaultList();

            // Inicializa algumas variáveis temporárias
            size_t value_len = 0;
            char value[5] = {};
            int position = i;

            value[0] = character;
            // Armazena o início de estado 'q' na lista, através de um par
            // Pair* state = createPair(createData(&character, CHAR), createData(&i, INT));

            // Cria um par temporário, para ser utilizado posteriormente
            Pair* pair_state;

            // Coleta o próximo caracter na cadeia de entrada
            character = fgetc(file);

            // Coleta o próximo caracter e faz as devidas comparações, incrementando no contador 'i'
            for(int m = 1; character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++, m++){
                // Incrementa 1 na variável 'i', do for principal
                i++;

                // Armazena o caracter atual na variável value, na posição 'm'
                value[m] = character;

                // Armazena o caracter atual no par criado anteriormente
                // pair_state = createPair(createData(&character, CHAR), createData(&i, INT));
                // Pair* tempValue = createPair(createPair(getFirstData(state), createData(getFirstData((Pair*)temp->start->data), CHAR)), getSecondData(state));

                // Adiciona o par contendo o caracter na lista, com sua devida posição
                pushList(temp, pair_state);

                // Coleta o próximo caracter da cadeia de entrada
                character = fgetc(file);
            }

            // Mapeando o tamanho real do vetor
            for(int l = 0; value[l] != '\0'; l++) value_len++;

            // Criando uma variável com base no tamanho real
            char* combined = (char*)malloc((sizeof(value) + 1));

            // Copiando os dados para a variável definitiva
            for(int l = 0; value[l] != '\0'; l++) combined[l] = value[l];

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