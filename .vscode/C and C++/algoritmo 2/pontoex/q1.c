
double calculaArea(char operacao, double M[][12]);

#include <stdio.h>
int main(){
    char x;
    double z;


    scanf("%s",&x);
    z=calculaArea(x,z);

    return 0;

}
double calculaArea(char operacao, double M[][12]){
    double l,c,c2=0;
    double s=0.0;

    for (l = 0; l <= 11; l++){
        for (c = 0; c <= 11; c++)
            scanf("%lf", &M[l][c]);
    }
    for (l = 1; l <= 11; l++){
        for (c = 0; c <= c2; c++){
            s += M[l][c];
        }
        c2++;
    }

    if (operacao == 'S')
      return s;
    else
    {
        printf("%.1lf\n", s / 66.0);
    }
    return s;

}