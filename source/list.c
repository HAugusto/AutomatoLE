#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/list.h"
#include "../headers/node.h"
#include "../headers/pair.h"
#include "../headers/data.h"

#define MAX_LENGTH 9999

// Inicializador padrão
List* defaultList(){
    List* list = (List*)malloc(sizeof(List));

    if(list == NULL){
        printf("Erro: não foi possível alocar memória para a criação de uma nova lista");
        return NULL;
    }
    
    list->start = list->end = NULL;
    list->count_nodes = 0;

    return list;
}

Node* pushList(List* list, void* data, DataType type){
    // Verifica se a lista atingiu o limite máximo
    if(list->count_nodes > MAX_LENGTH){
        printf("Erro: não é possível inserir mais itens na lista");
        return NULL;
    }

    // Cria um novo nó alocando a memória necessária através de Node
    Node* node = defaultNode();

    // Atribuição de valores
    node->data = createData(data, type);

    // Verifica se não há um elemento inicial já na lista
    if(list->start == NULL){
        list->start = node;
    } else {
        node->index = getLength(list);
        node->previous = list->end;
        list->end->next = node;
    }

    list->end = node;
    list->count_nodes++;
    
    return node;
}

Node* popList(List* list){
    if(getIsEmpty(list)){
        printf("Erro: a fila está vazia...");
        return NULL;
    }

    if(list->count_nodes > 1){
        list->end = list->end->previous;
        // freePair(list->end->next->data);
        free(list->end->next);
        list->end->next = NULL;
    } else {
        // freePair(list->start->data);
        free(list->start);
        list->start = list->end = NULL;
    }
    
    list->count_nodes--;
    return list->end;
}


// Getters
Node* getStart(List* list){
    return list->start;
}

Node* getEnd(List* list){
    return list->end;
}

Node* getListPosition(List* list, int position){
    if(position < 0 || position > getLength(list)){
        printf("Erro: posição inválida...");
        return NULL;
    }
    
    Node* current = list->start;
    
    for(int i = 0; i < position; i++){
        if(current == NULL) return NULL;
        current = current->next;
    }

    return current;
}

Node* getListNode(List* list, Node* node){
    // Inicializa um nó no início da lista
    Node* current = list->start;

    // Procura o nó correspondente a partir do ponte de referência
    for(current; current->index < getLength(list); current = current->next){
        if((Data*)getFirstData(current->data)->data == (Data*)getFirstData(node->data)->data && (Data*)getSecondData(node->data)->data == (Data*)getSecondData(node->data)->data);
        return current;
    }

    // Se não encontrar um correspondente, retorna nulo
    return NULL;
}

int getLength(List* list){
    // Retorna a variável 'count_nodes'
    return list->count_nodes;
}

bool getIsEmpty(List* list){
    if(list->start == NULL && list->end == NULL) return true;
    return false;
}

void freeList(List* list){
    if(list->start != NULL) {
        Node* node = list->end;
        for(node; list->start != NULL; node->previous){
            freeNode(node);
            printList(list, false);
        }
    }
    
    free(list);
}

void printList(List* list, bool detailed){
    // Verifica se a lista está vazia
    if(getIsEmpty(list)){
        printf("Erro: a lista está vazia...");

        // Se estiver vazia, retorna falha
        exit(EXIT_FAILURE);
    }

    // Verifica se está pedindo para detalhar
    if((void*)detailed == NULL) detailed = false;

    // Cria uma instância de node, passando o início da lista
    Node* node = list->start;

    // Inicia um laço 'for', passando por todos os elementos da lista através dos nós
    for(node; node != NULL && node->next != node; node = node->next){
        // Verifica se o usuário pediu para detalhar, realizando a impressão do nó
        if(detailed == true) printNode(node);

        // Realiza a impressão do Par
        printf("\n\n%d: ", node->index);
        printPair(node->data, detailed);
    }
}