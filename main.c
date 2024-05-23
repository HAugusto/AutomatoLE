#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "headers/readfile.h"
#include "headers/list.h"

#define BLOCK 2

int main(){
    // Define a linguagem para Português do Brasil
    setlocale(LC_ALL, ("Portuguese"));

    char filename[] = "text/filename.txt";
    List* list = readfile(filename);
    
    

    // char data;
    // int position;

    // List* list = defaultList();

    // for(int i = 0; i < 3; i++){
    //     printf("\nData: \t\t");
    //     scanf("%c", &data);
    //     clearBuffer();
    //     printf("Position: \t");
    //     scanf("%d", &position);
    //     clearBuffer();

    //     pushList(list, defaultCreator(data, position));
    // }

    // printList(list);

    return 0;
}