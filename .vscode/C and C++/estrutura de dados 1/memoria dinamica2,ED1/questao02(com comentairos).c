#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));
    int M,N,menor,aleatorio[10][2],aux[10][2],continuar=1;
    
    scanf("%d %d",&M,&N);
    while(continuar!= 0){

        if (M < N){
            menor = M;
        }else{
            menor = N;
        }

        for(int l=0;l<10;l++){
            aleatorio[l][0] = rand() % M;
            aleatorio[l][1] = rand() % N;
            aux[l][0] = aleatorio[l][0];
            aux[l][1] = aleatorio[l][1];
        }

        int x=0,z=0;

            for(int l=0;l<10;l++){
                for(int count=l+1;count<10;count++){
                    for(int c=0;c<2;c++){
                        if(aleatorio[l][c]==aux[count][c] || aleatorio[l][c] < (menor/2)){
                            x++;
                        }
                    }
                    if(x==2)
                        z++;
                    x=0;
                }  
            }

            printf("\n\n");

        for(int l=0;l<10;l++){
            for(int c=0;c<2;c++){
                printf("%d ",aleatorio[l][c]);
            }
            printf("\t");
        }
        printf("\n\n");

        printf("\n\nexistem:%d colisoes",z);
        printf("\ndeseja repetir?(1=s/0=n)");
        scanf("%d",&continuar);   

    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <stdbool.h>

// int main() {
//     srand(time(NULL));
//     int M, N, menor;
//     scanf("%d %d", &M, &N);

//     if (M < N) {
//         menor = M;
//     } else {
//         menor = N;
//     }

//     bool ocupado[M][N];

//     for (int l = 0; l < M; l++) {
//         for (int c = 0; c < N; c++) {
//             ocupado[l][c] = false;
//         }
//     }

//     int z = 0;

//     for (int i = 0; i < 10; i++) {
//         int x = rand() % M;
//         int y = rand() % N;

//         int distMinima = menor / 2;
//         bool colisao = false;

//         for (int dx = -distMinima; dx <= distMinima; dx++) {
//             for (int dy = -distMinima; dy <= distMinima; dy++) {
//                 int posX = x + dx;
//                 int posY = y + dy;

//                 if (posX >= 0 && posX < M && posY >= 0 && posY < N && ocupado[posX][posY]) {
//                     colisao = true;
//                     break;
//                 }
//             }
//             if (colisao) {
//                 break;
//             }
//         }

//         if (colisao) {
//             z++;
//         } else {
//             ocupado[x][y] = true;
//         }
//     }

//     printf("\n\n");

//     printf("\n\nExistem %d colisoes\n", z);
//     return 0;
// }
