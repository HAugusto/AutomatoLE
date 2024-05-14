#ifndef LIST_H
#define LIST_H

#define MAX_LENGTH 5

typedef struct List {
    Node* start;
    Node* end;
    int count_nodes;

    void (*pushList)(struct List* list, void* data);
    void (*printNode)(struct Node*);
} List;

// Inicializador padrão
List*   defaultList ();
Node*   pushList    (List* list, void* data);
Node*   popList     (List* list);
Node*   getStart    (const List* list);
Node*   getEnd      (const List* list);
Node*   getPosition (const List* list, int position);
int     getLength   (const List* list);
bool    getIsEmpty  (List* list);

#endif /* LIST_H */