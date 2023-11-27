class Funcionario():
    
    def __init__(self,nome,salario,cpf):
        self._nome = nome
        self._salario = salario
        self._cpf = cpf
        
    def imprimir(self):
        print(self._nome,self._salario,self._cpf)
        
    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self,nome):
        self._nome = nome

    @property
    def salario(self):
        return self._salario
    
    @salario.setter
    def salario(self,salario):
        self._salario = salario

    @property
    def cpf(self):
        return self._cpf
    
    @cpf.setter
    def cpf(self,cpf):
        self._cpf = cpf

class Gerente(Funcionario):
    
    def __init__(self,nome,salario,cpf,senha):
        super().__init__(nome,salario,cpf)
        self._senha = senha   
        
    def imprimir(self):
        super().imprimir()
        print(super().nome,self._senha)

    def get_bonificação(Self):
        return 5000 + self._salario*0.05
        
class Controle_bonificação():
    
    def __init__(self):
        self._total_bonificações = 0
        
    def registra(self, funcionario):
        self._total_bonificações += funcionario.get.bonificação()
        
    def imprimir_bonificações(self):
        print(self._total_bonificações)
    
    
f1 = Funcionario("Flavio",1000,"123")
g1 = Gerente("Henrique",1000,"111","senha")

f1.imprimir()
g1.imprimir()
