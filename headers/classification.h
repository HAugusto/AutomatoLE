#include "list.h"
#include "node.h"
#include "pair.h"

#define MAX_ITEMS 100

typedef struct {
    Pair states[MAX_ITEMS];
    int states_count;
    Pair alphabet[MAX_ITEMS];
    int alphabet_count;
    Pair transitions[MAX_ITEMS];
    int transitions_count;
    Pair initial_state[MAX_ITEMS];
    int initial_state_count;
    Pair final_states[MAX_ITEMS];
    int final_states_count;
} Classifications;

void classify_braces(List* list, Classifications* classifications);
void print_classifications(Classifications* classifications);