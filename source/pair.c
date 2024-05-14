#include <stdlib.h>
#include <stdio.h>
#include "../headers/pair.h"

Pair* defaultPair(){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    if(pair == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo par");
        return NULL;
    }
    
    pair->first = pair->second = NULL;
    pair->index = 0;
    
    return pair;
}

Pair* createPair(void* first, void* second){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    pair->first = first;
    pair->second = second;
    
    return pair;
};

void freePair(Pair* pair) {
    if (pair != NULL) {
        free(pair);
    }
}

void printPair(Pair* pair){
    printf("\nIndex: \t%d", pair->index);
    printf("\nFirst: \t%s", pair->first);
    printf("\nSecond: \t%s", pair->second);
}