#include <stdio.h>
#include <stdlib.h>

void change(int *a,int *b);

int main () {
    int var1,var2;

    scanf("%d%d",&var1,&var2);
    printf("A:%d  B:%d",var1,var2);

    change(&var1,&var2);

    printf("\n\nA:%d  B:%d",var1,var2);

    return 0;
}

void change(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}