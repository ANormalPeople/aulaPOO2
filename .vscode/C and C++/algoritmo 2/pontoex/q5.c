#include <stdio.h>
#include <string.h>

int main ()
{
    int N, cont=0; 
    char a[10];   

    scanf("%d", &N);

    while(N--){
       
        scanf("%s",a);

        if(strlen(a)==5){
            printf("3\n");            
        }else{

            if ( a[0] == 'o' ){

                cont++;
            }
            
            if ( a[1] == 'n' ){
                cont++;
            }

            if ( a[2] == 'e' ){
                cont++;
            }


            if ( cont >= 2 ){
                printf("1\n");
            }else{
                 printf("2\n");
            }
        }
    }

    return 0;
}