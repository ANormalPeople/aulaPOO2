pares = []
impares = []
zeros = []
numeros = []
while True:
    num = int(input(""))
    if num < 0:
        break
    else:
        numeros.append(num)

zeros += filter(lambda x: x == 0,numeros)
pares += filter(lambda x: x % 2 == 0 and x != 0,numeros)
impares += filter(lambda x: x % 2 == 1,numeros)   
pares.sort()
impares.sort()
a = pares + zeros + impares
    #pares - suffle(impares) iria embaralhar os valores da listas impares e amarzenar em pares
    #este comando faz parte da biblioteca rand
    #pares[0:6] seria do 0 ate o 5, o parametro de parada seria o 6.
print(a)