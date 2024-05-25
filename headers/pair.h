#ifndef PAIR_H
#define PAIR_H

typedef struct Data Data;
typedef struct Node Node;
typedef struct List List;

typedef struct Pair {
    int     index;
    Data*   first;
    Data*   second;
    Node*   previous;
    Node*   next;
    
} Pair;

Pair*   defaultPair     ();
Pair*   createPair      (Data* first, Data* second);
Pair*   defaultCreator  (char data, int position);
Data*   getFirstData    (Pair* pair);
Data*   getSecondData   (Pair* pair);
int     getPairIndex    (Pair* pair);
void    printPair       (Pair* pair);
void    freePair        (Pair* pair);

#endif /* PAIR_H */