#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/node.h"
#include "../headers/pair.h"
#include "../headers/data.h"

Node* defaultNode(){
    // Construtor padrão de node
    Node* node = (Node*)malloc(sizeof(Node));

    // Verifica se node não é nulo, confirmando que deu certo sua instanciação
    if(node == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo nó");
        
        // Retorna nulo em caso de falha
        return NULL;
    }
    
    // Atribuição padrão de valores
    node->previous = node->next = NULL;
    node->data = NULL;
    node->index = 0;
    
    // Retorna o nó criado
    return node;
}

Node* createNode(void* data, DataType type){
    // Chama o construtor padrão
    Node* node = defaultNode();
    
    // Realiza o tratamento e instanciação dos dados pelo tipo 'Data'
    node->data = createData(data, type);
    
    // Retorna o nó criado
    return node;
}

// Getters
// Retorna o nó anterior do nó referenciado, se ele não for nulo
Node* getNodePrevious(Node* node){
    if(node->previous != NULL) return node->previous;

    // Retorna nulo em caso de falha
    return NULL;
}

// Retorna o nó posterior do nó referenciado, se ele não for nulo
Node* getNodeNext(Node* node){
    if(node->next != NULL) return node->next;
    
    // Retorna nulo em caso de falha
    return NULL;
}

// Retorna o índice do nó referenciado, se ele não for nulo
int getNodeIndex(Node* node){
    if(node != NULL) return node->index;
    
    // Retorna '0' em caso de falha
    return 0;
}

// Retorna a variável 'data', se ele não for nulo
Data* getNodeData(Node* node){
    if(node->data != NULL) return node->data;
    
    // Retorna nulo em caso de falha
    return NULL;
}

// Libera a memória associado a instância do 'node' criado
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
    
    // Libera a memória
    free(node);
}

void printNode(Node* node){
    printf("\n\nID:\t\t%d", node->index);
    printf("\nData:\t\t");

    

    // if(getFirstData((Pair*)node->data) != NULL) printf("('%c', %d)", ((Data*)(getFirstData(node->data)->data)), ((Data*)(getSecondData(node->data)->data)));
    // else printPair(node->data, false);
    
    // printf("\nPrevious:\t");
    // if(node->previous){
    //     printf("%d", node->previous->index);
    // } else {
    //     printf("%s", node->previous);
    // }

    // printf("\nNext:\t\t");
    // if(node->next){
    //     printf("%d", node->next->index);
    // } else {
    //     printf("%s", node->next);
    // }
}