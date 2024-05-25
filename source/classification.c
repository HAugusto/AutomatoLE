#include "../headers/classification.h" // Inclui o cabeçalho "classification.h" que contém definições de estruturas e funções
#include <string.h> // Inclui a biblioteca para manipulação de strings
#include <stdio.h> // Inclui a biblioteca para entrada e saída padrão

// Declara a função classify_braces que recebe um ponteiro para uma List e um ponteiro para Classifications
void classify_braces(List* list, Classifications* classifications) {
    Node* node = list->start; // Inicializa o ponteiro node para apontar para o início da lista
    
    int stack[MAX_ITEMS]; // Declara um array stack para armazenar índices de colchetes de abertura
    int stack_top = -1; // Inicializa stack_top para -1, indicando que a pilha está vazia
    int brace_count = 0; // Inicializa brace_count para contar o número de colchetes
    int start_index = 0; // Inicializa start_index para rastrear a posição atual na lista

    while (node != NULL) { // Inicia um loop que percorre cada nó na lista até o final
        Pair* pair = (Pair*)node->data; // Obtém um ponteiro para Pair a partir dos dados armazenados no nó atual
        if (strcmp(pair->first, "{") == 0) { // Verifica se a primeira string no par é um colchete de abertura {
            stack[++stack_top] = start_index; // Empilha o índice atual e incrementa stack_top
            brace_count++; // Incrementa brace_count para contar o colchete de abertura
        } else if (strcmp(pair->first, "}") == 0) { // Verifica se a primeira string no par é um colchete de fechamento }
            start_index = stack[stack_top--]; // Desempilha a última posição de colchete de abertura e decrementa stack_top
            if (brace_count == 1) { // Verifica se brace_count é 1, indicando o fechamento do primeiro conjunto de colchetes
                Node* current = list->start; // Inicializa current para o início da lista
                for (int j = 0; j < start_index + 1; j++) { // Avança current até start_index + 1
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) { // Percorre os nós entre start_index + 1 e node->index
                    classifications->states[classifications->states_count++] = *(Pair*)current->data; // Classifica-os como states e armazena-os na estrutura classifications
                    current = current->next;
                }
            } else if (brace_count == 2) { // Verifica se brace_count é 2, indicando o fechamento do segundo conjunto de colchetes
                Node* current = list->start; // Inicializa current para o início da lista
                for (int j = 0; j < start_index + 1; j++) { // Avança current até start_index + 1
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) { // Percorre os nós entre start_index + 1 e node->index
                    classifications->alphabet[classifications->alphabet_count++] = *(Pair*)current->data; // Classifica-os como alphabet e armazena-os na estrutura classifications
                    current = current->next;
                }
            } else if (brace_count == 3) { // Verifica se brace_count é 3, indicando o fechamento do terceiro conjunto de colchetes
                Node* current = list->start; // Inicializa current para o início da lista
                for (int j = 0; j < start_index + 1; j++) { // Avança current até start_index + 1
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) { // Percorre os nós entre start_index + 1 e node->index
                    classifications->transitions[classifications->transitions_count++] = *(Pair*)current->data; // Classifica-os como transitions e armazena-os na estrutura classifications
                    current = current->next;
                }
            } else if (brace_count == 4) { // Verifica se brace_count é 4, indicando o fechamento do quarto conjunto de colchetes
                Node* current = list->start; // Inicializa current para o início da lista
                for (int j = 0; j < start_index + 1; j++) { // Avança current até start_index + 1
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) { // Percorre os nós entre start_index + 1 e node->index
                    classifications->initial_state[classifications->initial_state_count++] = *(Pair*)current->data; // Classifica-os como initial_state e armazena-os na estrutura classifications
                    current = current->next;
                }
            } else if (brace_count == 5) { // Verifica se brace_count é 5, indicando o fechamento do quinto conjunto de colchetes
                Node* current = list->start; // Inicializa current para o início da lista
                for (int j = 0; j < start_index + 1; j++) { // Avança current até start_index + 1
                    current = current->next;
                }
                for (int j = start_index + 1; j < node->index; j++) { // Percorre os nós entre start_index + 1 e node->index
                    classifications->final_states[classifications->final_states_count++] = *(Pair*)current->data; // Classifica-os como final_states e armazena-os na estrutura classifications
                    current = current->next;
                }
            }
            brace_count--; // Decrementa brace_count ao fechar um conjunto de colchetes
        }
        node = node->next; // Avança para o próximo nó na lista
        start_index++; // Incrementa start_index
    }
}

// Define a função print_classifications que recebe um ponteiro para Classifications
void print_classifications(Classifications* classifications) {
    printf("\nEstados:\n"); // Imprime o título "Estados:"
    for (int i = 0; i < classifications->states_count; i++) { // Itera sobre states
        printf("  %s at %d\n", (char*)classifications->states[i].first, (int)classifications->states[i].second); // Imprime cada par de dados em states
    }

    printf("Alfabeto:\n"); // Imprime o título "Alfabeto:"
    for (int i = 0; i < classifications->alphabet_count; i++) { // Itera sobre alphabet
        printf("  %s at %d\n", (char*)classifications->alphabet[i].first, (int)classifications->alphabet[i].second); // Imprime cada par de dados em alphabet
    }

    printf("Transições:\n"); // Imprime o título "Transições:"
    for (int i = 0; i < classifications->transitions_count; i++) { // Itera sobre transitions
        printf("  %s at %d\n", (char*)classifications->transitions[i].first, (int)classifications->transitions[i].second); // Imprime cada par de dados em transitions
    }

    printf("Estado inicial:\n"); // Imprime o título "Estado inicial:"
    for (int i = 0; i < classifications->initial_state_count; i++) { // Itera sobre initial_state
        printf("  %s at %d\n", (char*)classifications->initial_state[i].first, (int)classifications->initial_state[i].second); // Imprime cada par de dados em initial_state
    }

    printf("Estados finais:\n"); // Imprime o título "Estados finais:"
    for (int i = 0; i < classifications->final_states_count; i++) { // Itera sobre final_states
        printf("  %s at %d\n", (char*)classifications->final_states[i].first, (int)classifications->final_states[i].second); // Imprime cada par de dados em final_states
    }
}
