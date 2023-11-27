entrada = input()
N = entrada.split()
N = [int(x) for x in N]
Aux = [int(x) for x in N]

i,x=0,0
for i in range (len(N)):
    for c in range (i+1,len(N)):
        if N[i] == Aux[c]:
            x+=1
          
    if x==0:        
        print(N[i])
    x=0
