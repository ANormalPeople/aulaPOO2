import mysql.connector as mysql

class Cadastro:
    
    def __init__(self):
        pass
        
    def cadastra(self,pessoa):        
        conect = mysql.connect(host='localhost', user='root', password='Ripanlong807!')
        cursor = conect.cursor()
        cursor.execute("CREATE DATABASE IF NOT EXISTS poo2")   
        conect = mysql.connect(host='localhost', database='poo2', user='root', password='Ripanlong807!')
        cursor = conect.cursor()
        
        sql = """CREATE TABLE IF NOT EXISTS pessoa(id integer PRIMARY KEY AUTO_INCREMENT, nome text NOT NULL, endereco text NOT NULL, cpf int NOT NULL, nascimento int NOT null); """

        cursor.execute(sql)

        nome = pessoa.nome
        endereco = pessoa.endereco
        cpf = pessoa.cpf
        nascimento = pessoa.nascimento
        existe1 = self.busca_servico(pessoa.cpf)
        if(existe1==None):
         
            cursor.execute('INSERT INTO pessoa (nome, endereco, cpf, nascimento) VALUES (%s, %s, %s, %s)', (nome, endereco, cpf, nascimento))
            print(f'Foram inseridas {cursor.rowcount} linhas')
            conect.commit()

        
        if(existe1==None):
            return True
        else:
            return False
        
    def busca_servico(self,cpf):
        
        # Conectando ao banco de dados
        conect = mysql.connect(host='localhost', database='poo2', user='root', password='Ripanlong807!')
        cursor = conect.cursor()

        # Executando a consulta
        cursor.execute("SELECT * FROM pessoa WHERE cpf  = %s",(cpf,))

        # Obtendo os resultados
        resultados = cursor.fetchall()

        conect.close()
        
        if resultados == []:
            return None
        else:
            return resultados
        