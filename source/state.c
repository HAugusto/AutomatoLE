#include <stdlib.h>
#include <stdio.h>
#include "../headers/state.h"
#include "../headers/tokens.h"
#include "../headers/list.h"
#include "../headers/data.h"

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

State* defaultStateCreator(void* data, int start_position){
    State* state = defaultState();
    
    if(state != NULL && data != NULL){
        state->data = data;
        state->start_position = start_position;
        return state;
    }

    return NULL;
}

State* createState(FILE* file, char character, int i){
    // Inicializa algumas variáveis temporárias
    size_t value_len = 0;
    char value[5] = {};
    int start_position = i;

    // Armazena o início de estado 'q' na lista, através de um par
    value[0] = character;

    // Coleta o próximo caracter na cadeia de entrada
    character = fgetc(file);

    // Coleta o próximo caracter e faz as devidas comparações, incrementando no contador 'i'
    for(int m = 1; character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++, m++){            
        // Armazena o caracter atual na variável value, na posição 'm'
        value[m] = character;

        // Coleta o próximo caracter da cadeia de entrada
        character = fgetc(file);
    }

    // Mapeando o tamanho real do vetor
    for(int l = 0; value[l] != '\0'; l++) value_len++;

    // Criando uma variável com base no tamanho real
    char* combined = (char*)malloc((value_len + 1) * sizeof(char));

    // Copiando os dados para a variável definitiva
    for(int l = 0; value[l] != '\0'; l++) combined[l] = value[l];
    combined[value_len] = '\0';

    State* state = defaultStateCreator(createPair(createData(combined, STRING), createData(start_position, INT)), createData(i, INT));
    if(state->data != NULL) return state;
    
    return NULL;
}