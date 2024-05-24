#ifndef STATE_H
#define STATE_H

typedef struct State {
    void*   data;
    int     start_position;
} State;

State*  defaultState        ();
State*  createState         (void* data, int position);

#endif /* STATE_H */ 