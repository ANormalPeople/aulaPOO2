import menu_principal

class livro():
    
    def __init__(self,nome,capitulos,idn):
        self._nome = nome
        self._capitulos = capitulos
        self._favoritos_Total = 0
        self._idn = idn

    @property
    def nome(self):
        return self._nome
    
    @nome.setter
    def nome(self,nome):
        self._nome = nome    

    @property
    def capitulos(self):
        return self._capitulos
    
    @capitulos.setter
    def capitulos(self,capitulos):
        self._capitulos = capitulos

    @property
    def favoritos_Total(self):
        return self._favoritos_Total
    
    @favoritos_Total.setter
    def favoritos_Total(self,favoritos_Total):
        self._favoritos_Total = favoritos_Total

    @property
    def idn(self):
        return self._idn
    
    @idn.setter
    def idn(self,idn):
        self._idn = idn    

class Biblioteca():
    _num_livros = 0
    
    def __init__(self):        
        self._livros = []
        self._top10 = []

    @property
    def top10(self):
        return self._top10
    
    @top10.setter
    def top10(self,top10):
        self._top10 = top10

    @property
    def livros(self):
        return self._livros
    
    @livros.setter
    def livros(self,livros):
        self._livros = livros
    
    @property
    def num_livros(self):
        return self._num_livros
    
    @num_livros.setter
    def num_livros(self,num_livros):
        self._num_livros = num_livros
        
    def mostrar_livros(self):
        menu_principal.limpa("",0.25)
        print("LISTA DE LIVROS:")
        print("-----------------------")
        for livro in self.livros:
            print("Nome: ",livro.nome)
            print("Capitulos totais: ",livro.capitulos)
            print("Numero de Favoritos: ",livro.favoritos_Total)
            print("Id: ",livro.idn,"\n\n")
        print("-----------------------")
    
    def adicionar_livro(self):
        try:
            menu_principal.limpa("",0.25)
            nome = input("Diga o nome do livro: ")
            print("Diga a quantidade de capitulos: ", end = "")
            capitulos = menu_principal.valida(0,999999)
            self._livros.append(livro(nome,capitulos,self.num_livros))
            self.num_livros += 1        
            menu_principal.limpa("operação finalizada!!!")        
        except:
                 print("ERRO, VALORES INVALIDOS!!")
        menu_principal.limpa("",0.25)

    
    def cal_top_10(self):
        menu_principal.limpa("",0.25)    
        self._top10 = sorted(self.livros, key=lambda x: x.favoritos_Total, reverse=True)[:10]
        print("-------Top-10----------")
        for i, obj in enumerate(self._top10, start=1):
            print(f"{i}° lugar: {obj.nome}")
        print("-----------------------")
        input()
        menu_principal.limpa("",0.25)
        
    def remover(self):
        menu_principal.limpa("",0.25)
        print("diga o valor que id do livro remover:", end=" ")
        id_remover = menu_principal.valida(0,999999)
        for livro in self.livros:
            if id_remover == livro.idn:
                self.livros.remove(livro)
                menu_principal.limpa("Operação finalizada!!!")
                return
        menu_principal.limpa("Livro não encontrado!!!")
        
    def buscar_nome(self):
        menu_principal.limpa("",0.25)
        nome = input("Diga um nome para a busca: ")
        T = False
        for livro in self._livros:
            if nome == livro.nome:
                    print("-----------------------")
                    print("Nome: ",livro.nome)
                    print("Capitulos totais: ",livro.capitulos)
                    print("Numero de vizualizações: ",livro.favoritos_Total)
                    print("Id: ",livro.idn,"\n\n")
                    print("-----------------------")
                    T = True
                    input()
        if T == False:
            menu_principal.limpa("Sem dados referentes a pesquisa!!!")            
    
    def buscar_id(self):
        menu_principal.limpa("",0.25)
        print("Diga um id para a busca(possível ver na opção livros):", end=" ")
        idn = menu_principal.valida(0, 999999)
        for livro in self._livros:
            if idn == livro.idn:
                return livro
        menu_principal.limpa("Livro não encontrado!!")
        return False
    
    def editar(self):
        menu_principal.limpa("",0.25)
        print("Diga o id da novel que deseja modificar(possível ver na opção livros):", end=" ")
        idn = menu_principal.valida(0,999999)
        for livro in self._livros:
            if idn == livro.idn:
                menu_principal.limpa("livro encontrado!!!")
                print("Você deseja modificar o nome(1) ou os capitulos(2)?")
                escolha = menu_principal.valida(1,2)
                if escolha == 1:
                    novo = input("Diga o novo nome: ")
                    livro.nome = novo
                elif escolha == 2:
                    print("Diga a nova quantidade de capitulos:", end=" ")
                    novo = menu_principal.valida(0,999999)
                    livro.capitulos = novo
                menu_principal.limpa("Sucesso!!!!")
                return
        menu_principal.limpa("Livro não encontrado!!!")