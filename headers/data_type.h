#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <stddef.h>

typedef enum DataType{
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING,
    START,
    FINAL,
    STATE,
    TRANSITION,
    ALPHABET,
    NONE,
} DataType;

char*   getDataTypeName (DataType type);
size_t  getDataTypeSize (DataType type);

#endif /* DATA_TYPE_H */
