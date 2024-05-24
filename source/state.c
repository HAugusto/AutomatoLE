#include <stdlib.h>
#include <stdio.h>

#include "../headers/tokens.h"
#include "../headers/data.h"
#include "../headers/list.h"
#include "../headers/state.h"

State* defaultState(){
    State* state = (State*)malloc(sizeof(State));

    if(state == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo dado");
        return NULL;
    }
    
    state->data = NULL;
    state->start_position = 0;

    return state;
}

State* createState(void* data, int position){
    State* state = defaultState();

    if(state == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo dado");
        return NULL;
    }

    state->data = data;
    state->start_position = position;
    
    return state;
}