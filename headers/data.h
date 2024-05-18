#ifndef DATA_H
#define DATA_H

#include <stddef.h>

typedef enum DataTypeEnum{
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING
} DataTypeEnum;

typedef struct Data {
    void*           data;
    size_t          size;
    DataTypeEnum    type;
} Data;

Data*   defaultData     (void* data, DataTypeEnum type);
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
size_t  getTypeSize     (DataTypeEnum type);
void    freeData        (Data* data);
void    printData       (Data* data);

#endif /* Data */