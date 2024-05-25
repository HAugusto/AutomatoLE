#include <stdlib.h>
#include <stdio.h>

#include "../headers/data_type.h"
#include "../headers/data.h"
#include "../headers/pair.h"

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

        case DATA:
            return "data";

        case PAIR:
            return "pair";

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

    case DATA:
        return sizeof(Data*);

    case PAIR:
        return sizeof(Pair*);
        
    default:
        return 0;
    }
}