#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../headers/data.h"
#include "../headers/data_type.h"

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
    Data* newData = (Data*)malloc(sizeof(Data));

    if(newData == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo dado");
        return NULL;
    }
    
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
    printDataByType(newData, type);

    return newData;
}

Data* intData(int* data){
    return defaultData(data, INT);
}

Data* floatData(float* data){
    return defaultData(data, FLOAT);
}

Data* doubleData(double* data){
    return defaultData(data, DOUBLE);
}

Data* charData(char* data){
    return defaultData(data, CHAR);
}

Data* stringData(char* data){
    size_t size = strlen(data) + 1;
    return defaultData(data, STRING);
}

// Getters
Data* getData(Data* data){
    if(data->data != NULL && data->data != NULL) return data->data;
    return NULL;
}

int getSize(Data* data){
    if(data != NULL && data->size != NULL) return data->size;
    return -1;
}

size_t getType(Data* data){
    if(data != NULL && data->type != NULL) return data->type;
    return -1;
}

// Função para obter o nome do tipo
void printDataByType(Data* data, DataType type) {
    printf("\t(");
    switch (type) {
        case INT:
            printf("'%d', ", *(int*)data->data);
            break;
        case FLOAT:
            printf("'%f', ", *(float*)data->data);
            break;
        case DOUBLE:
            printf("'%ld', ", *(long int*)data->data);
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

void printData(Data* data){
    if(data->size == sizeof(int)) printf("\nData: \t%d\n", *(int*)data->data);
    else if(data->size == sizeof(float)) printf("\nData: \t%f\n", *(float*)data->data);
    else if(data->size == sizeof(double)) printf("\nData: \t%f\n", *(double*)data->data);
    else if(data->size == sizeof(char)) printf("\nData: \t%c\n", *(char*)data->data);
    else printf("\nData: \t%s", (char*)data->data);
    
    printf("\nType: \t%d", data->type);
    printf("\nSize: \t%d", data->size);
}

// Libera a memória com o dado e a estrutura em que foi alocada
void freeData(Data* data){
    if(data->data != NULL){
        free(data->data);
        data->data = NULL;
    }
    free(data);
}