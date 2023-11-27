lista = [1,2,3,4,5,6,7,8,9,10]
x = len(lista)

for i in range(0,x-(x//2)):
    aux = lista[(x-1)-i]
    lista[(x-1)-i] = lista[i]
    lista[i] = aux
print(lista)