#ifndef DATA_H
#define DATA_H

#include <stddef.h>

typedef enum DataTypeEnum{
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
} DataTypeEnum;

typedef struct Data {
    void*           data;
    size_t          size;
    DataTypeEnum    type;
} Data;

Data*   defaultData     ();
Data*   createData      (void* data, DataTypeEnum type);
Data*   intData         (int* data);
Data*   floatData       (float* data);
Data*   doubleData      (double* data);
Data*   charData        (char* data);
Data*   stringData      (char* data);
Data*   getData         (Data* data);
int     getIntData      (Data* data);
float   getFloatData    (Data* data);
double  getDoubleData   (Data* data);
char    getCharData     (Data* data);
char    getStringData   (Data* data);
int     getSize         (Data* data);
char*   getDataTypeName (DataTypeEnum type);
size_t  getDataTypeSize (DataTypeEnum type);
void    freeData        (Data* data);
void    printDataByType (Data* data, DataTypeEnum type);
void    printData       (Data* data);

#endif /* Data */