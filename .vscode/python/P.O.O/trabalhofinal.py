import abc

class Conta:
    def __init__(self, nome, senha, nivel_acesso):
        self._nome = nome
        self._senha = senha
        self._nivel_acesso = nivel_acesso
            
    @property
    def nome(self):
        return self._nome

    @property
    def senha(self):
        return self._senha

    @property
    def nivel_acesso(self):
        return self._nivel_acesso

    @nivel_acesso.setter
    def nivel_acesso(self, nivel_acesso):
        self._nivel_acesso = nivel_acesso

    def autenticacao(self, senha_digitada):
        return senha_digitada == self._senha
    
    
class Autenticavel(abc.ABC):
    @abc.abstractmethod
    def autenticacao(self, senha):
        pass

class SistemaLogin:
    def login(self, obj,senha):
        if isinstance(obj, Autenticavel):
            if obj.autenticacao(senha):
                print("Login realizado com sucesso!")
                return True
            else:
                return False
        else:
            print("Objeto não autenticável")
            return False


class main:

    _usuarios = []    

    def __init__(self):
        
        print("         BEM-VINDO À LIGHT NOVEL WORLD                 ")
        print("1-logar")
        print("2-logar")
        while True:
            try:
                r = int(input(""))
            except:
                print("valor invalido!!")
                
        Autenticavel.register(Conta)
        

class Menu:
    
    _usuarios = []    

    def __init__(self):
        print("BEM-VINDO À LIGHT NOVEL WORLD")
        input("Pressione Enter para continuar...")
        Autenticavel.register(Conta)
        
    def adicionar_usuarios(self):
        self._usuarios.append(Conta("gabriel", "321", "User"))
    
    def adicionar_adms(self):
        self._usuarios.append(Conta("calos", "123", "Adm"))

    def main(self):
        Sl = SistemaLogin()

        self.adicionar_usuarios()
        self.adicionar_adms()

        senha = input("diga a senha: ")

        for conta in Menu._usuarios:
            if Sl.login(conta,senha):
                if conta.nivel_acesso == "User":
                    print("Login realizado com sucesso como usuário!")
                    print("LIGHT NOVEL WORLD")
                    print("1 - Top 10")
                    print("2 - Livros")
                    print("3 - Favoritos")

                elif conta.nivel_acesso == "Adm":
                    print("Login realizado com sucesso como administrador!")
                    print("LIGHT NOVEL WORLD")
                    print("1 - Top 10")
                    print("2 - Livros")
                    print("3 - Adicionar livro")
                    print("4 - Remover livro")
                return

if __name__ == "__main__":
    menu = Menu()
    menu.main()

# class main():
#     _num_livros = 0
    
#     def __init__(self):        
#         self._livros = []
#         self.usuarios = []
#     @property
#     def livros(self):
#         return self._livros
    
#     @livros.setter
#     def livros(self,livros):
#         self._livros = livros
    
#     @property
#     def num_livros(self):
#         return self._num_livros
    
#     @num_livros.setter
#     def num_livros(self,num_livros):
#         self._num_livros = num_livros
    
#     def adicionar_livro(self):
#         try:
#             nome = input("Diga o nome do livro: ")
#             capitulos = int(input("Diga a quantidade de capitulos iniciais"))
            
#             self.livros.append(livro(nome,capitulos,self.num_livros))
#             self.num_livros += 1        
#             print("operação finalizada!!!")        
#         except:
#             print("ERRO!!")
    
#     def top_10(self):
#         pass    

#     def livros(self):
#         pass


# class livro():
    
#     def __init__(self,nome,capitulos,idn,estado='on-going'):
#         self._nome = nome
#         self._capitulos = capitulos
#         self._vizualizacoes = 0
#         self._id = idn
#         self._estado = estado
        
#     def fim_livro(self):
#         try:
#             r = input(("Deseja declarar o livro como finalizado?(S/N) "))
#             if r in ['S','s']:
#                 self._estado = 'completed'
#                 print('Operação finalizada!!!')
#                 input()
            
#         except:
            
#             print("opição invalida!!!")