#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/node.h"
#include "../headers/pair.h"
#include "../headers/data.h"

Node* defaultNode(){
    Node* node = (Node*)malloc(sizeof(Node));

    if(node == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo nó");
        return NULL;
    }
    
    node->previous = node->next = NULL;
    node->data = NULL;
    node->index = 0;
    
    return node;
}

// Getters
Node* getNodePrevious(Node* node){
    if(node->previous != NULL) return node->previous;
    return NULL;
}

Node* getNodeNext(Node* node){
    if(node->next != NULL) return node->next;
    return NULL;
}


int getNodeIndex(Node* node){
    if(node != NULL) return node->index;
    return 0;
}

void* getNodeData(Node* node){
    if(node->data != NULL) return node->data;
    return NULL;
}

void freeNode(Node* node){
    if(node->previous != NULL){
        freeNode(node->previous);
        node->previous = NULL;
    }

    if(node->next != NULL){
        freeNode(node->next);
        node->next = NULL;
    }
    
    if(node->data != NULL){
        free(node->data);
        node->data = NULL;
    }
    
    free(node);
}

void printNode(Node* node){
    printf("\n\nID:\t\t%d", node->index);
    printf("\nData:\t\t");

    if(getFirstData((Pair*)node->data) != NULL) printf("('%c', %d)", ((Data*)(getFirstData(node->data)->data)), ((Data*)(getSecondData(node->data)->data)));
    else printPair(node->data, false);
    
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