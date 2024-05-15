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

// Getters
Node* getPrevious(Node* node){
    return node->previous;
}

Node* getNext(Node* node){
    return node->next;
}

Data* getData(Node* node){
    return node->data;
}

int getIndex(Node* node){
    return node->index;
}

void printNode(Node* node){
    printf("\nID:\t\t%d", node->index);
    printf("\nData:\t\t%s", node->data);
    
    printf("\nPrevious:\t");
    if(node->previous){
        printf("%d", node->previous->index);
    } else {
        printf("%s", node->previous);
    }

    printf("\nNext:\t\t");
    if(node->next){
        printf("%d", node->next->index);
    } else {
        printf("%s", node->next);
    }
}