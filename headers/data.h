# ifndef DATA_H
#define DATA_H

#include <stddef.h>

typedef struct Data {
    size_t  size;
    void*   data;
} Data;

Data*   defaultData (size_t size, void* data);
void    freeData    (Data* data);

#endif /* Data */