tipo = input('Digite A para alco e G para gasolina:')
quantidade = int(input('Digite a quatidade de litros:'))

if tipo in ['A','a'] :
    preco_combustivel = 3.45
    desconto_20 = 3
    desconto_acime_20 = 5
else:
    preco_combustivel = 4.53
    desconto_20 = 4
    desconto_acime_20 = 6
    
if quantidade <= 20:
    desconto = preco_combustivel * quantidade * desconto_20 / 100
    preco_final = preco_combustivel * quantidade - desconto
else:
    desconto = preco_combustivel * 20 * desconto_20 / 100 
    desconto = desconto + (quantidade - 20 ) * desconto_acime_20 /100
    preco_final = preco_combustivel * quantidade - desconto
    
print('o total a pagar é: ',preco_final)    