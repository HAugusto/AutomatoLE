#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/list.h"
#include "../headers/node.h"

#define MAX_LENGTH 5

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

Node* pushList(List* list, void* data){
    // Verifica se a lista atingiu o limite máximo
    if(list->count_nodes > MAX_LENGTH){
        printf("Erro: não é possível inserir mais itens na lista");
        return NULL;
    }

    // Cria um novo nó alocando a memória necessária através de Node
    Node* node = defaultNode();

    // Atribuição de valores
    node->data = data;

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

    Node* node = node->next;
    
    list->start = node;
    list->count_nodes--;
    
    return node;
}


// Getters
Node* getStart(List* list){
    return list->start;
}

Node* getEnd(List* list){
    return list->end;
}

Node* getPosition(List* list, int position){
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

int getLength(List* list){
    return list->count_nodes;
}

bool getIsEmpty(List* list){
    return (list->start == NULL);
}

void printList(List* list){
    Node* node = list->start;
    for(node; node != NULL && node->next != node; node = node->next) printNode(node);
}