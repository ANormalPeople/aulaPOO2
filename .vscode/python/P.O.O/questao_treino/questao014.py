par = []
impar = []
zero = []
while True:
    a = int(input(""))
    if a < 0:
        break
    elif a == 0:
        zero.append(a)
    elif a % 2 == 1:
        impar.append(a)
    elif a % 2 == 0:
        par.append(a)
        
par.sort()
impar.sort()

saida = par + zero + impar
print(saida)