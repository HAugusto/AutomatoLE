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
    if(list->count_nodes < MAX_LENGTH){
        // Cria um novo nó alocando a memória necessária através de Node
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        // Atribuição de valores
        newNode->data = data;

        // Verifica se não há um elemento inicial na lista
        if(list->start == NULL){
            list->start = list->end = newNode;
            newNode->previous = newNode;
        }
        if(list->end != NULL) {
            newNode->index = getListLength(list) + 1;
            newNode->previous = list->end;
            newNode->next = newNode;
            list->end->next = newNode;
        }

        list->end = newNode;
        list->count_nodes++;
    } else {
        printf("Erro: não é possível inserir mais itens na fila");
        return NULL;
    }

    return list;
}

Node* popList(List* list){
    if(isEmpyt(list)){
        printf("Erro: a fila está vazia...");
        return NULL;
    }

    Node* node = node->next;
    list->start = node;
    list->count_nodes--;

    return node;  
}

// Getters
Node* getStart(const List* list){
    return list->start;
}

Node* getEnd(const List* list){
    return list->end;
}

Node* getPosition(const List* list, int position){
    if(position < 0 || position > getLength(list)){
        return NULL;
    }
    
    Node* current = list->start;
    for(int i = 0; i < position; i++){
        if(current == NULL) return NULL;
        current = current->next;
    }

    return current;
}

int getLength(const List* list){
    return list->count_nodes;
}

bool getIsEmpty(List* list){
    return (list->start == NULL);
}

