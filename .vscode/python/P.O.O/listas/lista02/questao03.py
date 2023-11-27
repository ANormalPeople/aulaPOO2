def encontra(a,b):
    i = 0
    for c in a.lower():
        if c == b.lower():
            print(i)
        i += 1
            
            
o = 'ola'
rep = encontra(o, 'a')
