def primo(n):
    if n != 1:
        count = 0
        for i in range(2,n):
            if n % i == 0:
                count += 1
        if count == 0:
            return True
        else:
            return False
    else:
        return False
"n // 2 + 1 e int(n ** 0.5) + 1 otimizariam o calculo"
        
try:
    num = int(input(''))
    num2 = int(input(''))
    if num < 0 or num2 < 0:
        raise
    count = 0
    if num2 < num:
        aux = num2
        num2 = num
        num = aux
    for i in range(num+1 ,num2+1):
        if primo(i) == True:
            print(i)
            count+= 1
    if count == 0:
        print('Não existe nenhum número primo dentro desse intervalo')   
except:
    print('permitidos somente números inteiros e positivos')