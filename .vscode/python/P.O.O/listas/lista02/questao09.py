lista = []
valor = int(input(''))
for i in range(valor):
    pessoa = {}
    pessoa['nome'] = input('nome: ')
    pessoa['endereço'] = input('')
    pessoa['CEP'] = input('')
    pessoa['bairro'] = input('')
    pessoa['telefone'] = input('')
    lista.append(pessoa)

for i in range(len(lista)-1,-1,-1):
    linha = lista[i]
    print("nome:",linha['nome'])
    print('endereço: ',linha['endereço'])
    print('cep: ',linha['CEP'])
    print('bairro: ',linha['bairro'])
    print('telefone: ',linha['telefone'])
    print()