#Q1
def facto_p(factorielle,res):
    res=factorielle
    for i in range(1,factorielle):
        res=res*(factorielle-i)
    print(res)
"""resultat1=facto(7,0)"""
    
#Q2
def facto(factorielle):
    res=factorielle
    for i in range(1,factorielle):
        res=res*(factorielle-i)
    return res
"""resultat1=0
resultat1=facto(7,resultat1)
print(resultat1)"""

#Q3
"""def faire_facto():
    resultat=0
    val_facto=int(input("Qelle factorielle voulez-vous faire : "))
    print("Méthode 2 :")
    print(facto(val_facto))
    print("Méthode 1 : ")
    facto_p(val_facto,resultat)
faire_facto()"""

#Q4
"""def convert(somme,devise):
    if(devise!='$'and devise!='€'):
        print('Pas de devise valide')
        return
    if(devise=='$'):print("Somme en euro : ",round(somme*0.90,2))
    else:print("Somme en dollar : ",round(somme/0.90,2))
#convert(28,'€')

#Q5
while(True):
    next=input("Faire une conversion y/n : ")
    if(next=='y'):
        s=int(input("Somme ? : "))
        d=input("Devise ? $/€ : ")
        convert(s,d)
    elif(next=='n'):break
    else:print('mauvaise entrée')
"""
#Q6
"""def cap(pays):
    match pays:
        case 'France':
            print('Sa capitale est Paris')
        case 'Italie':
            print('Sa capitale est Rome')
        case 'Espagne':
            print('Sa capitale est Madrid')
        case 'Allemagne':
            print('Sa capitale est Berlin')
        case 'Pologne':
            print('Sa capitale est Varsovie')
        case 'République Tchèque':
            print('Sa capitale est Prague')
        case 'Angleterre':
            print('Sa capitale est Londres')
        case 'Portugal':
            print('Sa capitale est Lisbonne')
        case 'Pays-Bas':
            print('Sa capitale est Amsterdam')
        case _:
            print('Cette capitale ne doit pas être' ,pays, "elle s’est échappée de mon capital mémoire")
#cap(3)

#Q7
for i in range(5):
    next=input("Quelle capitale ? ('quit' pour stop, 5 fois max): ")
    if(next=='quit'):break
    cap(next)"""

#Q8
"""def cube(x):
    return x**3

#Q9
def puissancepar3():
    x=int(input('Quelle valeur ? : '))
    print(cube(x),cube(x)*cube(x),cube(x)*cube(x)*cube(x))
puissancepar3()"""

#Q10
"""def positive(tableau):
    cnt=0
    for element in tableau:
        if element>0:
            cnt=cnt+1
    return cnt
def negative(tableau):
    cnt=0
    for element in tableau:
        if element<0:
            cnt=cnt+1
    return cnt

#Q11
def affiche(tableau):
    print("Nombre de valeur positive dans le tableau : ", positive(tableau))
    print("Nombre de valeur negative dans le tableau : ", negative(tableau))
affiche([2,1,3,4,15,73,0,0,-3,-4,-1,-12])"""