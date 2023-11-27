import abc

class Funcionario (abc.ABC):
    
    def __init__(self,nome,matricula):
        self.nome = nome
        self.matricula = matricula
    
    @abc.abstractmethod
    def imprimir(self):
        pass
    
class Gerente(Funcionario):
    
    def __init__(self,nome,matricula):
        super().__init__(nome,matricula)
        
    def imprimir(self):
        print("KONO DIO DA")
        
Funcionario1 = Funcionario()
gerente1 = gerente()