// #include <stdio.h>
// #include <stdlib.h>
// #include <locale.h>
// #include "../headers/list.h"
// #include "../headers/node.h"
// #include "../headers/pair.h"

// const char tokens2[] = {'{', '}', '(', ')'};

// void classifier(List* list){
//     int count = 0;
//     Node* node = list->start;
//     List* newList = defaultList();
    
//     for(node, count; node->data != NULL; node = node->next, count++){
//         Pair* pair = ((Pair*)node->data)->first;

//         if(pair->first == tokens2[0] || pair->first == tokens2[2] && count == 0){
//             printf("\nInicio: ");
//             if(pair->first == tokens2[0]){
//                 printPair((Pair*)node->data, false);
//             } else {
//                 printPair((Pair*)node->next->data, false);
//             }
//         }
//     }
// }