#ifndef STATE_H
#define STATE_H

typedef struct FILE *FILE;

typedef struct State {
    void*   data;
    int     start_position;
} State;

State*  defaultState        ();
State*  defaultStateCreator (void* data, int i);
State*  createState         (FILE* file, char character, int i);

#endif /* STATE_H */ 