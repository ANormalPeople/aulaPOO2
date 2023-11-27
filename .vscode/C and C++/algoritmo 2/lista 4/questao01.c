#include <stdio.h>
#include <stdlib.h>
#define N 5

float calculo_media1( float x, float x1, float x2 );

float calculo_media2();

float calculo_maior( int z, float m, float m1, float m2);

struct aluno{
	char nome[20];
	float peso;
	float altura;
    float ira;
};

float maior_peso=0,maior_altura=0,maior_IRA=0,media_peso=0,media_altura=0,media_IRA=0;
int aux, aux1, aux2;

int main(){
	struct aluno turma[N];
    
	int i;

    system("cls");

	for(i=0; i<N; i++){
	
		scanf("%s %f %f %f", turma[i].nome, &turma[i].altura, &turma[i].peso, &turma[i].ira);

        calculo_maior( i, turma[i].peso,turma[i].altura,turma[i].ira);

		setbuf(stdin, NULL);
	}

    for(i=0; i<N; i++){

       calculo_media1(turma[i].peso,turma[i].altura,turma[i].ira);
       
    }
   
    calculo_media2();
 
	printf("\nMedia de peso: %f\nMedia altura: %f\nMedia IRA: %f\n\n",media_peso,media_altura,media_IRA);
    printf("Maior peso: %s(%.4f)\nMaior altura: %s(%.4f)\n",turma[aux].nome, maior_peso, turma[aux1].nome, maior_altura);
    printf("Maior IRA: %s(%.4f)\n",turma[aux2].nome,maior_IRA);
    

    system("PAUSE");
    return 0;
}


//funçoes

float calculo_media1( float x, float x1, float x2 ){

    media_peso = x + media_peso; 
    media_altura = x1 + media_altura;
    media_IRA = x2 + media_IRA;

    return 0;
}

float calculo_media2(){
    media_peso = media_peso / 5;
    media_altura = media_altura / 5;
    media_IRA = media_IRA / 5;

    return 0;
 }

float calculo_maior( int z, float m, float m1, float m2){

        if( m > maior_peso){
			maior_peso = m;
            aux = z; 
		}
        if( m1 > maior_altura){
			maior_altura = m1;
		    aux1 = z;
        }
        if( m2 > maior_IRA){
			maior_IRA = m2;
		    aux2 = z;
        }

    return 0;
}