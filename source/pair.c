#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

Pair* createPair(void* first, void* second){
    Pair* pair = (Pair*)malloc(sizeof(Pair));

    if(pair == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo par");
        return NULL;
    }
    
    pair->first = first;
    pair->second = second;
    
    return pair;
}

Pair* defaultCreator(char data, int position){
    char* x = malloc(sizeof(char));
    int* y = malloc(sizeof(int));
    
    *x = data;
    *y = position;

    Data* data1 = charData(x);
    Data* data2 = intData(y);

    return createPair(x, y);
}

// Getters
Data* getFirstData(Pair* pair){
    if(pair->first != NULL) return pair->first;
    return NULL;
}

Data* getSecondData(Pair* pair){
    if(pair->second != NULL) return pair->second;
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

void printPair(Pair* pair, bool detailed){
    // if(((Pair*)pair->first)->first != NULL) printPair(pair->first, false);

    if(detailed == false){
        printf("('");
        if(((Pair*)pair->first)->first != NULL) printf("%c%c", *(char*)((Pair*)pair->first)->first, *(char*)((Pair*)pair->first)->second);
        else printf("%c", *(char*)pair->first);
        printf("', %d)", *(int*)pair->second);
    }

    // if(detailed == false) printf("('%c', %d)", *(char*)pair->first, *(int*)pair->second);
    else {
        printf("\n\n1: \t\t");
        if(((Pair*)pair->first)->first != NULL) printf("%c%c", *(char*)((Pair*)pair->first)->first, *(char*)((Pair*)pair->first)->second);
        else printf("'%c'", *(char*)pair->first);
        
        printf("\n2: \t\t");
        if(((Pair*)pair->second)->first != NULL) printf("%c%c", *(char*)((Pair*)pair->second)->first, *(char*)((Pair*)pair->second)->second);
        else printf("%d", *(int*)pair->second);
        
        printf("\nNext: \t\t");
        printf("%d", getNodeIndex(pair->next));
        printf("\n============");
    }
}