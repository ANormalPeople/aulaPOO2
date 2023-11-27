int main () {
int i, aux, a, b, x;

 system("cls");
 scanf("%d%d",&a, &b);
 x=0;
 if (a<b){//swap
  aux = a;
   a = b;
   b= aux;
 }
 
  for(i=a; i > 1 && !(a%i==0 && b%i==0); i--){
 }

 printf("\n%d\n",i);
 printf("\n%d\n",x);

//3518463
 system("PAUSE");
 return 0;
}