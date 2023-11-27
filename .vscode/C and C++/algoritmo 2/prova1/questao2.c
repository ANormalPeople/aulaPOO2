#include <stdio.h>

struct  posicao{
    float x;
    float y;
};

int main () {
    struct posicao g;

       
      
      scanf("%f %f",&g.x,&g.y);

       if(g.x==0 && g.y==0)
            printf("Origem");
        
        else if(g.x>0 && g.y>0)
            printf("Q1");
       
       else if(g.x<0 && g.y>0)
           printf("Q2");
       
       else if(g.x<0 && g.y<0)
           printf("Q3");
       
       else if(g.x>0 && g.y<0)
           printf("Q4");
       
       else if (g.x==0)
           printf("Eixo Y\n");
 
       else if (g.y == 0) 
           printf("Eixo X\n");     

    
 
    return 0;
}