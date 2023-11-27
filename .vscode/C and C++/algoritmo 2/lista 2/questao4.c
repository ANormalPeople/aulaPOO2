#include <stdio.h>

int main() {
    int vetor[10],aux[10]={0};
    int c,i,x=0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
        aux[i]=vetor[i];
    }

    for(i = 0;i < 10; i++){
        for(c = i+1; c < 10; c ++){
            if(vetor[i]==aux[c]){
                x++;
            }// 1x 2 3 4 5 6 7 8 9 10
             // 1 2x 3x 4x 5x 6x 7x 8x 9x 10x
        }
        if(x==0){
            printf("a%d\n",vetor[i]);
        }
        x=0;
    } 
    return 0;
}

// 14 linhas em python
// entrada = input()
// N = entrada.split()
// N = [int(x) for x in N]
// Aux = [int(x) for x in N]

// i,x=0,0
// for i in range (len(N)):
//     for c in range (i+1,len(N)):
//         if N[i] == Aux[c]:
//             x+=1
            
//     if x==0:        
//         print(N[i])
//     x=0




// int c, cont[10]={0},cont2[10];

// system("cls");

// for(c=0;c<10;c++){

//  scanf("%d",&cont2[c]);

//   if(cont2[c] >= 10 && cont2[c] < 100){
  
//   cont[c] = cont2[c];
//   }else{
//    c--; 
//   }
// }

// printf("\n");

// if(cont[0]!= cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[0]);
//   }

// if(cont[1]!= cont[0] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[1]);
//   }

// if(cont[2]!= cont[0] && cont[1] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[2]);
//   }

// if(cont[3]!= cont[0] && cont[1] && cont[2] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[3]);
//   }

// if(cont[4]!= cont[0] && cont[1] && cont[2] && cont[3] && cont[5] && cont[6] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[4]);
//   }

// if(cont[5]!= cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[6] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[5]);
//   }

// if(cont[6]!= cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[7] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[6]);
//   }

// if(cont[7]!= cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[8] && cont[9]){
    
//  printf("%d\t",cont[7]);
//   }

// if(cont[8]!= cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[9]){
    
//  printf("%d\t",cont[8]);
//   }

// if(cont[9]!= cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8]){
    
//  printf("%d\t",cont[9]);
//   }

// system("PAUSE");
// return 0;
// }