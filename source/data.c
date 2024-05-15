#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../headers/data.h"

Data* defaultData(size_t size, void* data){
    Data* newData = (Data*)malloc(sizeof(Data));

    if(newData == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo dado");
        return NULL;
    }
    
    newData->size = size;
    newData->data = malloc(size);
    memcpy(newData->data, data, size);

    return newData;
}

// Libera a memória com o dado e a estrutura em que foi alocada
void freeData(Data* data){
    free(data->data);
    free(data);
}