class agenda():
    
    def __init__(self):
        self.pessoa = []

    def ArmazenarPessoa(self):
        if len(self.pessoa) < 10:
            nome = input("diga o nome: ")
            idade = int(input("diga a idade: "))
            altura = float(input("diga a altura: "))
            saida = {}
            saida.update(Nome=nome)
            saida.update(Idade=idade)
            saida.update(Altura=altura)
            self.pessoa.append(saida)         
        else:
            print("\nQuantidade maxima atingida!!!!\n")
            input()
            
    def removerPessoa(self):
        nome = input("diga o nome que deseja remover: ")
        for dicionario in self.pessoa:
            if nome in dicionario.values():
                self.pessoa.remove(dicionario)
                return self.pessoa
        print("pessoa não encontrada")
        input()
        
    def buscaPessoa(self):
        nome = input("diga o nome que deseja buscar: ")
        for dicionario in self.pessoa:
            if nome in dicionario.values():
                print()
                for chave, valor in dicionario.items():
                    print(f"{chave}: {valor}")
                return
        print('pessoa não encontrada!!')
        
    def imprimeAgenda(self):
        print()
        for dicionario in self.pessoa:
            for chave, valor in dicionario.items():
                print(f"{chave}: {valor}")
            print()
minha_agenda = agenda()
minha_agenda.ArmazenarPessoa()
minha_agenda.ArmazenarPessoa()
minha_agenda.imprimeAgenda()
minha_agenda.removerPessoa()
minha_agenda.buscaPessoa()