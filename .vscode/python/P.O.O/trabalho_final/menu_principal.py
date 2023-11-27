from os import system
from time import sleep
import abc
import menu_secundario
import biblioteca

def limpa(p,tempo = 0.75):
    system("cls")
    print(p)
    sleep(tempo)
    system("cls")

def valida(min,max):
    while True:
        try:
            r = int(input(""))
            if r >= min and r <= max:
                break
            else:
                print("valor invalido!!")
        except:
            print("valor invalido!!")
    return r

class Conta:

    def __init__(self, nome, senha, nivel_acesso):
        self._nome = nome
        self._senha = senha
        self._nivel_acesso = nivel_acesso
        self._favoritos = []
        
        if nivel_acesso == "ADM":
            del self._favoritos
            
    @property
    def nome(self):
        return self._nome

    @property
    def senha(self):
        return self._senha

    @property
    def favoritos(self):
        return self._favoritos

    @favoritos.setter
    def favoritos(self,favoritos):
        self._favoritos = favoritos

    @property
    def nivel_acesso(self):
        return self._nivel_acesso

    @nivel_acesso.setter
    def nivel_acesso(self, nivel_acesso):
        self._nivel_acesso = nivel_acesso

    def autenticacao(self, nome,  senha):
        return nome == self._nome and senha == self._senha 

class SistemaLogin:
    def login(self,obj,nome,senha):
        if isinstance(obj, Autenticavel):
            if obj.autenticacao(nome, senha):
                limpa("Login realizado com sucesso!")
                return True, obj.nivel_acesso
            else:
                return False,False
        else:
            limpa("Objeto não autenticável")
            return False,False
        
class Autenticavel(abc.ABC):
    @abc.abstractmethod
    def autenticacao(self, senha):
        pass

class Main:

    _usuarios = []    
    Autenticavel.register(Conta)

    def __init__(self):
        pass
        
    def menuzin(self,bibli):
        while True:
            print("         BEM-VINDO À LIGHT NOVEL WORLD                 ")
            print("0-finalizar")
            print("1-registrar")
            print("2-logar")
            r = valida(0,2)
            if r == 0:
                break
            elif r == 1:
                val = True
                limpa("",0.25)
                nome = input("diga o nome: ")
                senha = input("diga a sua senha: ")
                for conta in self._usuarios:
                    if conta.nome == nome:
                        limpa("Indentificador ja utilizado!!!")
                        val = False
                if val == True:
                    limpa("",0.25)
                    print("\n Agora escolha entre criar um usuario ou um adimin")
                    print("1-admin")
                    print("2-user")                                
                    a = valida(1,2)
                    if a == 1:
                        self._usuarios.append(Conta(nome,senha,'ADM'))
                        limpa("SUCESSO!!!")                        
                    else:
                        self._usuarios.append(Conta(nome,senha,'USER'))                    
                        limpa("SUCESSO!!!")
            elif r == 2:
                limpa("",0.25)
                nome = input("diga o nome: ")
                senha = input("diga a sua senha: ")

                ver = False

                Sl = SistemaLogin()                    
                for a in self._usuarios:
                    ver,valor = Sl.login(a,nome, senha)
                    if ver:
                        conta_logada = a                   
                        menu_secundario.Main_secundario(conta_logada,valor,bibli)
                        break
                if ver == False:
                    limpa("usuario não encontrado!!")

if __name__ == "__main__":
    bibliotecaM = biblioteca.Biblioteca()
    menu = Main()
    menu.menuzin(bibliotecaM)
    