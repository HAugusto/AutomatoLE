#include <stdlib.h>
#include <stdio.h>
#include "../headers/tokens.h"
#include "../headers/list.h"
#include "../headers/data.h"
#include "../headers/state.h"

Data* StateCreator(FILE* file, char character, int i){
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

    State* state = createState(createData(createPair(createData(combined, STRING), createData(&start_position, INT)), STATE), i);
    if(state->data != NULL) return state;
    
    return NULL;
}