#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../headers/data_type.h"
#include "../headers/pair.h"
#include "../headers/data.h"
#include "../headers/node.h"

Pair* defaultPair(){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    if(pair == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo par");
        return NULL;
    }
    
    pair->first = pair->second = NULL;
    pair->previous = pair->next = NULL;
    pair->index = 0;

    return pair;
}

Pair* createPair(Data* first, Data* second){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    if(pair == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo par");
        return NULL;
    }
    
    pair->first = first;
    pair->second = second;
    
    return pair;
}

// Getters
Data* getFirstData(Pair* pair){
    if(pair->first != NULL) return (Data*)pair->first;
    return NULL;
}

Data* getSecondData(Pair* pair){
    if(pair->second != NULL) return (Data*)pair->second;
    return NULL;
}

int getPairIndex(Pair* pair){
    return pair->index;
}

// Setters
Pair* setFirstData(Pair* pair, Data* data){
    if(pair->first != NULL) pair->first = data;
    return pair;
}

Pair* setSecondData(Pair* pair, Data* data){
    if(pair->second != NULL) pair->second = data;
    return pair;
}

void freePair(Pair* pair) {
    if (pair->first != NULL) {
        freeData(pair->first);
        free(pair->first);
        pair->first = NULL;
    }
    
    if (pair->second != NULL) {
        freeData(pair->second);
        free(pair->second);
        pair->second = NULL;
    }

    if (pair->previous != NULL) {
        freeNode(pair->previous);
        free(pair->previous);
        pair->previous = NULL;
    }

    if (pair->next != NULL) {
        freeNode(pair->next);
        free(pair->next);
        pair->next = NULL;
    }
    
    free(pair);
}

void printPair(Pair* pair){
    // Verifica se o par possui um par interno
    if(getFirstData(pair) != NULL){
        printf("(");
        
        // Verifica se o par possui uma instância de Data
        
        if((Data*)((pair->first)) != NULL) printf("'%s'", ((Data*)pair->first)->data);
        else if((Pair*)getFirstData(pair)) printPair((Pair*)getFirstData(pair));
        
        printf(", ");
        printf("%d", *(int*)((Data*)(getSecondData(pair)->data)));

        printf(")");
    }
}