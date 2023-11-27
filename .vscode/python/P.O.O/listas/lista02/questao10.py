import math

def calmedia(lista):
    media = 0
    for i in lista:
        media += i
    media = media/len(lista)
    return media    

def calmediana(lista):
    if len(lista) % 2 == 0:
        x = len(lista)//2
        mediana = (lista[x] + lista[x-1]) / 2
    else:
        mediana = lista[x]
    return mediana
    
def calvariante(lista,media):
    variante = [0] * len(lista)
    for i, valor in enumerate(lista):
        variante[i] = (valor-media) ** 2
    x = calmedia(variante)
    return x
    
lista = list(range(1,101))

media = calmedia(lista)
mediana = calmediana(lista)
variante = calvariante(lista,media)
desvio = math.sqrt(variante)
    
print(media)
print(mediana)
print(variante)
print("{:.2f}".format(desvio))