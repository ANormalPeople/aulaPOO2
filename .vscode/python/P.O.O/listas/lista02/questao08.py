import random
lista = [random.randint(1,3) for _ in range(13)]
cartao1 = [101] + [random.randint(1,3) for _ in range(13)]
cartao2 = [102] + [random.randint(1,3) for _ in range(13)]
cartao3 = [103] + [random.randint(1,3) for _ in range(13)]
valor1,valor2,valor3 = 0,0,0

for i in range(13):
    if cartao1[i+1] == lista[i]:
        valor1 += 1    
    if cartao2[i+1] == lista[i]:
        valor2 += 1          
    if cartao3[i+1] == lista[i]:
        valor3 += 1

print("o jogador de numero",cartao1[0],"acertou",valor1,"vezes!")
print("o jogador de numero",cartao2[0],"acertou",valor2,"vezes!")   
print("o jogador de numero",cartao3[0],"acertou",valor3,"vezes!")     

if valor1 == 13:
    print("o",cartao1[0],"ganhou!")        
if valor2 == 13:
    print("o",cartao2[0],"ganhou!")
if valor3 == 13:
    print("o",cartao3[0],"ganhou!")              