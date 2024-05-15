#include <stdlib.h>
#include <stdio.h>
#include "../headers/pair.h"
#include "../headers/data.h"

Pair* defaultPair(){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    if(pair == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo par");
        return NULL;
    }
    
    pair->first = pair->second = NULL;
    
    return pair;
}

Pair* createPair(struct Data* first, struct Data* second){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    if(pair == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo par");
        return NULL;
    }
    
    pair->first = first;
    pair->second = second;
    
    return pair;
}

struct Data* getFirstData(Pair* pair){
    if(pair->first != NULL) return pair->first;
    else return NULL;
}

struct Data* getSecondData(Pair* pair){
    if(pair->second != NULL) return pair->second;
    else return NULL;
}

// int getIndex(Pair* pair){
//     return pair->index;
// }

void freePair(Pair* pair) {
    if (pair != NULL) {
        free(pair->first);
        free(pair->second);
        free(pair);
    }
}

void printPair(Pair* pair){
    printf("\nFirst: \t\t%s", pair->first);
    printf("\nSecond: \t%s", pair->second);
}