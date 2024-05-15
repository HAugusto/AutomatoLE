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
    
    List* list = defaultList();
    pushList(list, "teste");
    pushList(list, "abc");
    pushList(list, 34);
    pushList(list, 4);

    printList(list);
    return 0;
}