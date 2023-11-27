# retorna os o dobro dos valores pares de uma lista
import functools as f
A = input().split()
r = filter(lambda x: int(x) % 2 == 0 and int(x) != 0, A)
r = map(lambda x: int(x) * 2, r)
r = f.reduce(lambda x,x2: int(x) + int(x2),r)
print(r)
