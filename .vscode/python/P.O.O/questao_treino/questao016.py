class conta():
    _total_contas = 0
    
    __slots__ =['_numero','_saldo']#so pode ser criado estes atributos.
    
    def __init__(self,numero,saldo):
        self._numero = numero
        self._saldo = saldo
        conta._total_contas += 1    
    
    @property#criando o gets
    def numero(self):
        return self._numero
    
    @numero.setter#criando sets
    def numero(self,numero):
        self._numero = numero
    #É necessario cada dupla dessas para cada atributo privado
    @property
    def saldo(self):
        return self._saldo
    
    @saldo.setter
    def saldo(self,saldo):
        self._saldo = saldo
    
    @staticmethod#utilizado para criar um atributo sem self
    def mostrar():
        print("O banco tem ",conta._total_contas,"conta")
    
c1  = conta('123',150)
# c2 = conta('333',0)
# c3 = conta("222",10)
conta.mostrar()