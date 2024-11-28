//
// Created by Toxi on 01/10/2024.
//

#ifndef REGROUPEMENTFONCTIONSTP_H
#define REGROUPEMENTFONCTIONSTP_H

int** matrice2d(int taille1,int taille2);
int** plateau2d(int taille1,int taille2);
int** plusGrandDansTableau(int** tableau,int taille1,int taille2);
int JeuDeDame(int** &plateau);
#include <string>
#include <vector>
using namespace std;
struct FormeFournisseur
{
    string Nom = "Nom";
    string telephone="06 etc";
    string date = "16/10/2006";
    int CA=0;
};

FormeFournisseur* fournisseur_tab();

int PlusGrandParNom(FormeFournisseur* fournisseur);
int DateParNom(FormeFournisseur* fournisseur);
int NomTelParDate(FormeFournisseur* fournisseur);
int menu(FormeFournisseur* fournisseur);

struct CUMP{
    string libelle="Libelle par defaut";
    int quantite_stock=5;
    float prixHT=9.99;
};

vector<CUMP> stock();
int affiche_stock(vector<CUMP> &inventaire);
vector<CUMP> ajout_stock(vector<CUMP> &inventaire);
vector<CUMP> vente_stock(vector<CUMP> &inventaire);

struct Eleve{
    string CodeEl = CodeEl.substr(0,3);
    string NomEl = NomEl.substr(0,29);
    string ClassEl = ClassEl.substr(0,9);
    int NbreE;
};

struct Emprunt{
    int NumE;
    int DateE[3]={2006,10,16};
    int DateR[3]={2006,11,20};
    int PosE;
};


Eleve* CreerEleve();
int AfficheTabEleve(Eleve* TabEleve);
vector<Emprunt> CreerTabEmprunt();
int AfficheTabEmprunt(vector<Emprunt> TabEmprunt);
vector<Emprunt> AjoutEmprunt(vector<Emprunt> &TabEmprunt,Eleve* &TabEleve);
string NomClasseParDate(vector<Emprunt> TabEmprunt,Eleve* TabEleve);


#endif //REGROUPEMENTFONCTIONSTP_H