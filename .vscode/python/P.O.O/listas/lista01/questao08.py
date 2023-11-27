i = 5.0
q = 120
l = q * i - 200
lmax = 0
imin = i    
qmin = q

while i >= 1.0:
    print('preço do ingreço =',i,', quantidade =',q,'lucro =',l)
    i -= 0.5
    q += 26
    l = q * i - 200
    
    if lmax < l:
        lmax = l
        imin = i
        qmin = q
        
print('\n\nlucro máximo:',lmax,'\nPreço do ingreço:',imin,'\nQuantidade vendidas:',qmin)