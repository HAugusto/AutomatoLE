#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../headers/data.h"

Data* defaultData(void* data, DataTypeEnum type){
    Data* newData = (Data*)malloc(sizeof(Data));

    if(newData == NULL){
        printf("Erro: não foi possível alocar memória para a criação de um novo dado");
        return NULL;
    }
    
    newData->type = type;
    newData->size = getTypeSize(type);
    newData->data = malloc(newData->size);

    if(newData->data == NULL || data == NULL){
        printf("Erro: não foi possível alocar o dado na memória");
        freeData(newData);
        return NULL;
    } 

    memcpy(newData->data, data, newData->size);
    if(memcmp(newData->data, data, newData->size) == 0) printf("\nA cópia dos dados foi bem-sucedida...");
    else printf("\nOcorreu uma falha durante a cópia dos dados...");
    
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
    if(data->data != NULL) return data->data;
    return NULL;
}

int getIntData(Data* data){
    if(data != NULL && data->size == sizeof(int)) return *(int*) data->data;
    return 0;
}

float getFloatData(Data* data){
    if(data != NULL && data->size == sizeof(float)) return *(float*) data->data;
    return 0;
}

double getDoubleData(Data* data){
    if(data != NULL && data->size == sizeof(double)) return *(double*) data->data;
    return 0;
}

char getCharData(Data* data){
    if(data != NULL && data->size == sizeof(char)) return *(char*) data->data;
    return 0;
}

char getStringData(Data* data){
    if(data != NULL && data->size == sizeof(char)) return *(char*) data->data;
    return 0;
}

int getSize(Data* data){
    if(data != NULL) return data->size;
    return 0;
}

size_t getTypeSize(DataTypeEnum type){
    switch (type){
    case INT:
        return sizeof(int);
    
    case FLOAT:
        return sizeof(float);
    
    case DOUBLE:
        return sizeof(double);
    
    case CHAR:
        return sizeof(char);
    
    case STRING:
        printf("%d", sizeof(char*));
        return sizeof(char*);
        
    default:
        return 0;
    }
}

// Libera a memória com o dado e a estrutura em que foi alocada
void freeData(Data* data){
    if(data->data != NULL){
        free(data->data);
        data->data = NULL;
    }
    free(data);
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