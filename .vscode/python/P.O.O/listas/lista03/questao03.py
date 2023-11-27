class elevador():
    
    def __init__(self,total_de_andares,capacidade):
        self._andar_atual = 0
        self._total_de_andares = total_de_andares
        self._capacidade = capacidade
        self._quant_pessoas = 0
        self.menu()
    
    @property
    def andar_atual(self):
        return self._andar_atual
    
    @andar_atual.setter
    def andar_atual(self,andar_atual):
        self._andar_atual = andar_atual
        
    @property
    def total_de_andares(self):
        return self._total_de_andares
    
    @total_de_andares.setter
    def total_de_andares(self,total_de_andares):
        self._total_de_andares = total_de_andares
        
    @property
    def capacidade(self):
        return self._capacidade
    
    @capacidade.setter
    def capacidade(self,capacidade):
        self._capacidade = capacidade
      
    @property
    def quant_pessoas(self):
        return self._quant_pessoas
    
    @quant_pessoas.setter
    def quant_pessoas(self,quant_pessoas):
        self._quant_pessoas = quant_pessoas  
    
    def entra(self):
        if self.quant_pessoas < self.capacidade:
            self.quant_pessoas += 1
        else:
            print("\nNumero maximo atingido!!!!!")
            
    def sai(self):
        if self.quant_pessoas != 0:
            self.quant_pessoas -= 1
        else:
            print("\nelevador ja esta vazio") 
            
    def sobe(self):
        if self.andar_atual < self.total_de_andares:
            self.andar_atual += 1
        else:
            print("\nNumero maximo atingido!!!!!")
            
    def desce(self):
        if self.andar_atual > 1:
            self.andar_atual -= 1
        else:
            print("\nelevador ja esta no terrio")
    
    def menu(self):
        r = 0
        print("Bem vindo ao elevador, que ação deseja tomar?")
        print("----------------------------------------------")
        print("|          1 para entrar alguem              |")
        print("|          2 para sair alguem                |")
        print("|             3 para subir                   |")
        print("|             4 para descer                  |")
        print("|             5 para finalizar               |")
        print("----------------------------------------------")            
        while r != 5:
            print("Andar atual: ",self.andar_atual,"|",self.total_de_andares)
            print("Capacidade atual: ",self.quant_pessoas,"|",self.capacidade)
            r = int(input(""))
            if r == 1:
                self.entra()
            if r == 2:
                self.sai()
            if r == 3:
                self.sobe()
            if r == 4:
                self.desce()
                
elevador1 = elevador(10,15)