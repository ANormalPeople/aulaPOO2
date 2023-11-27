#include <stdio.h>
int main()
{
    double soma = 0.0, M[12][12];
    char O;
    int c, l, c2 = 0;
    scanf("%s", &O);
    for (l = 0; l <= 11; l++)
    {
        for (c = 0; c <= 11; c++)
            scanf("%lf", &M[l][c]);
    }
    for (l = 1; l <= 11; l++)
    {
        for (c = 0; c <= c2; c++)
            soma += M[l][c];
        c2++;
    }
    if (O == 'S')
        printf("%.1lf\n", soma);
    else
    {
        printf("%.1lf\n", soma / 66.0);
    }
    return 0;
}
