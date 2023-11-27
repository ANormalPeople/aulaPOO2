import datetime
class pessoa:
    
    def __init__ (self,nome,data_nascimento,altura):
        self._nome = nome
        self._data_nascimento = data_nascimento
        self._altura = altura
        
    @property
    def nome(self):
        return self._nome
    
    @nome.setter
    def nome(self,nome):
        self._nome = nome
        
    @property
    def data_nascimento(self):
        return self._data_nascimento
    
    @data_nascimento.setter
    def data_nascimento(self,data_nascimento):
        self._data_nascimento = data_nascimento

    @property
    def altura(self):
        return self._altura
    
    @altura.setter
    def altura(self,altura):
        self._altura = altura        
        
    def imprimir(self):
        print("\nNome: ",self.nome)
        print("data de nascimento: ",self.data_nascimento)
        print("Idade: ",self.idade())
        print("altura: ",self.altura)
        
    def idade(self):
        dia,mes,ano = self.data_nascimento.split('/')
        dia,mes,ano = int(dia),int(mes),int(ano)
        data_nascimento = datetime.datetime(ano,mes,dia)
        data_atual = datetime.datetime.now()
        diferenca = data_atual - data_nascimento
        idade = diferenca.days // 365
        return idade

nome = input("diga o seu nome: ")
altura = float(input("diga sua altura: "))
data = input("Diga sua data de nascimento na ordem dia, mes e ano(ex:00/00/0000): ")

pessoa1 = pessoa(nome,data,altura)
pessoa1.imprimir()