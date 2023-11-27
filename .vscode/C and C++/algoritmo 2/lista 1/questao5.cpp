#include <stdio.h>
#include <stdlib.h>


int main () {
int m1, m2, f1, f2, ma, pr;

system("cls");

printf("diga uma idade por vez, porfavor.\n");

 scanf("%d",&m1);

 scanf("%d",&m2);

 scanf("%d",&f1);

 scanf("%d",&f2);



//SOMA
if(m1>m2){
 
  if(f1<f2){
     ma= m1 +f1;
 }
  if(f2<f1){
     ma= m1 +f2;
  }

}

if(m2>m1){
 if(f1<f2){
    ma= m2 +f1;
 }
  if(f2<f1){
     ma= m2 +f1;
  }

}

//fim da soma


//produto

if(m1<m2){
 if(f1>f2){
  pr= m1 * f1;
 }
  if(f2>f1){
  pr= m1 * f2;
  }   
}

if(m2<m1){
 if(f1>f2){
  pr= m1 * f1;
 }
  if(f2>f1){
  pr= m1 * f2;
  }   
}
 
printf("\n%d\n%d\n",ma,pr);

system("PAUSE");
return 0;
}


// o 2 resultado da questao relacionado aos produtos esta errada.
