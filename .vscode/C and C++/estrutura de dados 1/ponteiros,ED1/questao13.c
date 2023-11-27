#include <stdio.h>
#include <string.h>

int veri(char *a, char *b);

int main () {

    char string1[20], string2[20];
    int r=0;
    scanf("%s %s",string1,string2);
    r = veri(string1,string2);
    if(r==1){   
        printf("a string2 existe dentro da string1");
    }else{
        printf("a string2 nao existe dentro da string1");
    }
    return 0;
}

int veri(char *a, char*b){
    char *A= a,*B= b;
    int len = strlen(b);

    while(*A != '\0'){
        if(*A == *B){
            int i = 0;
            while(*(A+i) == *(B+i)){
                i++;
                if(i == len){
                    return 1;
                }
            }    
            B = b; 
        }
        A++; 
    }
    return 0;
}

/*#include <stdio.h>
#include <string.h>

int main() {
    char string1[20], string2[20];
    int tam1, tam2;

    scanf("%s %s", string1, string2);
    tam1 = strlen(string1);
    tam2 = strlen(string2);

    for (int i = 0; i <= tam1 - tam2; i++) {
        if (strncmp(string1 + i, string2, tam2) == 0) {
            printf("a string2 existe dentro da string1");
            return 0;
        }
    }

    printf("a string2 nao existe dentro da string1");
    return 0;
}*/
