lista = []
valor = int(input(""))
for i in range(valor):
    dicionario = {}
    dicionario["nome"] = input(f"diga o nome da {i+1}° pessoa: ")
    dicionario["idade"] = int(input(f"diga a idade do(a) {dicionario['nome'] }: "))
    lista.append(dicionario)
# lista = lista.reverse()
# atualizar = input('novo busca: ')

lista.reverse()

# for i in lista:
#     if atualizar in i['nome']:
#         i.update(idade=list(valorzin))

print(lista)    
    
    
remover = input('')

for i in lista:
    if remover in i['nome']:
        lista.remove(i)
    
    
    
print(lista)