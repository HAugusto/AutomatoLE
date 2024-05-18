#include <stdio.h>

void clearBuffer(){
    while(getchar() != '\n' && getchar() != EOF);
}