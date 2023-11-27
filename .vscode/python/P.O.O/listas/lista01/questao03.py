while True:          
        R = input("diga o formato(triângulo, quadrado ou círculo)\n")
        if R in ['triângulo','triangulo']:
            B = float(input('diga a base\n'))
            H = float(input('diga a altura\n'))
            Result = (B*H)/2
            print('area = ',Result,'\n')
        
        elif R == 'quadrado':
            L = float(input('diga o lado\n'))
            print('area = ',(L*2),'\n')

        elif R in ['circulo','círculo']:
            Raio = float(input('diga o raio\n'))
            Result = (Raio*2) * 3.14
            print('area = ',Result,'\n')  
        
        else:
            print('formato invalido!')
            continue
        
        X = input('deseja continuar? (S/N)')
        
        if X.lower() == 'n':
            break