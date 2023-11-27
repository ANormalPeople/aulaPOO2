def printarray(array):
    for c in array:
        if isinstance(c, list):
            printarray(c)
        else:
            print(c)
                
lista3 = [3,4]
lista2 = [2,lista3]                  
lista1 = ['a',2.5,0,1,lista2,5] 

printarray(lista1)
