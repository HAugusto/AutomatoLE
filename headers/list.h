#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#define MAX_LENGTH 9999

typedef struct Node Node;
typedef struct Data Data;
typedef struct Pair Pair;

typedef struct List {
    struct Node*    start;
    struct Node*    end;
    int             count_nodes;

    // void (*pushList)(struct List* list, void* data);
    // void (*printNode)(struct Node*);
} List;

// Inicializador padrão
List*   defaultList ();
Node*   pushList        (List* list, Data* data);
Node*   popList         (List* list);
Node*   getListStart    (List* list);
Node*   getListEnd      (List* list);
Node*   getListPosition (List* list, int position);
Node*   getListNode     (List* list, Node* node);
int     getListLength   (List* list);
bool    getListIsEmpty  (List* list);
void    freeList        (List* list);
void    printList       (List* list, bool detailed);

#endif /* LIST_H */