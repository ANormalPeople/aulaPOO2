def f(n):
    r = 1
    for i in range(1, n + 1):
        r *= i
    return r


try:
    N = int(input(''))
    P = int(input(''))

    Ra = f(N) / f(N-P)
    Rc = f(N) / (f(P)*f(N-P))
    print("Arranjo: ",Ra,'\nCombinação: ',Rc)

except:
    print('é necessario um valor inteiro')