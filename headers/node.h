#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int index;
    void* data;
    struct Node* previous;
    struct Node* next;
} Node;

Node* defaultNode();
void printNode(Node* node);
int getIndex(Node* node);
void* getData(Node* node);
void* getPrevious(Node* node);
void* getNext(Node* node);

#endif /* NODE_H */