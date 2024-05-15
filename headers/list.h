#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#define MAX_LENGTH 5

typedef struct Node Node;

typedef struct List {
    struct Node*    start;
    struct Node*    end;
    int             count_nodes;

    // void (*pushList)(struct List* list, void* data);
    // void (*printNode)(struct Node*);
} List;

// Inicializador padrão
List*   defaultList ();
Node*   pushList    (List* list, void* data);
Node*   popList     (List* list);
Node*   getStart    (List* list);
Node*   getEnd      (List* list);
Node*   getPosition (List* list, int position);
int     getLength   (List* list);
bool    getIsEmpty  (List* list);
void    printList   (List* list);

#endif /* LIST_H */