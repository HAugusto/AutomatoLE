#ifndef NODE_H
#define NODE_H

typedef enum DataType DataType;
typedef struct Data Data;
typedef struct Pair Pair;

typedef struct Node {
    struct Node*    previous;
    struct Node*    next;
    Data*           data;
    int             index;
} Node;

Node*   defaultNode     ();
Node*   createNode      (void* data, DataType type);
Node*   getNodePrevious (Node* node);
Node*   getNodeNext     (Node* node);
int     getNodeIndex    (Node* node);
Data*   getNodeData     (Node* node);
void    freeNode        (Node* node);
void    printNode       (Node* node);

#endif /* NODE_H */