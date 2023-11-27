#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main () {

    int tri[50][50]={0},l,c,v=50;
    int r = v/2;

        for(l=0;l<v;l++){
            for(c=0;c<v;c++){
                int dS = pow((l-r),2) + pow((c-r),2);

            if (dS <= r*r)
                tri[l][c] = 1; 

            }
        }
    
		for (int y = 0; y < v; ++y){
			for (int x = 0; x < v; ++x){
				printf("%d ", tri[y][x]);
			}
			printf("\n");
		}
    return 0;
}