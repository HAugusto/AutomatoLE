#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/list.h"
#include "../headers/node.h"
#include "../headers/pair.h"
#include "../headers/data.h"

#define MAX_LENGTH 9999

// Inicializador padrão
List* defaultList(){
    List* list = (List*)malloc(sizeof(List));

    if(list == NULL){
        printf("Erro: não foi possível alocar memória para a criação de uma nova lista");
        return NULL;
    }
    
    list->start = list->end = NULL;
    list->count_nodes = 0;

    return list;
}

// Função dedicada a inserir um elemento no final da lista
Node* pushList(List* list, Data* data){
    // Verifica se a lista atingiu o limite máximo
    if(list->count_nodes > MAX_LENGTH){
        printf("Erro: não é possível inserir mais itens na lista");
        return NULL;
    }

    // Cria um novo nó alocando a memória necessária e realiza a atribuição de valores
    Node* node = defaultNode();
    node->data = data;

    // Verifica se não há um elemento inicial inserido na lista
    if(list->start == NULL){
        // Atribui o nó criado como o elemento inicial da lista
        list->start = node;
    } else {
        // Coleta o número de elementos inseridos na lista
        node->index = getListLength(list);

        // Atribui o último nó da lista como o anterior do novo nó criado
        node->previous = list->end;

        // Atribui o novo nó do nó anterior como sucessor
        list->end->next = node;
    }

    // Atualiza a referência de nó final
    list->end = node;

    // Incrementa '1' na contagem da lista
    list->count_nodes++;

    // Retorna o nó criado    
    return node;
}

// Função dedicada a retirar o elemento final de uma lista
Node* popList(List* list){
    // Verifica se a lista está vazia
    if(getListIsEmpty(list)){
        printf("Erro: a fila está vazia...");

        // Se estiver vazia, retorna nulo
        return NULL;
    }

    // Verifica se há pelo menos um item na lista
    if(list->count_nodes > 1){
        // Atribui o nó anterior ao final como o último
        list->end = list->end->previous;
        
        // Libera a memória do último nó anterior
        free(list->end->next);
        
        // Atribui o próximo elemento do novo nó final como vazio
        list->end->next = NULL;
    } else {
        // Se houver apenas um item na lista, libera a memória desse nó
        free(list->start);

        // Atribui as referências de início e fim da lista como nulos
        list->start = list->end = NULL;
    }
    
    // Decrementa '1' do contador
    list->count_nodes--;

    // Retorna o fim da fila
    return list->end;
}


// Getters
// Função dedicada a retornar o elemento inicial da lista
Node* getListStart(List* list){
    // Verifica se a lista está vazia, retornando vazio
    if(getListIsEmpty(list)) return NULL;

    // Retorna o elemento inicial
    return list->start;
}

// Função dedicada a retornar o elemento final da lista
Node* getListEnd(List* list){
    // Verifica se a lista está vazia, retornando vazio
    if(getListIsEmpty(list)) return NULL;

    // Retorna o elemento final
    return list->end;
}

Node* getListPosition(List* list, int position){
    if(position < 0 || position > getListLength(list)){
        printf("Erro: posição inválida...");
        return NULL;
    }
    
    Node* current = list->start;
    
    for(int i = 0; i < position; i++){
        if(current == NULL) return NULL;
        current = current->next;
    }

    return current;
}

Node* getListNode(List* list, Node* node){
    // Inicializa um nó no início da lista
    Node* current = list->start;

    // Procura o nó correspondente a partir do ponte de referência
    for(current; current->index < getListLength(list); current = current->next){
        printData(current->data);
        // if((Data*)getFirstData(current->data)->data == (Data*)getFirstData(node->data)->data && (Data*)getSecondData(node->data)->data == (Data*)getSecondData(node->data)->data);
        return current;
    }

    // Se não encontrar um correspondente, retorna nulo
    return NULL;
}

// Função dedicada a identificar o número de elementos na lista
int getListLength(List* list){
    // Retorna a variável 'count_nodes'
    return list->count_nodes;
}

// Função dedicada a identificar se a lista está vazia
bool getListIsEmpty(List* list){
    // Verifica se os elementos iniciais e finais são nulos, retornando 'true'
    if(list->start == NULL && list->end == NULL) return true;

    // Se houverem elementos ocupando estas posições, retorna 'false'
    return false;
}

void printList(List* list, bool detailed){
    // Verifica se a lista está vazia
    if(getListIsEmpty(list)){
        printf("Erro: a lista está vazia...");

        // Se estiver vazia, retorna falha
        exit(EXIT_FAILURE);
    }

    // Verifica se está pedindo para detalhar
    if((void*)detailed == NULL) detailed = false;

    // Cria uma instância de node, passando o início da lista
    Node* node = list->start;

    // Inicia um laço 'for', passando por todos os elementos da lista através dos nós
    for(node; node != NULL && node->next != node; node = node->next){
        // Realiza a impressão do Par
        printf("\n\n%d: ", node->index);
        printData(node->data);
    }
}


// Função dedicada a liberar a memória ocupada pela instância de uma lista
void freeList(List* list){
    // Verifica se há elementos inseridos na lista
    if(list->start != NULL) {
        // Instancia o nó final da lista
        Node* node = list->end;
        
        // Inicializa um laço 'for' com o intuito de percorrer toda a lista até o seu início
        for(node; list->start != NULL; node->previous){
            // Libera a memória dos nós que permaneceram na lista
            popList(list);
        }
    }
    
    // Por fim libera a memória ocupada pela lista
    free(list);
}