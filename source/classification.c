#include "../headers/classification.h"
#include <string.h>
#include <stdio.h>

void classify_braces(List* list, Classifications* classifications) {
    Node* node = list->start;
    
    int stack[MAX_ITEMS];
    int stack_top = -1;
    int brace_count = 0;
    int start_index = 0;

    while (node != NULL) {
        Pair* pair = (Pair*)node->data;
        if (strcmp(pair->first, "{") == 0) {
            stack[++stack_top] = start_index;
            brace_count++;
        } else if (strcmp(pair->first, "}") == 0) {
            start_index = stack[stack_top--];
            if (brace_count == 1) {
                Node* current = list->start;
                for (int j = 0; j < start_index + 1; j++) {
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) {
                    classifications->states[classifications->states_count++] = *(Pair*)current->data;
                    current = current->next;
                }
            } else if (brace_count == 2) {
                Node* current = list->start;
                for (int j = 0; j < start_index + 1; j++) {
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) {
                    classifications->alphabet[classifications->alphabet_count++] = *(Pair*)current->data;
                    current = current->next;
                }
            } else if (brace_count == 3) {
                Node* current = list->start;
                for (int j = 0; j < start_index + 1; j++) {
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) {
                    classifications->transitions[classifications->transitions_count++] = *(Pair*)current->data;
                    current = current->next;
                }
            } else if (brace_count == 4) {
                Node* current = list->start;
                for (int j = 0; j < start_index + 1; j++) {
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) {
                    classifications->initial_state[classifications->initial_state_count++] = *(Pair*)current->data;
                    current = current->next;
                }
            } else if (brace_count == 5) {
                Node* current = list->start;
                for (int j = 0; j < start_index + 1; j++) {
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) {
                    classifications->final_states[classifications->final_states_count++] = *(Pair*)current->data;
                    current = current->next;
                }
            }
            brace_count--;
        }
        node = node->next;
        start_index++;
    }
}

void print_classifications(Classifications* classifications) {
    printf("Estados:\n");
    for (int i = 0; i < classifications->states_count; i++) {
        printf("  %s at %d\n", (char*)classifications->states[i].first, (int)classifications->states[i].second);
    }

    printf("Alfabeto:\n");
    for (int i = 0; i < classifications->alphabet_count; i++) {
        printf("  %s at %d\n", (char*)classifications->alphabet[i].first, (int)classifications->alphabet[i].second);
    }

    printf("Transições:\n");
    for (int i = 0; i < classifications->transitions_count; i++) {
        printf("  %s at %d\n", (char*)classifications->transitions[i].first, (int)classifications->transitions[i].second);
    }

    printf("Estado inicial:\n");
    for (int i = 0; i < classifications->initial_state_count; i++) {
        printf("  %s at %d\n", (char*)classifications->initial_state[i].first, (int)classifications->initial_state[i].second);
    }

    printf("Estados finais:\n");
    for (int i = 0; i < classifications->final_states_count; i++) {
        printf("  %s at %d\n", (char*)classifications->final_states[i].first, (int)classifications->final_states[i].second);
    }
}