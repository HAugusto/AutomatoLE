#ifndef PAIR_H
#define PAIR_H

typedef struct Data Data;
typedef struct Node Node;
typedef struct List List;

typedef struct Pair {
    int     index;
    void*   first;
    void*   second;
    Node*   previous;
    Node*   next;
    
} Pair;

Pair*   defaultPair     ();
Pair*   createPair      (void* first, void* second);
Pair*   defaultCreator  (char data, int position);
Data*   getFirstData    (Pair* pair);
Data*   getSecondData   (Pair* pair);
int     getPairIndex    (Pair* pair);
Pair*   setFirstData    (Pair* pair, Data* data);
Pair*   setSecondData   (Pair* pair, Data* data);
void    freePair        (Pair* pair);
void    printPair       (Pair* pair, bool detailed);

#endif /* PAIR_H */