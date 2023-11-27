import datetime
class Historico():
    def __init__(self):
        self.data_da_abertura = datetime.datetime.today()
        self.transacoes = []
    
    def imprimir(self):
        print("Data de abertura da conta  {}".format(self.data_da_abertura))
        print("\n------TRANSAÇÕES------")
        for t in self.transacoes:
            print("-",t)
        print("----------------------")
                        
class SeguroVida:
    def __init__(self, valor_mensal, valor_total):
        self._valor_mensal = valor_mensal
        self._valor_total = valor_total
                        
    @property
    def valor_mensal(self):
        return self._valor_mensal
    
    @valor_mensal.setter
    def valor_mensal(self,valor_mensal):
        self._valor_mensal = valor_mensal    
        
    @property
    def valor_total(self):
        return self._valor_total
    
    @valor_total.setter
    def valor_total(self,valor_total):
        self._valor_total = valor_total    
                    
class Conta:
    def __init__(self, numero, saldo=0):
        self._numero = numero
        self._saldo = saldo

    @property
    def numero(self):
        return self._numero

    @numero.setter
    def numero(self, numero):
        self._numero = numero

    @property
    def saldo(self):
        return self._saldo

    @saldo.setter
    def saldo(self, saldo):
        self._saldo = saldo

class ContaCorrente(Conta):
    pass

class ContaPoupanca(Conta):
    pass 

class Cliente():
    proximo_id = 0
    _clientes = []
    _tributacoes = []

    def __init__(self, cpf,nome):
        self._cpf = cpf
        self._nome = nome
        self._numero = Cliente.proximo_id
        Cliente.proximo_id += 1        
        Cliente._clientes.append(self)
        self._contas_correntes = []
        self._contas_poupancas = []
        self._seguros_de_vida = []
        self.Historico = Historico()
        
    @property
    def seguros_de_vida(self):
        return self._seguros_de_vida
        
    def adicionar_seguro_de_vida(self):
        seguro = SeguroVida(100,1000)    
        self.seguros_de_vida.append(seguro)

    @property
    def clientes(self):
        return self._clientes

    @property
    def tributacoes(self):
        return self._tributacoes

    @property
    def contas_correntes(self):
        return self._contas_correntes

    def adicionar_conta_corrente(self):
        if len(self.contas_correntes) < 1:
            a = ContaCorrente(self.numero)    
            self.contas_correntes.append(a)
        else:
            print("O cliente so pode ter 1 conta corrente!!!!")
            
            
    @property
    def contas_poupancas(self):
        return self._contas_poupancas
            
    def adicionar_conta_poupanca(self):
        if len(self.contas_poupancas) <1:
            b = ContaPoupanca(self.numero)
            self.contas_poupancas.append(b)        
        else:
            print("O cliente so pode ter 1 conta poupança!!!")        

    @property
    def nome(self):
        return self._nome
        
    @nome.setter
    def nome(self,nome):
        self._nome = nome
        
    @property
    def cpf(self):
        return self._cpf

    @cpf.setter
    def cpf(self,cpf):
        self._cpf = cpf    

    @property
    def numero(self):
        return self._numero

    @numero.setter
    def numero(self,numero):
        self._numero = numero
            
    @staticmethod
    def mostrar_dados_gerais():
        print(f"O banco possui atualmente {Cliente.proximo_id} clientes.\n")
        for titular in Cliente._clientes:
            t = len(titular.contas_correntes) + len(titular.contas_poupancas)
            t2 = len(titular.seguros_de_vida)
            print(f"O cliente de nome {titular.nome} tem {t} contas e {t2} seguros de vidas.\n")
            
                       
    def transferir(self, conta_destino, valor):
        
        try:

            if len(self.contas_correntes) == 0 and len(self.contas_poupancas) == 0:
                print("Cliente de origem sem contas!!!")
                input()
                return
                
            if len(self.contas_correntes) + len(self.contas_poupancas) == 2:
                op = int(input("O cliente em questão possui mais de uma conta, de qual deseja fazer a transferencia? (1-conta corrente/0-conta poupanca)"))
                if op == 1:
                    for conta in self.contas_correntes:
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            for conta in conta_destino:
                                conta.saldo += valor
                            self.Historico.transacoes.append('Transferencia de {} na conta corrente'.format(valor))
                        else:
                            print("Deposito insuficiente para tal transferencia!!!")
                            input()
                            return
                elif op == 0:
                    for conta in self.contas_poupancas:       
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            for conta in conta_destino:
                                conta.saldo += valor
                            self.Historico.transacoes.append('Transferencia de {} na conta poupança'.format(valor))
                        else:
                            print("Deposito insuficiente para tal transferencia!!!")
                            input()
                            return
                        
            else:
                if len(self.contas_correntes) == 0:
                    for conta in self.contas_poupancas:       
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            for conta in conta_destino:
                                conta.saldo += valor
                            self.Historico.transacoes.append('Transferencia de {} na conta popança'.format(valor))
                        else:
                            print("Deposito insuficiente para tal transferencia!!!")
                            input()
                            return
                else:
                    for conta in self.contas_correntes:
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            for conta in conta_destino:
                                conta.saldo += valor
                            self.Historico.transacoes.append('Transferencia de {} na conta corrente'.format(valor))
                        else:
                            print("Deposito insuficiente para tal transferencia!!!")
                            input()
                            return
        except:
            print("ERRO, VALORES INVALIDOS!!!")
            input()
            
    def depositar(self, valor):
        
            if valor < 0:
                print("valor negativo!!!!!")
                input()
                return

            if len(self.contas_correntes) == 0 and len(self.contas_poupancas) == 0:
                print("Cliente sem contas!!!")
                return
            
            if len(self.contas_correntes) + len(self.contas_poupancas) == 2:
                op = int(input("O cliente em questão possui mais de uma conta, em qual deseja depositar? (1-conta corrente/0-conta poupanca)"))
                if op == 1:                        
                    for conta in self.contas_correntes:
                        conta.saldo += valor
                        self.Historico.transacoes.append('deposito de {} na conta corrente'.format(valor))
                elif op == 0:
                    for conta in self.contas_poupancas:
                        conta.saldo += valor
                        self.Historico.transacoes.append('deposito de {} na conta poupanca'.format(valor))
            else:
                if len(self.contas_correntes) == 0:
                    for conta in self.contas_poupancas:
                        conta.saldo += valor
                        self.Historico.transacoes.append('deposito de {} na conta poupanca'.format(valor))
                else:
                    for conta in self.contas_correntes:
                        conta.saldo += valor
                        self.Historico.transacoes.append('deposito de {} na conta corrente'.format(valor))
        
    def sacar(self, valor):
        
        try:

            if valor < 0:
                print("nao é necessario por um valor negativo!!!!!")
                input()
                return

            if len(self.contas_correntes) == 0 and len(self.contas_poupancas) == 0:
                print("Cliente sem contas!!!")
                return
            
            if len(self.contas_correntes) + len(self.contas_poupancas) == 2:
                op = int(input("O cliente em questão possui mais de uma conta, em qual deseja sacar? (1-conta corrente/0-conta poupanca)"))
                if op == 1:                        
                    for conta in self.contas_correntes:
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            self.Historico.transacoes.append('Saque de {} na conta corrente'.format(valor))

                        else:
                            print("Deposito insuficiente para tal saque!!!")
                            input()
                            return
                            
                elif op == 0:
                    for conta in self.contas_poupancas:       
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            self.Historico.transacoes.append('Saque de {} na conta poupança'.format(valor))
                        else:
                            print("Deposito insuficiente para tal saque!!!")
                            input()
                            return
            else:
                if len(self.contas_correntes) == 0:
                    for conta in self.contas_poupancas:
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            self.Historico.transacoes.append('Saque de {} na conta poupança'.format(valor))
                        else:
                            print("Deposito insuficiente para tal saque!!!")
                            input()
                            return
                else:
                    for conta in self.contas_correntes:
                        if conta.saldo >= valor:
                            conta.saldo -= valor
                            self.Historico.transacoes.append('Saque de {} na conta corrente'.format(valor))
                        else:
                            print("Deposito insuficiente para tal saque!!!")
                            input()
                            return
    
        except:
            print("ERRO, VALORES INVALIDOS!!!")
            input()

    def mostrar_contas(self):
        if len(self.contas_correntes) == 0 and len(self.contas_poupancas) == 0:
            print("O cliente não possui contas")
        else:
            print(f"\n\n Contas de {self.nome}:")
            
            if len(self.contas_correntes) > 0:
                print("\nConta corrente:\n")
                for conta in self.contas_correntes:
                    print("--------------------")
                    print("Número da conta: ", conta.numero)
                    print("SALDO da conta: ",conta.saldo)
                    print("--------------------")
                
            if len(self.contas_poupancas) > 0:    
                print("\nConta poupança:\n")
                for conta in self.contas_poupancas:
                    print("--------------------")
                    print("Número da conta: ", conta.numero)
                    print("SALDO da conta: ",conta.saldo)
                    print("--------------------")
                    
            if len(self.seguros_de_vida) > 0:
                print("\nSeguros de vidas:")
                for seguro in self.seguros_de_vida:
                    print("--------------------")
                    print("Valor total: ", seguro.valor_total)
                    print("Valor mensal: ",seguro.valor_mensal)
                    print("--------------------")

    @staticmethod
    def cal_tributacao():
        T = 10
        for cliente in Cliente._clientes:
            for conta in cliente.contas_correntes:
                T += (1/100 * conta.saldo)
            for seguro in cliente.seguros_de_vida:
                T += (2/100 * seguro.valor_mensal)
        if len(Cliente._tributacoes) == 0:
            print(f"1 Tributação = {T}")
        else:
            Cliente._tributacoes.append(T)
            for i, quant in enumerate(Cliente._tributacoes, start=1):
                print(f"{i} Tributação = {quant}")
        Cliente._tributacoes.append(T)


            
# Criando o cliente Gabriel e me_mata
conta_gabriel = Cliente(123, 'Gabriel')
conta_dio_brando = Cliente(666,'Kono Dio da')
# Criando duas contas correntes associadas ao cliente 
# Tentando associar as contas correntes ao cliente 
conta_gabriel.adicionar_conta_corrente()
conta_gabriel.adicionar_conta_poupanca()
conta_gabriel.adicionar_seguro_de_vida()
conta_dio_brando.adicionar_conta_corrente()
conta_dio_brando.adicionar_conta_poupanca()
conta_dio_brando.adicionar_seguro_de_vida()
conta_gabriel.depositar(700)
conta_gabriel.sacar(300)
conta_gabriel.transferir(conta_dio_brando.contas_correntes,150)
conta_gabriel.mostrar_contas()
conta_dio_brando.mostrar_contas()
conta_gabriel.Historico.imprimir()
Cliente.mostrar_dados_gerais()
Cliente.cal_tributacao()
Cliente.cal_tributacao()