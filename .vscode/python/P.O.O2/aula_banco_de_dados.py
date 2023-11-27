import mysql.connector as mysql

try:
    conect = mysql.connect(host='localhost', user='root', password='Ripanlong807!')
    cursor = conect.cursor()

    cursor.execute("CREATE DATABASE IF NOT EXISTS poo2")
    
    conect = mysql.connect(host='localhost', database='poo2', user='root', password='Ripanlong807!')
    cursor = conect.cursor()

    sql = """CREATE TABLE IF NOT EXISTS usuarios(id integer PRIMARY KEY AUTO_INCREMENT, nome text NOT NULL, email text NOT NULL); """
    
    cursor.execute(sql)

    nome = input("Diga seu nome: ")
    email = input("Diga seu email: ")

    cursor.execute('INSERT INTO usuarios (nome, email) VALUES (%s, %s)', (nome, email))
    print(f'Foram inseridas {cursor.rowcount} linhas')

    # Exibindo os dados inseridos
    cursor.execute('SELECT * from usuarios')
    for c in cursor:
        print(c)
    
    conect.commit()

    # BUSCAR
    nome_buscar = input("Diga o nome: ")
    cursor.execute('SELECT * from usuarios where nome = %s', (nome_buscar,))
    
    for result in cursor:
        print(result)
    
    conect.commit()
    
except mysql.Error as e:
    print(f"Ocorreu um erro: {e}")
finally:
    if conect:
        conect.close()
