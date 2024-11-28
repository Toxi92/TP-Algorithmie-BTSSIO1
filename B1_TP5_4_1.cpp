#include <iostream>
#include <string>
/*
Le type structuré fournisseur est un tableau de tableau sous la forme 

[
[Nom1,telephone1,date de derniere commande1,CA1],
[Nom2,telephone2,date de derniere commande2,CA2]
. . .
]

*/
using namespace std;

struct FormeFournisseur // Je suis obligé de préparer un type de structure pour mon tableau ( pas besoin de le faire en php)
{
    string Nom = "Nom";
    string telephone="06 etc";
    int date[3] = {16,10,2000};
    int CA=0;
};


FormeFournisseur* fournisseur_tab(){ // On fais une fonction qui permet de créer et d'afficher un tableau avec 100 tableau de la forme de la structure faite avant
    FormeFournisseur* foursnisseur = new FormeFournisseur[100];
    cout << '['<<endl;
    foursnisseur[7].CA=2000;
    foursnisseur[7].Nom="TeST";
    foursnisseur[7].date[0]=16;
    foursnisseur[7].date[1]=10;
    foursnisseur[7].date[2]=2024;
    foursnisseur[18].Nom="Deuxiememec";
    foursnisseur[18].telephone="deuxiemme telephone";
    foursnisseur[18].date[0]=15;
    foursnisseur[18].date[1]=10;
    foursnisseur[18].date[2]=2024;
    for(int i=0;i<100;i++){
        cout <<'['<< foursnisseur[i].Nom<<',';
        cout << foursnisseur[i].telephone<<',';
        cout << foursnisseur[i].date[0] << '/' <<foursnisseur[i].date[1] << '/' << foursnisseur[i].date[2] <<',';
        if(i<99){
            cout << foursnisseur[i].CA << "]," << endl;
        }else{
            cout << foursnisseur[i].CA << ']' << endl;
        }
    }
    cout << ']' << endl;
    return foursnisseur;
}

int PlusGrandParNom(FormeFournisseur* fournisseur){//Fonction qui prend un tableau de la forme créer précedémment 
    int PlusGrandCA = 0;
    int indexPlusGrandCA=0;
    for(int i =0;i<100;i++){//On cherche dans les 100 tableau du tableau
        if(fournisseur[i].CA>PlusGrandCA){//Si le CA du fournisseur qui est actuellement parcouru est plus grand que celui d'avant , 0 pour le premier
            PlusGrandCA=fournisseur[i].CA;//On actualise le CA le plus grand pour les autres passage
            indexPlusGrandCA=i;//On stock la place du fournisseur qui à ce CA plus grand que celui d'avant
        }
    }cout << "La personne ayant le plus grand CA est " << fournisseur[indexPlusGrandCA].Nom << " et son CA est de " << fournisseur[indexPlusGrandCA].CA << endl;// Au bout des 100 tableau on sait qu'on a forcement le plus grand CA et son index donc avec son index sont peux afficher le Nom correspondant
    return PlusGrandCA;//Pas besoin car PHP n'a pas de fonction typé et de toute façon le plus grand ca n'est pas magné dans la suite.
}

int DateParNom(FormeFournisseur* fournisseur){//Nouvelle fonction qui prend toujours le tableau de la forme de d'habitude
    string NomF;//On prépare et ensuite on demande le nom d'un fournisseur
    bool existe = false;//On anticipe la variable qui permettra d'envoyer un message si le nom entré n'est pas trouvé 
    cout << "Entrez le nom du fournisseur : " << endl;
    cin>>NomF;
    for(int i=0;i<100;i++){//On parcours les tableaux
        if(fournisseur[i].Nom==NomF){//On compare et si c'est le fournisseur entré correspond au fournisseur parcouru
            cout << "La date correspondant a '" << NomF << "' est la suivante : " << fournisseur[i].date[0] << fournisseur[i].date[1] << fournisseur[i].date[2]  << endl;
            existe = true;//On passe existe a true , on sort de la boucle , et ont affiche la date de derniere commande  ( on s'aide de l'index de la boucle comme d'hab)
            break;
        }
    }if(!existe){
        cout << "Cette personne n'existe pas !"<< endl;//Si il existe pas c'est resté false
    }
    return 0;
}

int NomTelParDate(FormeFournisseur* fournisseur){
    int date1[3];
    int date2[3];
    cout << "Entrez premiere date sous forme (dd;mm;yy;)"<<endl;
    cout  << "Premiere date dd : ";
    cin >> date1[0];
    cout << endl << "Premiere date mm : ";
    cin >> date1[1];
    cout << endl << "Premiere date yy : ";
    cin >> date1[2];

    cout  << "Deuxieme date dd : ";
    cin >> date2[0];
    cout << endl << "Deuxieme date mm : ";
    cin >> date2[1];
    cout << endl << "Deuxieme date yy : ";
    cin >> date2[2];

    for(int i=0;i<100;i++){//On parcours les tableau
        if(date1[2]<=fournisseur[i].date[2] && fournisseur[i].date[2]<date2[2]){//Si l'année est comprise entre les deux entrée on affiche les infos du fournisseur actuel
            cout << "Le fournisseur "<<fournisseur[i].Nom << " dont le numero de telephone est "<< fournisseur[i].telephone << " a commande entre ces deux dates"<<endl;
        }  else if((date1[2]==fournisseur[i].date[2] || fournisseur[i].date[2]==date2[2])&&(date1[1]<fournisseur[i].date[1] && fournisseur[i].date[1]<date2[1])){//Si c'est la même année mais que le mois est compris
            cout << "Le fournisseur "<<fournisseur[i].Nom << " dont le numero de telephone est "<< fournisseur[i].telephone << " a commande entre ces deux dates"<<endl;
        } else if(((date1[2]==fournisseur[i].date[2] ||fournisseur[i].date[2]==date2[2])&&(date1[1]==fournisseur[i].date[1] || fournisseur[i].date[1]==date2[1]))&&(date1[0]<fournisseur[i].date[0]&&fournisseur[i].date[0]<date2[0])){//Si c'est la même année et le même mois mais que le jours est compris
            cout << "Le fournisseur "<<fournisseur[i].Nom << " dont le numero de telephone est "<< fournisseur[i].telephone << " a commande entre ces deux dates"<<endl;
        }
    }
    return 0;
}

int menu(FormeFournisseur* fournisseur){
    int conti;
    do
    {
        cout << "Que voulez vous faire 1 , 2 , 3 (0 pour stop)"<<endl;
        cin >> conti;
        if(conti==1){
            PlusGrandParNom(fournisseur);
            menu(fournisseur);
        }if(conti==2){
            DateParNom(fournisseur);
            menu(fournisseur);
        }if(conti==3){
            NomTelParDate(fournisseur);
            menu(fournisseur);
        }

    } while (conti!=0);
    return 0;
}