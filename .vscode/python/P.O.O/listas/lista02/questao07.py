lista1 = list(range(10))
lista2 = list(range(10))
saida = list(range(10))

print("diga os valores da 1° lista:")
for i in range(0,len(lista1)):
    lista1[i] = int(input(""))
    
print("\ndiga os valores da 2° lista:")
for i in range(0,len(lista2)):
    lista2[i] = int(input(""))
    
for i in range(0,10):
    saida[i] = lista1[i] * lista2[i]
    
print(saida)