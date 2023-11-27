#include <stdio.h>
#include <string.h>
void insercao(int *Pnt, int n);
int buscabinaria(int *arr, int esquerda, int direita, int x);

int main() {
    int n;
 
    while ((scanf("%d",&n))!=EOF) {
        
        int x,y,i,cont=0,num_pro;
        int vetor[10000],sobe,desce;
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            while(x<=y){
               vetor[cont]=x;
               cont++;
               x++;
            }
        }

        scanf("%d",&num_pro);
        insercao(vetor,cont);  

        int result = buscabinaria(vetor, 0, cont - 1, num_pro);
        sobe=result;
        desce=result;


        if(result==-1){
            printf("%d Not found.\n",num_pro);
        }else{

            for (i=1;vetor[result+i]==vetor[result]&&result-i>=0;i++) {
                sobe++;
            }

            for (i=1;vetor[result-i]==vetor[result]&&result-i>=0;i++) {
                desce--;
            }

            printf("%d found from %d to %d\n",num_pro,desce,sobe);

        }
    }

    return 0;
}

void insercao(int *Pnt, int c) {
    int i,j,aux;
    
    for(i=1;i<c;i++){
        aux=Pnt[i];
        j=i-1;
        while((j>=0)&&(Pnt[j]>aux)){
            Pnt[j+1]=Pnt[j];
            j--;
        }
     Pnt[j+1]=aux;
    }
}

int buscabinaria(int *arr, int top, int bot, int x) {
   if (bot>=top) {
        int mid=top+(bot-top)/2;


        if (arr[mid]==x)
            return mid;


        if (arr[mid]>x)
            return buscabinaria(arr,top,mid-1,x);


        return buscabinaria(arr,mid+1,bot,x);
    }
    return -1;
}