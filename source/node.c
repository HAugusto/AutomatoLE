#include <stdlib.h>
#include <stdio.h>
#include "../headers/node.h"

Node* defaultNode(){
    Node* node = (Node*)malloc(sizeof(Node));

    if(node == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo nó");
        return NULL;
    }
    
    node->previous = node->next = NULL;
    node->data = NULL;
    node->index = 0;

    // node->getIndex = getIndex;
    
    return node;
}

void printNode(Node* node){
    printf("\nID:\t\t%d", node->index);
    printf("\nData:\t\t%s", node->data);
    
    printf("\nPrevious:\t");
    if(node->previous != NULL && node->previous->index != node->index){
        printf("%d", node->previous->index);
    } else {
        printf("%d (HIMSELF)", node->previous->index);
    }

    printf("\nNext:\t\t");
    if(node->next != NULL && node->next->index != node->index){
        printf("%d", node->next->index);
    } else {
        printf("%d (HIMSELF)", node->next->index);
    }
}

// Getters
int getIndex(Node* node){
    return node->index;
}

void* getData(Node* node){
    return node->data;
}

void* getPrevious(Node* node){
    return node->previous;
}

void* getNext(Node* node){
    return node->next;
}
