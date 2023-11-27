#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, j, m , n, p, x, n1;

system("cls");

    m=2;
    n=3; 
    p=2;
    n1=n;
    float A[m][n], B[n][p], C[m][p], aux = 0;

    if (n == n1)
    {
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
            {
                printf("\n\n Valor da %d%c linha e da %d%c coluna da maitriz A: ", i+1, 167, j+1, 167);
                scanf("%f", &A[i][j]);
            }
            printf("\n");
        }
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < p; j++)
            {
                 printf("\n\n Valor da %d%c linha e da %d%c coluna da maitriz B: ", i+1, 167, j+1, 167);
                 scanf("%f", &B[i][j]);
            }
            printf("\n");
        }



        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
            {
                printf("%6.f",A[i][j]);
            }
            printf("\n\n");
        }

        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < p; j++)
            {
                printf("%6.f", B[i][j]);

            }
            printf("\n\n");
            
        }
        
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < p; j++)
            {
                C[i][j] = 0;
                for ( x = 0; x < p; x++)
                {
                    aux += A[i][x] * B[x][j];
                }
                C[i][j] = aux;
                aux = 0;
            }
            
        }
        
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < p; j++)
            {
                printf("%6.f", C[i][j]);
            }
            printf("\n\n");
        }
        printf("\n\n");
    }
    else
    {
        printf("\n\n Nao pode ser multiplicada!");
    }
    
    return 0;
    system("PAUSE");

}


