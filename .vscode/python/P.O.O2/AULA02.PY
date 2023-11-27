# # #Criar o botao sair na primeira tela
# # #Criar o botao voltar na segunda tela
# # # $pyuic5 -x nome.ui -o tela.py

# class cadastro:
    
#     __slot__ = ['_lista_pessoas']

#     def __init__(self):
#         self._lista_pessoas = []
        
#     def cadastra(self,pessoa):
#         existe = self.busca(pessoa.cpf)
#         if(existe==None):
#             self.lista_pessoas.append(pessoa)
#             return True
#         else:
#             return False
        
#     def busca(self,cpf):
#         for lp in self._lista_pessoas:
#             if lp.cpf == cpf:
#                 return lp
#         return None
    
# # class pessoa:
# #     __slot__ = ['Nome','cpf']