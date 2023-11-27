import abc

class Funcionario():
    
    def  __init__(self,nome):
        self._nome = nome
        
class Gerente(Funcionario):
    
    def __init__(self,nome,senha):
        super().__init__(nome)
        self._senha = senha 
        
    def autenticacao(self,senha):
        return senha == self._senha
    
class autentica(abc.ABC):
    
    @abc.abstractmethod
    def autenticacao(self,senha):
        pass
        

class SistemaLogin():
    
    def login(self,obj):
        #So ira entrar caso o objeto seja instacia de autenticavel 
        if isinstance(obj, autentica):
            if obj.autenticacao('123'):
                print("sucesso!")
            else:
                print("falha!")
        else:
            print("objeto nao atunticavel")

Autenticavel.register(Gerente)
    
f = Funcionario('Flavio')
g = Gerente('Henrique','123456')
sL = SistemaLogin()

sL.login(f)
sL.login(g)