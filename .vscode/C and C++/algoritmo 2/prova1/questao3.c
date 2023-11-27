#include <stdio.h>

double calculaArea(char operacao, double M[][12]);

int main(){
    int i,j;
    double rest,mat[12][12];
    char op;
    scanf("%c", &op);
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	rest=calculaArea(op,mat);
    printf("%.1lf\n",rest);
    return 0;
}

double calculaArea(char operacao, double M[][12]){
	int i, j;
	double resultado=0, cont=0;

    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            if(i+j < 11){
                resultado += M[i][j];
                cont += 1.0;
            }
        }
    }
    if(operacao == 'M'){
    	resultado = resultado/cont;
	}
	return resultado;
}