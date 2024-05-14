#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "headers/readfile.h"
#include "headers/pair.h"
#include "headers/node.h"
#include "headers/list.h"

#define BLOCK 2

int main(){
    setlocale(LC_ALL, ("Portuguese"));

    // char filename[] = "text/filename.txt";
    // readfile(filename);
    
    // Pair* pair = defaultPair();
    // pair = createPair('{', 3);
    // printPair(pair);

    // List* list = defaultList();
    // pushList(list, "teste");
    // pushList(list, "teste2");    
    // pushList(list, "teste3");    
    
    // printNode(list->start);
    Node* node = defaultNode();
    
    printf("%s", node);
    
    return 0;
}