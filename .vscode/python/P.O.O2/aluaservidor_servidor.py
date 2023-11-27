import socket
import threading

def server(con, addr):
    
    print(f"Cliente {addr[1]} se conectou")

    x = True

    while x:
        try:
            recebe = con.recv(1024)
            if recebe.decode() == 'bye' or recebe.decode() == '' or recebe.decode() == None:
                print(f"{addr[1]} desconectado")
                x = False
            elif x:
                print(f'Mensagem recebida de {addr[1]}: {recebe.decode()}')
        except Exception as e:
            print(f"Erro na comunicação com {addr[1]}: {e}")
            break
        
    con.close()

def main():
    host = ''
    port = 8011
    addr = (host, port)
    serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    serv_socket.bind(addr)
    serv_socket.listen(10)
    print('Aguardando conexões...')

    while True:
        con, cliente = serv_socket.accept()
        client_thread = threading.Thread(target=server, args=(con, cliente))
        client_thread.start()

if __name__ == "__main__":
    main()