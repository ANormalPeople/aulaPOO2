import socket
ip =  'localhost'
port = 8011
addr = ((ip,port))
cliente_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cliente_socket.connect(addr)

while(True):
    try:
        mensagem = input("Diga uma mensagem para enviar ao servidor: ")
        cliente_socket.send(mensagem.encode())  
        if mensagem == 'bye':
            break
        print('mensagem enviada')  
        
    except:
        cliente_socket.close()
        

        