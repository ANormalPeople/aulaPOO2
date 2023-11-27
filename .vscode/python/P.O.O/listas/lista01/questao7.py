Decimal = int(input(""))
if Decimal == 0:
    result = '0' 
aux = ''
result = ''
while Decimal != 0:
    if Decimal % 2 != 0:  
        aux += '1'

    elif Decimal % 2 == 0:
        aux += '0'
    Decimal //= 2
        
for i in range(len(aux),0,-1):
    if aux[i-1] == '1':
        result +='1'
    else:
        result += '0'      
     
print(result)

