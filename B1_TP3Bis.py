#Q1
"""while(True):
    val=int(input("Entrez une valeur entre 1 et 3"))
    if(1<=val<=3):break
"""

#Q2
"""while(True):
    val=int(input("Entrez une valeur entre 10 et 20 : "))
    if(val<10):
        print('Plus grand')
    elif(val>20):
        print('Plus petit')
    else:
        print('Bravo')
        break"""
#Q3
"""nb_depart=int(input("Entrez un nombre de départ : "))
for i in range(1,10):
    print(nb_depart+i)
"""

#Q4
"""nb_depart=int(input("Entrez un nombre de départ : "))
for i in range(1,11):
    print(nb_depart," x ",i," = ",nb_depart*i)
"""
#Q5
"""cnt=1
nb_depart=int(input("Entrez un nombre : "))
res=0
while(cnt!=nb_depart+1):
    res=res+cnt
    cnt=cnt+1
print(res)
"""
#Q6
"""cnt=1
nb_depart=int(input("Entrez un nombre : "))
res=1
while(cnt!=nb_depart+1):
    res=res*cnt
    cnt=cnt+1
print(res)"""
#Q7
"""maxval=0
maxindex=0
for i in range(1,21):
    val=int(input(f'Entrez le nombre N°{i} : '))
    if(i==1):
        maxval=val
    elif(val>maxval):
        maxval=val
        maxindex=i
print("La valeur max parmi toutes les valeurs est : ",maxval," et elle se trouvais à la position : ",maxindex)"""
#Q8
"""maxval=0
maxindex=0
index=1
while(True):
    val=int(input(f'Entrez le nombre N°{index} (0 pour arrêter): '))
    if(val==0):break
    if(index==1):
        maxval=val
    elif(val>maxval):
        maxval=val
        maxindex=index
    index=index+1
print("La valeur max parmi toutes les valeurs est : ",maxval," et elle se trouvais à la position : ",maxindex)
"""
#Q9 J'ai rien compris à la consigne elle est mal faite
#Q10 Pas dur mais que veux dire X = n ! / (n - p) ! et Y = n ! / (p ! * (n – p) !) 
