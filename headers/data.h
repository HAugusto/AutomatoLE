#ifndef DATA_H
#define DATA_H

#include <stddef.h>

typedef enum DataType DataType;

typedef struct Data {
    void*           data;
    size_t          size;
    DataType        type;
} Data;

// Construtores
Data*   defaultData         ();
Data*   createData          (void* data, DataType type);
Data*   createIntData       (int* data);
Data*   createFloatData     (float* data);
Data*   createDoubleData    (double* data);
Data*   createCharData      (char* data);
Data*   createStringData    (char* data);

// Getters
Data*       getData             (Data* data);
size_t      getSize             (Data* data);
DataType*   getType             (Data* data);

// Print
void    printDataByType     (Data* data, DataType type);
void    printData           (Data* data);

// Liberação de Memória
void    freeData            (Data* data);

#endif /* Data */