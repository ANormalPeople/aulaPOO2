#include "str.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void lerStr(char **str){
    *str = (char*) malloc(100 * sizeof(char));
    scanf("%s",*str);
}

int tamanhoStr(char *str){
   int tam = 0;
    while(*str != '\0'){
        str++;
        tam += 1;
    }
    return tam;
}

int comparar(char *str1, char *str2){

    int count = 0;
    while(*str1 != '\0' && *str2 != '\0'){
        if(*str1 != *str2){
            count ++;
        }
        str1++;
        str2++;
    }
    if( count == 0 && *str1 == *str2){
        return 1;
    }
    return 0;
    
}

char *concatenar(char *str1, char *str2){
    int t1 = tamanhoStr(str1);
    int t2 = tamanhoStr(str2);
    char *conca;
    char *concaincial;
    conca = (char*) malloc((t1+t2+1) * sizeof(char));
    concaincial = conca;
    while(*str1 != '\0'){
        *conca = *str1;
        conca++;
        str1++;
    }

    while(*str2 != '\0'){
        *conca = *str2;
        conca++;
        str2++;
    }

    *conca = '\0';
    
    return concaincial;

}

void liberar(char *str){
    free(str);
}