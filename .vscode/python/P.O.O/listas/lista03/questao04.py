class Televisao():
    
    def __init__(self,):
        while True:
            canais = int(input("Diga a quantidade de canais que a televisão tera: "))
            volume = int(input("Informe o volume maximo: "))
            if canais >= 0 and volume >= 0:
                break
            else:
                print("valores invalidos")
    
        self.volume = 0 
        self.canal = 0
        self.canalmax = canais
        self.volumemax = volume

class ControleRemoto():
    
    def __init__(self,televisao):
        self.televisao = televisao
        self.menu()

    def aumentar(self):
        if self.televisao.volume < self.televisao.volumemax:
            self.televisao.volume += 1
        else:
            print("MAX")                
        
    def diminuir(self):
        if  self.televisao.volume > 0:
            self.televisao.volume -= 1
        else:
            print("MIN")
            
    def passarcanal(self):
        if self.televisao.canal < self.televisao.canalmax:
            self.televisao.canal += 1
        else:
            print("MAX")
        
    def voltarcanal(self):
        if self.televisao.canal > 0:
            self.televisao.canal -= 1
        else:
            print("MIN")        

    def escolhercanal(self):
        c = int(input("informe o canal: "))
        if c <= self.televisao.canalmax and c >= 0: 
            self.televisao.canal = c
        else:
            print("canal inexistente")

    def consultar_som(self):
        print("Volume atual:",self.televisao.volume)
        
    def consultar_canal(self):
        print("Canal atual:",self.televisao.canal)

    def menu(self):
            r = 0
            print("Ações possiveis para a TV:")
            print("----------------------------------------------")
            print("|          1 aumentar o volume               |")
            print("|          2 diminuir o volume               |")
            print("|          3 passar de canal                 |")
            print("|          4 voltar de canal                 |")
            print("|          5 escolher um canal               |")
            print("|          6 ver o volume atual              |")
            print("|          7 ver o canal atual               |")
            print("|          8 finalizar o progama             |")
            print("----------------------------------------------")            
            while r != 8:
                r = int(input(""))
                if r == 1:
                    self.aumentar()
                if r == 2:
                    self.diminuir()
                if r == 3:
                    self.passarcanal()
                if r == 4:
                    self.voltarcanal()
                if r == 5:
                    self.escolhercanal()
                if r == 6:
                    self.consultar_som()
                if r == 7:
                    self.consultar_canal()

tv = Televisao()
Controle = ControleRemoto(tv)
