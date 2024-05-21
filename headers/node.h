#ifndef NODE_H
#define NODE_H

typedef struct Data Data;
typedef struct Pair Pair;

typedef struct Node {
    struct Node*    previous;
    struct Node*    next;
    void*           data;
    int             index;
} Node;

Node*   defaultNode     ();
Node*   getNodePrevious (Node* node);
Node*   getNodeNext     (Node* node);
int     getNodeIndex    (Node* node);
void*   getNodeData     (Node* node);
void    freeNode        (Node* node);
void    printNode       (Node* node);

#endif /* NODE_H */