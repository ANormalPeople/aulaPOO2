import abc

class Funcionario(abc.ABC):
    
    def __init__(self,nome):
        self._nome = nome
      
class autentica(abc.ABC):
    
    @abc.abstractmethod
    def autenticacao(self,senha):
        pass
    
class gerente(Funcionario,autentica):
    
    def __init__(self,nome,senha):
        super().__init__(nome)
        self._senha = senha 
        
    def autenticacao(self,senha):
        return senha == self._senha

class sistemainterno():
    
    def login(self,obj):
        if isinstance(obj, autentica):
            if obj.autenticacao('123'):
                print("sucesso!")
            else:
                print("falha!")
        else:
            print("objeto nao atunticavel")

class cliente():
    
    def __init__(self,nome,senha):
        self._nome = nome
        self._senha = senha
        
    def autenticacao(self,senha):
        return senha == self._senha
            
g = gerente('Flavio','123')
c = cliente('Henrrique','123')
Si =  sistemainterno()
Si.login(g)              
Si.login(c)