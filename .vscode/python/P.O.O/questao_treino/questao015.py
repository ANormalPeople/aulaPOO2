class conta():
    
    def __init__(self,idd,numero,titular, saldo=0):
        self.numero = numero
        self.titular = titular
        self.saldo = saldo
        self._id = idd

    def extrato(self):
        print('A conta esta sob o titular',self.titular)
        print('o numero da conta é', self.numero)
        print('o saldo da conta é', self.saldo)

    def depositar(self, deposito): 
        if deposito > 0:
            self.saldo += deposito
            return True,'sucesso!'
        else:
            return False,'valor negativo'
            
    def sacar(self, valor):
        if valor <= self.saldo and valor < 0:
            self.saldo -= valor
            return valor
        else:
            print("O saldo não é sufuciente para tal ação")
            return -1
            
    def transfere(self,valor,destino):
        if self.saldo >= valor:
            self.saldo -= valor
            destino.saoldo += valor
            return True, 'sucesso!'
        else:
            return false, 'fracasso'
       
class cliente():
    def __init__(self,nome,cpf):
        self.nome = nome
        self.cpf = cpf
        self.conta = conta(self.telefone,self.cpf,self.nome)
    
    def __init__(self,nome,cpf):
        r = 0 
        while True:
            print("escolha uma alternativa:\n\n")
            print("|----------------------------|")
            print("|1 para depositar            |")
            print("|2 para sacar                |") 
            print("|3 para ter acesso ao extrato|")
            print("|4 para deleter as contas    |")       
            print("|----------------------------|")

            r = int(input(""))
    def delete(self):
        del self
        
    def extrato(self):
        conta.extrato()

    def depositar(self):
        conta.depositar(int(input("")))
        
    def sacar(self):
        conta.sacar(int(input("")))

cliente1 = cliente(input(""),int(input("")),input(""),int(input("")))
