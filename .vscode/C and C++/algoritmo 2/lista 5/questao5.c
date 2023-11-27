#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card{
    int face;
    int naipe;
};

typedef struct card Card;

void preenche(Card *sDeck, char *tFace, char *zSuit);
void embaralha(Card *sDeck);
void imprime(Card *sDeck);

char face[][20]={"As","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove","Dez","Valete","Dama","Rei"};
char naipe[][20]={"Copas","Ouros","Paus","Espadas"};


int main(){
    Card deck[52];

    preenche(deck,face,naipe);
    embaralha(deck);
    imprime(deck);

    system("PAUSE");
    return 0;
}

void preenche( Card *sDeck, char *tFace, char *zSuit){
   int c;
   for(c=0; c<52; c++){
        sDeck[c].face=c%13;
        sDeck[c].naipe=c%4;

   }
}

void embaralha(Card *sDeck){
    int c,x;
    Card temp;
    srand(time(NULL));

    for(c=0;c<52;c++){
        x=rand()%12;
        temp=sDeck[c];
        sDeck[c]=sDeck[x];
        sDeck[x]=temp;
    }
}   

void imprime(Card *sDeck){
    int c,z,y;

    for(c=0;c<52;c++){
        z=sDeck[c].face;
        y=sDeck[c].naipe;
        printf("%s de %s\n",face[z],naipe[y]); 
    }

}