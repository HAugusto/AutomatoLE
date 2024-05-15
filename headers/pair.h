#ifndef PAIR_H
#define PAIR_H

typedef struct Data Data;

typedef struct Pair {
    struct Data*    first;
    struct Data*    second;
} Pair;

Pair*   defaultPair     ();
Pair*   createPair      (Data* first, Data* second);
Data*   getFirstData    (Pair* pair);
Data*   getSecondData   (Pair* pair);
void    freePair        (Pair* pair);
void    printPair       (Pair* pair);

#endif /* PAIR_H */