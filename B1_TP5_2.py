#Exercice 8 

"""nb_val=int(input("Nombre de valeur à entrer : "))
tab=[0 for i in range(nb_val)]
pos=0
neg=0
for i in range(nb_val):
    val=int(input(f"Valeur N°{i} : "))
    tab[i]=val
    if(tab[i]>0):pos=pos+1
    else:neg=neg+1
print(tab,pos,neg)"""

#Exercice 9
"""cnt=0
for el in tab:
    cnt=cnt+el
print(cnt)"""

#Exercice 10
"""tab=[4,8,7,9,1,5,4,6]
tab2=[7,6,5,2,1,3,7,4]
tabres=[]
print(len(tab))
for i in range(len(tab)):
    print(i)
    tabres.append(tab[i]+tab2[i])
print(tabres)
    """

#Exercice 11
"""tab2=[4,8,7,12]
tab=[3,6]
cnt=0
for el in tab:
    for produit in tab2:
        cnt=cnt+el*produit
print(cnt)"""

#Exercice 12
"""nb_val=int(input("Nombre de valeur à entrer : "))
tab=[0 for i in range(nb_val)]
for i in range(nb_val):
    val=int(input(f"Valeur N°{i} : "))
    tab[i]=val+1
print(tab)"""

#Exercice 13
"""nb_val=int(input("Nombre de valeur à entrer : "))
tab=[0 for i in range(nb_val)]
for i in range(nb_val):
    val=int(input(f"Valeur N°{i+1} : "))
    tab[i]=val

imax=0
maxval=tab[0]
for i in range(nb_val):
    if (tab[i]>maxval):
        maxval=tab[i]
        imax=i
print(maxval,imax)"""

#Exercice 14

nb_val=int(input("Nombre de valeur à entrer : "))
tab=[0 for i in range(nb_val)]
moyenne=0
for i in range(nb_val):
    val=int(input(f"Valeur N°{i+1} : "))
    tab[i]=val
    moyenne=moyenne+val
moyenne=moyenne/i
cnt=0
for note in tab:
    if(note>moyenne):
        cnt=cnt+1
print("Il y a ",cnt," notes au dessus de la moyenne classe, cette dernière étant de : ",moyenne)
