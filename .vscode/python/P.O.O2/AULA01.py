# def posto():
#     resultado = 0
#     try:
#         respt = int(input("Qual o tipo de combustível(1-álcool/2-gasolina): "))
#         respn = float(input("Diga quantos listro foram vendidos: "))
#     except:
#         print("responda apenas com valores númericos!!!!")
     
#     if respt == 1:
#         if respn <= 20 and respn > 0:
#             resultado =  (respn * 6.45) - ((respn * 6.45) * 0.03) 
#         elif respn > 20:
#             resultado =  (respn * 6.45) - ((respn * 6.45) * 0.05)
#         else:
#             print("\nNão ponha valores negativos")

#     elif respt == 2:
#         if respn <= 20 and respn > 0:
#             resultado =  (respn * 7.63) - ((respn * 7.63) * 0.04) 
#         elif respn > 20:
#             resultado =  (respn * 7.63) - ((respn * 7.63) * 0.06)
#         else:
#             print("\nNão ponha valores negativos")
    
#     else:
#         print("\nExistem apenas as opções 1 ou 2")
    
#     if resultado > 0:
#         print(resultado)
        
# posto()

# valor = 3
# for num in range(valor):
#     print(num+1)

# valor1,valor2 = 5,2
# result = 1
# for _ in range(valor2):
#     result = result * valor1

# print(result)

# s = 'Newton'

# for i in range(len(s)-1,-1,-1):
#     print(s[i],end='')


v = [1,2,3,4,5,6,7,8,9,10]
result = 0
for a in range(len(v)):
    result += v[a]
print(result)