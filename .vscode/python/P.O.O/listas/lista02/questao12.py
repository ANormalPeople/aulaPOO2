corredores = []
volta = [99999] + [None] * 2
for i in range(5):
    voltas = {}
    voltas['nome'] = input(f"diga o nome do {i+1}° corredor:\n")
    try:
        voltas['1tempo'] = int(input("tempo da 1° volta: "))
        voltas['2tempo'] = int(input("tempo da 2° volta: "))
        voltas['3tempo'] = int(input("tempo da 3° volta: "))
    except:
        print("apenas valores númericos, tente novamente")
        break
    
    corredores.append(voltas)
    
    if voltas['1tempo'] < volta[0]:
        volta[0] = voltas['1tempo']
        volta[1] = 1
        volta[2] = voltas['nome']
    if voltas['2tempo'] < volta[0]:
        volta[0] = voltas['2tempo']
        volta[1] = 2
        volta[2] = voltas['nome']
    if voltas['3tempo'] < volta[0]:
        volta[0] = voltas['3tempo']
        volta[1] = 3
        volta[2] = voltas['nome']

melhor_media = float('inf')
campeao = None

for v in corredores:
    media = (v['1tempo'] + v['2tempo'] + v['3tempo']) / 3
    
    if media < melhor_media:
        melhor_media = media
        campeao = v['nome']

print("a melhor volta foi a do",volta[2],' durante a volta',volta[1],' com o tempo de',volta[0],)
print("O campeão é", campeao)