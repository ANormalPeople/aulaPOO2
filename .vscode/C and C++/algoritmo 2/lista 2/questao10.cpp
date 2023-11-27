#include <iostream>
#include <queue>
#include <string.h>

int main () {

queue < char > fila;


for(char c = 'A'; c<= 'P';c++)
   fila.push(c);

for(int i=0; i<15; i++){
  int a, b;
  char ca, cb;

   ca = fila.front(); fila.pop();
   cb = fila.front(); fila.pop();

   cin >> a >> b;

  if(a<b) fila.push(ca);
  else fila.push(cb);
}
char ca;
ca = fila.front(); fila.pop();
cout << ca << end;


system ("PAUSE");
return 0;
}