#include <iostream>

using namespace std;
int** matrice2d(int taille1,int taille2) {
    int** tableau1 = new int*[taille1];
    cout << '[' << endl;
    for(int i=0;i<taille1;i++) {
        cout << '[';
        tableau1[i] = new int[taille2];
        for(int j=0;j<taille2;j++) {
            tableau1[i][j]=0;
            if(j!=taille2) {
                cout <<tableau1[i][j]<<",";
            }else if(j==taille2) {
                cout <<tableau1[i][j]<<"],";
            }
        }

        cout<<endl;
    }
    cout << ']';
    return tableau1;
}

int** plusGrandDansTableau(int** tableau,int taille1,int taille2) {
    int ValMax=tableau[0][0];
    for(int i=0;i<taille1;i++) {
        for(int j=0;j<taille2;j++) {
            if(tableau[i][j]>ValMax) {
                ValMax=tableau[i][j];
            }
        }
    }
    cout << "La valeur la plus grande du tableau a deux dimensions est : " << ValMax << endl;
    return tableau;
}

int** plateau2d(int taille1,int taille2) {
    int** tableau1 = new int*[taille1];
    cout << '[' << endl;
    for(int i=0;i<taille1;i++) {
        cout << '[';
        tableau1[i] = new int[taille2];
        for(int j=0;j<taille2;j++) {
            if(i==0||i==2 || i==6 || i==8){
                if(j%2==0){
                    tableau1[i][j]=0;
                }else{tableau1[i][j]=1;}
            }
            if(i==1 || i==3 || i==7 || i==9){
                if(j%2==0){
                    tableau1[i][j]=1;
                }else{tableau1[i][j]=0;}
            }
            if(i==4||i==5){tableau1[i][j]=0;}
            if(j!=taille2) {
                cout <<tableau1[i][j]<<",";
            }else if(j==taille2) {
                cout <<tableau1[i][j]<<"],";
            }
        }

        cout<<endl;
    }
    cout << ']';
    return tableau1;
}

int JeuDeDame(int** &plateau) {
    int pos_colonne;
    int pos_ligne;

    do {
        do {
            cout << "Entrez la ligne : " << endl;
            cin >> pos_ligne;
        } while(pos_ligne<1 or pos_ligne>10);
        do {
            cout << "Entrez la colonne : " << endl;
            cin >> pos_colonne;
        } while(pos_colonne<1 or pos_colonne>10);  
    pos_colonne=pos_colonne-1;
    pos_ligne=pos_ligne-1; 
    }while(plateau[pos_ligne][pos_colonne]!=1);

    int next_pos;
    cout << '[' << endl;
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout <<plateau[i][j]<<",";
            if(j==8) {
                cout <<plateau[i][j]<<endl;
            }
        }
    }


    do {
        cout << "Ou voulez-vous aller ? 0 - haut gauche 1 - haut droite 2 - bas gauche 3 - bas droite : " << endl;
        cin >> next_pos;
    }while (0>next_pos>4);
    if(next_pos==0) {
        if(pos_colonne-1 >= 0 && pos_colonne-1 <= 9 && pos_ligne-1 >= 0 && pos_ligne-1 <= 9 && plateau[pos_ligne-1][pos_colonne-1]==0) {
            plateau[pos_ligne][pos_colonne]=0;
            plateau[pos_ligne-1][pos_colonne-1]=1;
        }else cout<<"Mouvement impossible"<<endl;
    }else if(next_pos==1) {
        if (pos_colonne+1 >= 0 && pos_colonne+1 <= 9 && pos_ligne-1 >= 0 && pos_ligne-1 <= 9  && plateau[pos_ligne-1][pos_colonne+1]==0) {
            plateau[pos_ligne][pos_colonne]=0;
            plateau[pos_ligne-1][pos_colonne+1]=1;
        }else cout<<"Mouvement impossible"<<endl;
    }else if(next_pos==2) {
        if(pos_colonne-1 >= 0 && pos_colonne-1 <= 9 && pos_ligne+1 >= 0 && pos_ligne+1 <= 9  && plateau[pos_ligne+1][pos_colonne-1]==0) {
            plateau[pos_ligne][pos_colonne]=0;
            plateau[pos_ligne+1][pos_colonne-1]=1;
        }else cout<<"Mouvement impossible"<<endl;
    }else if(next_pos==3) {
        if(pos_colonne+1 >= 0 && pos_colonne+1 <= 9 && pos_ligne+1 >= 0 && pos_ligne+1 <= 9  && plateau[pos_ligne+1][pos_colonne+1]==0) {
            plateau[pos_ligne][pos_colonne]=0;
            plateau[pos_ligne+1][pos_colonne+1]=1;
        }else cout<<"Mouvement impossible"<<endl;
    }

    cout << '[' << endl;
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout <<plateau[i][j]<<",";
            if(j==8) {
                cout <<plateau[i][j]<<endl;
            }
        }
    } cout << "]";

    return 0;
}