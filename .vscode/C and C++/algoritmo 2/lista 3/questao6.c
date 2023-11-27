#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// o verbo saltos etava na questao.


//"Enfim, o programa deverá concatenar às palavras em um vetor que seja suficientemente
//grande para conter a frase inteira"

//Não entendi muito bem essa parte mas acredito que desejava um char de 20 para armazenar cada.

int a,  s, v, p, a1, s1, c;

int unindo_printando();
int aleatorizar();

int main () {

   srand(time(NULL));

   system("cls");

   for(c=0;c<20;c++){

      aleatorizar();
    
      unindo_printando();

   }

    printf("\n");

    system("PAUSE");
    return 0;
}

//funçoes

int aleatorizar(){

     a = rand()%4;
     a1 = rand()%4;
     s = rand()%4;
     s1 = rand()%4;
     v = rand()%4;
     p = rand()%4;     

     return 0;
}

int unindo_printando(){
    char art[5][15]={" o "," um "," algum "," todo "," qualquer "};//artigo
    char sub[5][15]={"menino","homem","cachorro","carro","gato"};//substantivo
    char ver[5][15]={" passou "," pulou "," correu "," saltos "," andou "};//verbo
    char pre[5][15]={"sobre","sob","ante","ate","com"};//preposição
    char frase[20][50]={0};

    strcat(frase[c],art[a]);
    strcat(frase[c],sub[s]); 
    strcat(frase[c],ver[v]);
    strcat(frase[c],pre[p]);
    strcat(frase[c],art[a1]);
    strcat(frase[c],sub[s1]);
     
    frase[c][1]=frase[c][1]- 32;

    printf("\n%s.\n",frase[c]);

    return 0;
}
