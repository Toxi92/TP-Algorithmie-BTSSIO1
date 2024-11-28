#Exercice 1
"""Tab=[0 for i in range(7)]"""
#print(Tab)

#Exercice 2
"""Tab2=['A','E','I','O','U','Y']"""

#Exercice 3
"""Tab3=[0 for i in range(9)]
for i in range(9):
    Tab3[i]=int(input(f'Valeur pour la note n° {i+1} : '))"""
#print(Tab3)

#Exercice 4
"""Tab4=[0 for i in range(5)]
for i in range(5):
    Tab4[i]=i*i
    print(Tab4[i])
"""
#Exercice 5
"""Tab5=[0 for i in range(6)]
Tab5[0]=1
print(Tab5[0])
for i in range(1,6):
    Tab5[i]=Tab5[i-1]+2
    print(Tab5[i])"""

#Exercice 6
"""Tab6=[0 for i in range(7)]
Tab6[0]=1
print(Tab6[0])
Tab6[1]=1
print(Tab6[1])
for i in range(2,7):
    Tab6[i]=Tab6[i-1]+Tab6[i-2]
    print(Tab6[i])"""

#Exercice 7
Tab7=[0 for i in range(9)]
cnt=0
for i in range(9):
    Tab7[i]=int(input(f'Valeur pour la note n° {i+1} : '))
    cnt=cnt+Tab7[i]
print(Tab7," moyenne du tableau : ",cnt/i)