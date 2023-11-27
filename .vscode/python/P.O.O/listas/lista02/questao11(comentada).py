def mediaaluno(nome,lista):
    for i, v in enumerate(lista):
        if nome == v['nome']:
            media = (v['nota1'] + v['nota2']) / 2
            return media    
    print("dados não encontrados")
    return 0

numero = int(input("quantos alunos deseja cadastrar?\n"))
notas =[{'nome':'','nota1':'','nota2':''} for _ in range(numero)]

for i, v in enumerate(notas):
    v['nome'] = input(f'diga o nome do {i+1}° aluno: ')
    v['nota1'] = int(input('diga a 1° nota: '))
    v['nota2'] = int(input('diga a 2° nota: '))
        
resp = input('diga o nome do aluno que deseja buscar a media\n')
media = mediaaluno(resp,notas)
if media != 0:
    print(media)
    
# versao melhorada: 
#     def media_aluno(nome, lista):
#     for aluno in lista:
#         if nome == aluno['nome']:
#             media = (aluno['nota1'] + aluno['nota2']) / 2
#             return media    
#     print("Dados não encontrados")
#     return 0

# numero = int(input("Quantos alunos deseja cadastrar?\n"))
# notas = []

# for i in range(numero):
#     aluno = {}
#     aluno['nome'] = input(f'Diga o nome do {i+1}° aluno: ')
#     aluno['nota1'] = int(input('Diga a 1° nota: '))
#     aluno['nota2'] = int(input('Diga a 2° nota: '))
#     notas.append(aluno)
        
# resp = input('Diga o nome do aluno que deseja buscar a média\n')
# media = media_aluno(resp, notas)
# if media != 0:
#     print(media)