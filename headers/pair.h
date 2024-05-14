#ifndef PAIR_H
#define PAIR_H

typedef struct{
    int index;
    void* first;
    void* second;
} Pair;

Pair* defaultPair();

Pair* createPair(void* first, void* second);

void freePair(Pair* pair);

void printPair(Pair* pair);

#endif /* PAIR_H */