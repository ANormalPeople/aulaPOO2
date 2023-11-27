import abc

class Conta(abc.ABC):
    def __init__(self,numero,titular,saldo=0,limite=1000.0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo
        self._limite = limite 

    @property
    def numero(self):
        return self._numero
    
    @numero.setter
    def numero(self,numero):
        self._numero = numero
        
    @property
    def titular(self):
        return self._titular
    
    @titular.setter
    def titular(self,titular):
        self._titular = titular
        
    @property
    def saldo(self):
        return self._saldo
    
    @saldo.setter
    def saldo(self,saldo):
        self._saldo = saldo

    @property
    def limite(self):
        return self._limite
    
    @limite.setter
    def limite(self,limite):
        self._limite = limite

    @abc.abstractmethod
    def atualiza(self,taxa):
        pass
    
class contacorrete(Conta):
    
    def __init__(self,numero,titular,saldo):
        super().__init__(numero,titular,saldo)
        
    def atualiza(self,taxa):
        self.saldo += self.saldo * 3 * taxa
    
class contapoupanca(Conta):
    
    def __init__(self,numero,titular,saldo):
        super().__init__(numero,titular,saldo)
        
    def atualiza(self,taxa):
        self.saldo += self.saldo * 9 * taxa
    
class containvestimento(Conta):
    
    def __init__(Self,numero,titular,saldo):
        super().__init__(numero,titular,saldo)
        
    def atualiza(self,taxa):
        self.saldo += self.saldo * 5 * taxa

    def deposito(self,valor):
        self.saldo += valor
    
if __name__ == '__main__':
    
    Cc = contacorrete('123-4','joao',1000.0)    
    Cp = contapoupanca('123-5','jose',1000.0)
    Ci = containvestimento('123-6','Maria',1000.0)
    Ci.deposito(1000.0)

    Cc.atualiza(0.01)
    Cp.atualiza(0.01)
    Ci.atualiza(0.01)
    
    print(Cc.saldo)
    print(Cp.saldo)
    print(Ci.saldo)