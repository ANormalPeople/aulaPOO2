class Pessoa:
    __slot__ = ['nome','endereco','cpf','nascimento']
    
    def __init__(self, nome, endereco, cpf, nascimento):
        self.nome = nome
        self.endereco = endereco
        self.cpf = cpf
        self.nascimento = nascimento