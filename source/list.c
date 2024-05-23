#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/list.h"
#include "../headers/node.h"
#include "../headers/pair.h"

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
    Node* current = list->start;
    for(current; current->index < getLength(list); current = current->next) if(*(char*)((Pair*)current->data)->first == *(char*)((Pair*)node->data)->first && *(int*)((Pair*)current->data)->second == *(int*)((Pair*)node->data)->second) return current;
    return NULL;
}

int getLength(List* list){
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
    if(getIsEmpty(list)){
        printf("Erro: a lista está vazia...");
        exit(EXIT_FAILURE);
    }

    if((void*)detailed == NULL) detailed = false;

    Node* node = list->start;
    for(node; node != NULL && node->next != node; node = node->next){
        if(detailed == true) printNode(node);
        printf("\n%d: ", node->index);
        printPair(node->data, detailed);
    }
}