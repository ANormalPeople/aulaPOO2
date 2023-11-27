import mysql.connector
from random import randint, choice
from datetime import datetime, timedelta

def consultas():
  
    conn =  mysql.connector.connect(host='localhost', database='mydb',user='root',password='Ripanlong807!')
    c = conn.cursor()

    print("Escolha a opção a qual deseja fazer a consulta SQL:")
    print("1. - Conta e saldo de todos os clientes no sistema em ordem decrescente de saldo.")
    print("2. - Os clientes com o menor e maior saldo atual. ")
    print("3. - Os clientes com o menor e maior saldo em um intervalo de tempo (dia) inicial e final informados.")
    print("4. - O saldo atual de uma conta específica informada")
    print("5. - O saldo de uma conta específica em um intervalo de tempo (dia) inicial e final informados")
    escolha = int(input())

    if escolha == 1:
        c.execute(''' 
            SELECT conta.id_conta as Conta, conta.saldo_inicial_conta
            FROM cliente
            JOIN conta ON cliente.id_numeroconta_cliente = conta.cliente_id_numeroconta_cliente
            ORDER BY conta.saldo_inicial_conta DESC;
        ''')
    elif escolha == 2:
        c.execute(''' 
            SELECT co.id_conta, co.saldo_inicial_conta
            FROM cliente c
            JOIN conta co ON c.id_numeroconta_cliente = co.cliente_id_numeroconta_cliente
            WHERE co.saldo_inicial_conta = (SELECT MIN(saldo_inicial_conta) FROM conta)
               OR co.saldo_inicial_conta = (SELECT MAX(saldo_inicial_conta) FROM conta);
        ''')
    elif escolha == 3:
        data_inicio = input("Digite a data de início (AAAA-MM-DD): ")
        data_fim = input("Digite a data de fim (AAAA-MM-DD): ")
        c.execute(''' 
            SELECT co.id_conta, co.saldo_inicial_conta
            FROM cliente c
            JOIN conta co ON c.id_numeroconta_cliente = co.cliente_id
            WHERE co.saldo_inicial_conta IN (
                SELECT MIN(saldo_inicial_conta)
                FROM conta
                JOIN operacao op ON conta.id_conta = op.conta_id_conta
                WHERE op.tempo_operacao >= %s AND op.tempo_operacao < %s
            )
            OR co.saldo_inicial_conta IN (
                SELECT MAX(saldo_inicial_conta)
                FROM conta
                JOIN operacao op ON conta.id_conta = op.conta_id_conta
                WHERE op.tempo_operacao >= %s AND op.tempo_operacao < %s
            );
        ''', (data_inicio, data_fim, data_inicio, data_fim))

    elif escolha == 4:
        id_conta = int(input("Digite o ID da conta: "))
        c.execute(f"SELECT saldo_inicial_conta FROM conta WHERE id_conta = {id_conta};")
    
    elif escolha == 5:
        id_conta = int(input("Digite o ID da conta: "))
        data_operacao = input("Digite a data da operação (AAAA-MM-DD): ")
        c.execute(f'''
            SELECT co.saldo_inicial_conta
            FROM conta co
            WHERE co.id_conta = {id_conta}
              AND EXISTS (
                SELECT 1
                FROM operacao op
                WHERE op.conta_id_conta = co.id_conta
                  AND op.tempo_operacao >= %s
                  AND op.tempo_operacao < %s
              );
        ''', (data_operacao, data_operacao))
    
    else:
        print("Opção inválida")

    resultados = c.fetchall()

    if resultados:
        for linha in resultados:
            print(linha)
    else:
        print("Nenhum resultado encontrado")

OP = True

while OP:
  escolha = (input('\n1 - Criar banco de dados e tabelas \n2 - Popular banco de dados. \n3 - Executar consulta a-f com parâmetros separados por espaço na ordem letra conta dia1 dia2 (preencher com zero parâmetros não utilizados). \n4 - Finalizar a aplicação (sair da aplicação apenas se informada essa opção)\nInforme a opção desejada:'))

  if escolha == "1":

    conect = mysql.connector.connect(host='localhost', user='root', password='Ripanlong807!')
    cursor = conect.cursor()

    # Criar o banco de dados
    cursor.execute("CREATE DATABASE IF NOT EXISTS mydb")

    # Conectar-se ao banco de dados criado
    conect = mysql.connector.connect(host='localhost', database='mydb', user='root', password='Ripanlong807!')
    cursor = conect.cursor()

    # Definição das tabelas
    TABLES = {}

    TABLES['cliente'] = (
      "CREATE TABLE IF NOT EXISTS cliente ("
      "id_numeroconta_cliente INT NOT NULL AUTO_INCREMENT,"
      "renda_cliente FLOAT NOT NULL,"
      "PRIMARY KEY (id_numeroconta_cliente)"
      ") ENGINE = InnoDB;"
    )

    TABLES['conta'] = (
    "CREATE TABLE IF NOT EXISTS conta ("
    "id_conta INT AUTO_INCREMENT PRIMARY KEY,"
    "saldo_inicial_conta FLOAT NOT NULL,"
    "cliente_id_numeroconta_cliente INT NOT NULL,"
    "FOREIGN KEY (cliente_id_numeroconta_cliente) "
    "REFERENCES cliente (id_numeroconta_cliente)"
    ") ENGINE = InnoDB;"
)

    TABLES['operacao'] = (
    "CREATE TABLE IF NOT EXISTS operacao ("
    "id_operacao INT NOT NULL AUTO_INCREMENT,"
    
   
"tipo_operacao VARCHAR(45) NOT NULL COMMENT 'debito ou credito',"
    "valor_operacao FLOAT NOT NULL,"
    "tempo_operacao DATETIME NOT NULL,"
    "conta_id_conta INT,"
    "PRIMARY KEY (id_operacao),"
    "FOREIGN KEY (conta_id_conta) REFERENCES conta (id_conta)"
    ") ENGINE = InnoDB;"
)
    # Criar o banco de dados e tabelas
    for table_name, table_definition in TABLES.items():
      cursor.execute(table_definition)

    # Fechar a conexão
    cursor.close()
    conect.close()
    
  elif escolha == "2":
    from random import randint, choice
    from datetime import datetime, timedelta

       # Conectar ao banco de dados
    conect = mysql.connector.connect(host='localhost', database='mydb', user='root', password='Ripanlong807!')
    cursor = conect.cursor()

    # Popular o banco de dados
    for _ in range(1000):
        # Criar um cliente com renda aleatória
        renda_cliente = randint(1000, 10000)
        cursor.execute("INSERT INTO cliente (renda_cliente) VALUES (%s)", (renda_cliente,))
        id_cliente = cursor.lastrowid  # Obter o ID do cliente recém-criado

        # Criar uma conta com saldo inicial aleatório
        saldo_inicial_conta = randint(1000, 10000)
        cursor.execute("INSERT INTO conta (saldo_inicial_conta, cliente_id_numeroconta_cliente) VALUES (%s, %s)",
                       (float(saldo_inicial_conta), id_cliente))
        id_conta = cursor.lastrowid  # Obter o ID da conta recém-criada

        for _ in range(100):
            # Gerar operações aleatórias (crédito ou débito)
            tipo = choice(['credito', 'debito'])
            valor = round(randint(1, 100) * 10, 2)  # Valor entre 10 e 1000 com duas casas decimais
            data = datetime.now() - timedelta(days=randint(1, 365))

            # Verificar se débito é válido (não permitir saldo negativo)
            if tipo == 'debito' and valor > saldo_inicial_conta:
                continue  # Ignorar esta operação de débito inválida

            # Registrar a operação no banco de dados
            cursor.execute("INSERT INTO operacao (conta_id_conta, tipo_operacao, valor_operacao, tempo_operacao) VALUES (%s, %s, %s, %s)",
                           (id_conta, tipo, float(valor), data))

            # Atualizar o saldo da conta
            if tipo == 'credito':
                saldo_inicial_conta += valor
            else:
                saldo_inicial_conta -= valor

    # Commit e fechar conexão
    conect.commit()
    conect.close()


  elif escolha == "3":
    consultas()
  elif escolha == "4":
      OP = False
  else:
    print("Opção inválida. Tente novamente.")