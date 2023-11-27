#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    int ***tri,v;

    scanf("%d",&v);
    int r = v/2;
    tri = (int***) calloc(v, sizeof(int **));
    int l, c;
    for(l=0;l<v;l++)
        tri[l] = (int**) calloc(v, sizeof(int *));
    for(l=0;l<v;l++){
        for(c=0;c<v;c++){
        tri[l][c] = (int*) calloc(v, sizeof(int ));
        }
    } 

    for(int i=0;i<v;i++){
        for(l=0;l<v;l++){
            for(c=0;c<v;c++){
                int dS = pow((l - r),2) + pow((c - r),2) + pow((i - r),2);
                if (dS <= r*r)
                    tri[i][l][c] = 1; 
                }
            }
            
        }
    
	for (int z = 0; z < v; ++z){
		for (int y = 0; y < v; ++y){
			for (int x = 0; x < v; ++x){
				printf("%d ", tri[z][y][x]);
			}
			printf("\n");
		}
		printf("\n");
	}
    return 0;
}