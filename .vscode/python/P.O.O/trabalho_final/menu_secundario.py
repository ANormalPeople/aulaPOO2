import menu_principal
import biblioteca 

class Main_secundario:
    
    def __init__(self,conta,nivel_acesso,bibli):
        if  nivel_acesso == "USER":
            menu_principal.limpa("entrando como usuário!")
            while True:            
                print("LIGHT NOVEL WORLD")
                print("1 - Top 10")
                print("2 - Livros")
                print("3 - Favoritos")
                print("4 - voltar")
                u = menu_principal.valida(1,4)

                if u == 1:
                    biblioteca.Biblioteca.cal_top_10(bibli)
                if u == 2:
                    biblioteca.Biblioteca.mostrar_livros(bibli)
                    a = input("Caso queira buscar um livro digete 'S': ")
                    if a in ["S","s"]:
                        biblioteca.Biblioteca.buscar_nome(bibli)
                    menu_principal.limpa("",0.25)
                if u == 3:
                    menu_principal.limpa("",0.25)
                    print("1- Ver seus favoritos")
                    print("2- Adicionar um livro aos seus favoritos")
                    print("3- Remover um livros dos seus favoritos")
                    r = menu_principal.valida(1,3)
                    if r == 1:
                        menu_principal.limpa("",0.25)
                        print("-------Favoritos----------")
                        for favoritos in conta.favoritos:
                            print("Nome: ",favoritos.nome)
                            print("Capitulos: ",favoritos.capitulos)
                            print("Número de favoritos: ",favoritos.favoritos_Total)
                            print("ID: ",favoritos.idn,"\n\n")
                        print("--------------------------")
                        input()
                        menu_principal.limpa("",0.25)
                    elif r == 2:             
                        Passo = True               
                        favorito = biblioteca.Biblioteca.buscar_id(bibli)
                        
                        if favorito != False:
                            for favoritinhos in conta.favoritos:
                                if favorito.idn == favoritinhos.idn:
                                    menu_principal.limpa("Não é possivel favoritar o mesmo livro 2 vezes!!!")
                                    Passo = False
                            
                        if Passo == True and favorito != False:
                            conta.favoritos.append(favorito)
                            favorito.favoritos_Total += 1
                            menu_principal.limpa("Sucesso!!!")
                    
                    elif r == 3:
                        
                        removendo = biblioteca.Biblioteca.buscar_id(bibli)    
                        if removendo != False:
                            for remover in conta.favoritos:
                                if removendo.idn == remover.idn:
                                    conta.favoritos.remove(remover)
                                    favorito.favoritos_Total -= 1
                                    menu_principal.limpa("Sucesso!!!")
                                    
                        else: 
                            menu_principal.limpa("Livro não encontrado!!!!")

                if u == 4:
                    menu_principal.limpa("",0.25)
                    break

        elif nivel_acesso == "ADM":
            menu_principal.limpa("entrando como administrador!")
            while True:
                print("LIGHT NOVEL WORLD")
                print("1 - Top 10")
                print("2 - Livros")
                print("3 - Adicionar livro")
                print("4 - Remover livro")
                print("5 - editar livro")
                print("6 - voltar")
                u2 = menu_principal.valida (1,6)
                
                if u2 == 1:
                    biblioteca.Biblioteca.cal_top_10(bibli)
                if u2 == 2:
                    biblioteca.Biblioteca.mostrar_livros(bibli)
                    a = input("Caso queira buscar um livro digete 'S': ")
                    if a in ["S","s"]:
                        biblioteca.Biblioteca.buscar_nome(bibli)
                    menu_principal.limpa("",0.25)
                if u2 == 3:
                    biblioteca.Biblioteca.adicionar_livro(bibli)
                if u2 == 4:
                    biblioteca.Biblioteca.remover(bibli)
                if u2 == 5:
                    biblioteca.Biblioteca.editar(bibli)
                if u2 == 6:
                    menu_principal.limpa("",0.25)
                    break
                

