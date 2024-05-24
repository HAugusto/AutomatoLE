#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "../headers/data_type.h"
#include "../headers/data.h"

Data* defaultData(){
    Data* data = (Data*)malloc(sizeof(Data));

    if(data == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo dado");
        return NULL;
    }
    
    data->data = NULL;
    data->type = NONE;
    data->size = 0;

    return data;
}

Data* createData(void* data, DataType type){
    Data* newData = defaultData();
    
    newData->type = type;
    newData->size = getDataTypeSize(type);
    newData->data = malloc(newData->size);

    if(newData->data == NULL || data == NULL){
        printf("Erro: não foi possível alocar o dado na memória");
        freeData(newData);
        return NULL;
    } 

    memcpy(newData->data, data, newData->size);
    if(memcmp(newData->data, data, newData->size) == 0) printf("\nA cópia dos dados foi bem-sucedida...");
    else printf("\nOcorreu uma falha durante a cópia dos dados...");
    
    // printf("\t('%s', %d, %s)", newData->data, newData->size, getDataTypeName(newData->type));
    printData(newData);

    return newData;
}

// Getters
Data* getData(Data* data){
    if(data->data != NULL && data->data != NULL) return data->data;
    return NULL;
}

size_t getSize(Data* data){
    if(data != NULL) return data->size;
    return -1;
}

DataType getType(Data* data){
    if(data != NULL) return data->type;
    return -1;
}

// Função para obter o nome do tipo
void printData(Data* data) {
    printf("\t(");
    switch (data->type) {
        case INT:
            printf("'%d', ", *(int*)data->data);
            break;
        case FLOAT:
            printf("'%f', ", *(float*)data->data);
            break;
        case DOUBLE:
            printf("'%lf', ", *(long int*)data->data);
            break;
        case CHAR:
            printf("'%c', ", *(char*)data->data);
            break;
        case STRING:
            printf("'%s', ", (char*)data->data);
            break;
        case NONE:
            printf("NULL");
            break;
        default:
            printf("UNKNOW");
            break;
    }

    printf("%d, %s)", data->size, getDataTypeName(data->type));
}

// Libera a memória com o dado e a estrutura em que foi alocada
void freeData(Data* data){
    if(data->data != NULL){
        free(data->data);
        data->data = NULL;
    }
    free(data);
}