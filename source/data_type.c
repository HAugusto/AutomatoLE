#include <stdlib.h>
#include <stdio.h>

#include "../headers/data_type.h"

// Função para obter o nome do tipo
char* getDataTypeName(DataType type) {
    switch (type) {
        case INT:
            return "int";
        case FLOAT:
            return "float";
        case DOUBLE:
            return "double";
        case CHAR:
            return "char";
        case STRING:
            return "string";
        case NONE:
            return "none";
        default:
            return "unknown";
    }
}

size_t getDataTypeSize(DataType type){
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
        return sizeof(char*);
        
    default:
        return 0;
    }
}