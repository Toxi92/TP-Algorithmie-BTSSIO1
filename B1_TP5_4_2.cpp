#include <iostream>
#include <string>
#include <vector>

/*
Le type produit est sous la forme

[ [libellé, quantité en stock , PrixHT ( calculé à partir du prix d'achat entré mais pas mm valeur dcp) ] ]
*/

using namespace std;

// Structure définissant un produit dans l'inventaire avec trois attributs : libellé, quantité en stock et prix hors taxes (HT)
struct CUMP {
    string libelle = "Libelle par defaut"; // Nom du produit
    int quantite_stock = 5; // Quantité initiale en stock
    float prixHT = 9.99; // Prix HT par défaut du produit
};

// Fonction qui initialise le stock avec un produit par défaut
vector<CUMP> stock() {
    vector<CUMP> inventaire(1); // Crée un vecteur (tableau dynamique) de produits avec un élément
    inventaire[0].libelle = "TesT"; // Définit le libellé du premier produit
    inventaire[0].prixHT = 7.0; // Définit le prix HT du produit
    inventaire[0].quantite_stock = 17; // Définit la quantité en stock du produit
    return inventaire; // Retourne l'inventaire initialisé
}

// Fonction qui affiche l'état actuel du stock
vector<CUMP> affiche_stock(vector<CUMP> &inventaire) {
    cout << "[" << endl; // Commence l'affichage du stock
    for (auto &&element : inventaire) { // Boucle à travers tous les produits dans l'inventaire
        cout << "[ " << element.libelle << " , " << element.quantite_stock << " , " << element.prixHT << " ]," << endl; // Affiche le libellé, la quantité en stock, et le prix HT de chaque produit
    }
    cout << "]" << endl; // Fin de l'affichage du stock
    return inventaire; // Retourne l'inventaire (pas nécessaire mais peut être utile si des modifications y sont faites dans d'autres contextes)
}

// Fonction pour ajouter un produit dans le stock ou mettre à jour un produit existant
vector<CUMP> ajout_stock(vector<CUMP> &inventaire) {
    string libelle;
    int quantite;
    float prix_achat;

    // Saisie des informations du produit
    cout << "Libelle : " << endl;
    getline(cin, libelle); // Récupère le nom du produit
    cout << "Quantite : " << endl;
    cin >> quantite; // Récupère la quantité livrée
    cout << "Prix d'achat" << endl;
    cin >> prix_achat; // Récupère le prix d'achat du produit
    bool existe = false; // Variable pour vérifier si le produit existe déjà dans l'inventaire

    // Parcourt l'inventaire pour vérifier si le produit existe déjà
    for (auto &&element : inventaire) {
        if (element.libelle == libelle) { // Si le produit existe déjà
            // Met à jour le prix HT selon la formule du CUMP (Coût Unitaire Moyen Pondéré)
            element.prixHT = (element.prixHT * element.quantite_stock + prix_achat * quantite) / (element.quantite_stock + quantite);
            // Met à jour la quantité en stock
            element.quantite_stock = element.quantite_stock + quantite;
            existe = true; // Indique que le produit a été trouvé
        }
    }

    // Si le produit n'existe pas, il est ajouté à l'inventaire
    if (!existe) {
        float nvPrixHT;
        cout << "Entrez nouveau prix HT : " << endl;
        cin >> nvPrixHT; // Saisie du prix HT pour un nouveau produit
        CUMP NvProduit; // Création d'un nouveau produit
        NvProduit.libelle = libelle; // Attribution du libellé
        NvProduit.prixHT = nvPrixHT; // Attribution du prix HT
        NvProduit.quantite_stock = quantite; // Attribution de la quantité en stock
        inventaire.push_back(NvProduit); // Ajout du produit à l'inventaire
    }

    // Affiche le stock mis à jour après l'ajout
    affiche_stock(inventaire);
    return inventaire; // Retourne l'inventaire mis à jour
}

// Fonction pour gérer la vente d'un produit
vector<CUMP> vente_stock(vector<CUMP> &inventaire) {
    string libelle;
    int quantite_vendu;

    // Affiche l'état actuel du stock avant la vente
    affiche_stock(inventaire);
    cout << "Libelle : " << endl;
    cin.ignore(); // Ignore le caractère newline résiduel dans le buffer
    getline(cin, libelle); // Récupère le nom du produit à vendre
    cout << "Quantite vendu: " << endl;
    cin >> quantite_vendu; // Récupère la quantité vendue
    bool existe = false; // Variable pour vérifier si le produit existe dans l'inventaire

    // Parcourt l'inventaire pour trouver le produit à vendre
    for (auto &&element : inventaire) {
        if (element.libelle == libelle) { // Si le produit est trouvé
            existe = true; // Marque que le produit existe
            if ((element.quantite_stock - quantite_vendu) < 0) { // Vérifie si la quantité vendue est supérieure au stock disponible
                cout << "La quantite vendu est trop grande par rapport au stock" << endl;
                affiche_stock(inventaire); // Réaffiche le stock sans modification
                break; // Arrête la vente
            } else {
                // Met à jour la quantité en stock après la vente
                element.quantite_stock = element.quantite_stock - quantite_vendu;
                // Calcule et affiche le prix de vente basé sur le prix HT avec une marge de 1,56
                cout << "Le prix de vente de ce produit est : " << element.prixHT * 1.56 << endl;
                cout << "Stock apres la vente : " << endl;
                affiche_stock(inventaire); // Affiche le stock mis à jour après la vente
            }
        }
    }

    // Si le produit n'existe pas dans l'inventaire, informe l'utilisateur
    if (!existe) {
        cout << "Ce produit n'existe pas !" << endl;
        affiche_stock(inventaire); // Réaffiche l'inventaire sans modification
    }

    return inventaire; // Retourne l'inventaire mis à jour après la vente
}