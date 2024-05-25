#include <stdlib.h>
#include <stdio.h>

#include "../headers/tokens.h"
#include "../headers/data_type.h"
#include "../headers/data.h"
#include "../headers/list.h"

Pair* StateCreator(FILE* file, char character, int i){
    // Se o caracter for encontrado nos tokens e for o caracter 'q'
    if(character == tokens[4]){
        // Cria uma outra lista temporária
        List* temp = defaultList();

        // Inicializa algumas variáveis temporárias
        size_t value_len = 0;
        char value[5] = {};
        int position = i;

        value[0] = character;
        // Armazena o início de estado 'q' na lista, através de um par
        // Pair* state = createPair(createData(&character, CHAR), createData(&i, INT));

        // Cria um par temporário, para ser utilizado posteriormente
        Pair* pair_state;

        // Coleta o próximo caracter na cadeia de entrada
        character = fgetc(file);

        // Coleta o próximo caracter e faz as devidas comparações, incrementando no contador 'i'
        for(int m = 1; character != ',' && character != tokens[1] && character != tokens[3] && character != EOF; i++, m++){
            // Incrementa 1 na variável 'i', do for principal
            i++;

            // Armazena o caracter atual na variável value, na posição 'm'
            value[m] = character;

            // Armazena o caracter atual no par criado anteriormente
            // pair_state = createPair(createData(&character, CHAR), createData(&i, INT));
            // Pair* tempValue = createPair(createPair(getFirstData(state), createData(getFirstData((Pair*)temp->start->data), CHAR)), getSecondData(state));

            // Adiciona o par contendo o caracter na lista, com sua devida posição
            pushList(temp, pair_state);

            // Coleta o próximo caracter da cadeia de entrada
            character = fgetc(file);
        }

        // Mapeando o tamanho real do vetor
        for(int l = 0; value[l] != '\0'; l++) value_len++;

        // Criando uma variável com base no tamanho real
        char* combined = (char*)malloc((sizeof(value) + 1));

        // Copiando os dados para a variável definitiva
        for(int l = 0; value[l] != '\0'; l++) combined[l] = value[l];

        Pair* state = createPair(createData(combined, STRING), createData(&position, INT));

        return state;
    }
}