def fatorialiterativo(n):
    r = 1
    for i in range(1, n + 1):
        r *= i
    return r

def fatorialrecursivo(n):
    if n == 0:
        return 1
    else:
        return n * fatorialrecursivo(n - 1)
    
"""fatorial(5)
  -> 5 * fatorial(4)
       -> 4 * fatorial(3)
            -> 3 * fatorial(2)
                 -> 2 * fatorial(1)
                      -> 1 * fatorial(0)
                           -> return 1
                      -> return 1 * 1 = 1
                 -> return 2 * 1 = 2
            -> return 3 * 2 = 6
       -> return 4 * 6 = 24
  -> return 5 * 24 = 120"""

try:
    P = int(input(''))
    print(fatorialiterativo(P))
    print(fatorialrecursivo(P))
    
except:
    print('é necessario um valor inteiro')