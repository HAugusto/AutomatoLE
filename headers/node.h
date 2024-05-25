#ifndef NODE_H
#define NODE_H

typedef enum DataType DataType;
typedef struct Data Data;
typedef struct Pair Pair;

typedef struct Node {
    struct Node*    previous;
    struct Node*    next;
    void*           data;
    int             index;
} Node;

Node*   defaultNode     ();
Node*   createNode      (void* data);
Node*   getNodePrevious (Node* node);
Node*   getNodeNext     (Node* node);
Data*   getNodeData     (Node* node);
int     getNodeIndex    (Node* node);
void    printNode       (Node* node);
void    freeNode        (Node* node);

#endif /* NODE_H */