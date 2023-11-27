#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Carta{
    int face;
    int naipe;
};

char *face[][15] = {"As","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove","Dez","Valete","Dama","Rei"};
char *naipe[][15] = {"paus","ouros","copas","espadas"};

void preenche( Carta *deck, char *face[ ], char *naipe[ ] );
void embaralha( Carta *deck );
void imprime( Carta *deck );

int main () {
    Carta deck[52];

    void preenche( Carta *deck, char *face[ ], char *naipe[ ] );
    void embaralha( Carta *deck );
    void imprime( Carta *deck );

    system("PAUSE");
    return 0;
}


void preenche( Carta *deck, char *face[ ], char *naipe[ ] ){
    int c;

    for(c=0;c<52;c++){
        deck[c].face = c % 13;
        deck[c].naipe = c % 4;
    }

}

void embaralha( Carta *deck ){
    int c,x;
    srand(time(NULL));
        
    for(c=0;c<52;c++){
        x=rand()%12;
        deck[c] = 

    }

}

