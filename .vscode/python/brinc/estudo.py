
n = int(input())
buffer,buffer2 = "",[]
string = []
x = 21

for i in range(n):
    aux = input()
    x1 = len(aux)
    if x1 < x:
        buffer = aux
        x = x1
    string.append(aux)
    
del aux,x1,x
        
print(string)
print(buffer)
  
#transformação de cedulas
# valor = float(input())

# notas = [100, 50, 20, 10, 5, 2]
# qtd_notas = []

# for nota in notas:
#     qtd = int(valor / nota)
#     qtd_notas.append(qtd)
#     valor -= qtd * nota

# moedas = [1, 0.50, 0.25, 0.10, 0.05, 0.01]
# qtd_moedas = []

# for moeda in moedas:
#     qtd = int(round(valor, 2) / moeda)
#     qtd_moedas.append(qtd)
#     valor = round(valor - qtd * moeda, 2)

# # impressão dos resultados
# print("NOTAS:")
# for i in range(len(notas)):
#     print(f"{qtd_notas[i]} nota(s) de R$ {notas[i]:.2f}")

# print("MOEDAS:")
# for i in range(len(moedas)):
#     print(f"{qtd_moedas[i]} moeda(s) de R$ {moedas[i]:.2f}")

#joGO DA MOEDA
# x=0
# while x < 1:
#    M = int(input())

#    V = [0] * M
#    for i in range(M):
#       V[i] = int(input()) 

#    N = int(input())
#    soma = 0

#    for i in range(0,M,N):
#       soma += V[i]


#    if soma < 2:
#       print("Bad boy! I’ll hit you.")
#    else:
#       # Percorre todos os números de 2 até a raiz quadrada de n
#       for i in range(2, int(soma**0.5) + 1):
#          if soma % i == 0:
#             print("Bad boy! I’ll hit you.")
#             break
#       else:
#          print("You’re a coastal aircraft, Robbie, a large silver aircraft.")
#          x = 1   

#mostrar a diferença de horario
# a = input().split()
# hi,mi,hf,mf = map(int,a) #o filter() tem a mesma função de map mas ela retorna true or false.
# inicio = hi * 60 + mi    #caso o valor e questao nao atinja as condioes ele não incremento o 
                           #valor a nova função.
# fim = hf * 60 + mf       #se fosse utilizado A = filter(int,a) somente os valores int iriam
# fim = hf * 60 + mf       #entrar na lista A.
# duraçao = fim - inicio

# if duraçao <= 0:
# duraçao += 24 * 60

# rh = duraçao // 60
# rm = duraçao % 60
