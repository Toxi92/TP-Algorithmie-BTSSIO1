#Q1
def affichage(name,surname):
    print("Le cours d'algorithme est bientot fini.Bon courage à vous",name, surname," pour la suite.")
#affichage('Edgar',"Oui")

#Q2

def mtcom(ca):
    if(ca<10000):
        txc=0.1
    elif(10000<=ca<=20000):
        txc=0.12
    elif(20000<ca<=30000):
        txc=0.15
    elif(ca>30000):
        txc=0.20
    mtc=ca*txc
    print("Taux de commission = ",txc*100,"%\n")
    print("Montant de commission = ",mtc,"€")
#mtcom(20001)

#Q3
def cube(nb):
    return nb**3
#print(cube(3))

#Q4

def moyenne():
    resultat=0
    cnt=0
    while True:
        val=input("Entrez une valeur ('quit' pour arrêter) : ")
        if(val=='quit'):break
        cnt=cnt+1
        resultat=resultat+int(val)
    return resultat/cnt
#print(moyenne())

