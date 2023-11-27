def ordena(s):
    sl = list(s)
    for i in range(0,len(sl)-1):
        for j in range(1,len(sl)-i):
            if sl[j] < sl[j-1]:
                aux = sl[j-1]
                sl[j-1] = sl[j]
                sl[j] = aux
    saida = ''.join(sl)
    print(saida)
    
    
# def ordena(s):
#     sl = list(s)
#     saida = []
#     for i in range(0,len(sl)-1):
#         aux = sl[0]
#         count = 0
#         for c in range(0,len(sl)-1):            
#             if aux > sl[c]:
#                 aux = sl[c]
#                 count = c
#         saida.append(aux)
#         del sl[count]
#     saida = ''.join(saida)
#     print(saida)     
    
ola = "fdskfadfg"
ordena(ola)
             