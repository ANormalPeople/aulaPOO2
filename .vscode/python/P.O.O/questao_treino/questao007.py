maxi = 10
mini = 0
quant = 6

import random

sorteados = []

while len(sorteados) < quant:
    x = random.randint(mini, maxi)
    if x not in sorteados:
        sorteados.append(x)
    
    print(sorteados)
