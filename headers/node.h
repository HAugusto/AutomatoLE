#ifndef NODE_H
#define NODE_H

typedef struct Data Data;

typedef struct Node {
    struct Node*    previous;
    struct Node*    next;
    struct Data*    data;
    int             index;
} Node;

Node*   defaultNode ();
Node*   getPrevious (Node* node);
Node*   getNext     (Node* node);
Data*   getData     (Node* node);
int     getIndex    (Node* node);
void    printNode   (Node* node);

#endif /* NODE_H */