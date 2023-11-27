#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main () {
    int N, K, ii, c, j;
    char ia[20], iant[20];

    scanf("%d", &N);


    for (c=0; c<N; c++) {
        scanf("%d", &K);
        scanf("%s", iant);
        ii = 1;

        for (j=0; j<(K-1); j++) {
            
            scanf("%s", ia);

            if (strcmp(iant, ia)) {
                ii = 0;
            }
            else {
                strcpy(iant, ia);
            }
        }
        if (ii) {
            printf("%s\n", ia);
        }
        else {
            printf("\ningles\n\n");
        }
    }

    system("PAUSE");
    return 0;
}