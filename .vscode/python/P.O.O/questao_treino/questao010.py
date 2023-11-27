import functools as F
def par(a):
    return a % 2 == 0 and a != 0

def soma(a,b):
    return a+b

lista = [1,2,3,4]

A = filter(par, lista)
A = F.reduce(soma,A)

print(A)
#pares = [X*2 for X in range(0,len(pares)) if X % 2 == 0]