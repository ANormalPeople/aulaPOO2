import random

def jogo():
    x = random.randint(0, 100)
    for i in range(0, 10):
        r = int(input('Escreva um número: '))
        print((i + 1), "ª tentativa")
        if r == x:
            print("Acertou!!!")
            return True
    
    print('Sem mais tentativas')
    return False

def main():
    continuar = True
    while continuar:
        if jogo():
            print('Você ganhou!')
        else:
            print('Você perdeu!')
        
        resposta = input("Deseja continuar? (s/n): ")
        if resposta not in ['s','S']:
            continuar = False
main()