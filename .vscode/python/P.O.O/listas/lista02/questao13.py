def menu():
    print("Escolha a opção que desejar abaixo a partir do numero indicado\n\n\n")
    print("0-incluir novo nome")
    print("1-incluir novo telefone")
    print("2-excluir telefone")
    print("3-excluir nome")
    print("4-consultar telefone")
    print("\ncaso queria finalizar o progama digite um numero negativo")

def novo_nome(nome, telefone):
    saida = {}
    saida.update(Nome=nome)
    saida.update(Telefone=list(telefone))
    return saida    
    #return{'Nome': nome, 'Telefone': list(telefone)}

def novo_telefone(lista):
    nome = input("escreva o nome de quem voce quer adicionar um telefone\n")
    novotele = input("escreva o novo telefone: ")
    for dicionario in lista:
        if nome in dicionario.values():
            dicionario['Telefone'].append(novotele)
            return lista
    else:
        r = input("nome não encontrado, deseja acrentar ele?(S/N)")
        if r in ['S','s']:
            lista.append(novo_nome(nome,novotele))
        else:
            return lista
    return lista
            
def excluir_fone(lista):
    nome = input("escreva o nome de quem voce quer remover um telefone\n")
    removefone = input("escreva o telefone: ")
    for dicionario in lista:
        if nome in dicionario.values():
           telefonis = dicionario['Telefone']
           if len(telefonis) == 1:
               lista.remove(dicionario)
               return lista
           elif removefone in telefonis:
               telefonis.remove(removefone)
               return lista
    print("pessoa nao encontrada")
    return lista

def excluir_nome(lista):
    nome = input("escreva o nome de quem voce quer remover\n")
    for dicionario in lista:
        if nome in dicionario.values():
            lista.remove(dicionario)
            return lista
    print("nome não encontrado")
    input()    
    return lista

def consultar_fone(lista):
    nome = input("diga o nome que deseja buscar: ")
    for dicionario in lista:
        if nome in dicionario.values():
            telefones = dicionario['Telefone']
            for i in telefones:
                print(i)
            input()
            return
    print("nome nao encontrado")
    input()

lista = []
a = True
while a:
    try: #try para o progama finalizar APENAS se o usuario escrever um numero negativo
         # ou teoricamente repetir se o inicio do progama der erro nesta fase incial
         # mas adicionei o try so quando eu ja tinha finalizado a contrução do progama
        telefone = []
        menu()
        resp = int(input(""))
        if resp < 0:
            a = False
        elif resp == 0:
            b = True
            nome = input("diga o nome que deseja adicionar: ")
            while b:
                numero = input("diga o telefone: ")
                telefone.append(numero)
                confirm = input('deseja adicionar mais um detelefone?(n/N para finalizar): ')
                if confirm in ['N','n']:
                    b = False
            lista.append(novo_nome(nome,telefone))
            del telefone,numero,nome,confirm
            
        elif resp == 1:
            lista = novo_telefone(lista)
        elif resp == 2:
            lista = excluir_fone(lista)
        elif resp == 3:
            lista = excluir_nome(lista)
        if resp == 4:
            consultar_fone(lista)
    except:
        a = True   