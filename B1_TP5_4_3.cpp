#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Emprunt{
    int NumE;
    int DateE[3]={2006,10,16};
    int DateR[3]={2006,11,20};
    int PosE;
};

struct Eleve{
    string CodeEl="E001";
    string NomEl="NomEL";
    string ClassEl="SIO1B";
    int NbreE=0;
};

int NBEP;
int NBEL;

Eleve* CreerEleve(){
    Eleve* TabEleve = new Eleve[500];
    TabEleve[7].CodeEl="E007";
    TabEleve[7].NomEl="Test";
    TabEleve[7].ClassEl="SIO1A";
    return TabEleve;
}

int AfficheTabEleve(Eleve* TabEleve){
    cout<<"["<<endl;
    for(int i=0;i<500;i++){
        cout<<"[ "<<TabEleve[i].ClassEl<<", "<<TabEleve[i].CodeEl<<", "<<TabEleve[i].NbreE<<", "<<TabEleve[i].NomEl<<"],"<<endl;
    }
    cout<<']'<<endl;
    return 0;
}

vector<Emprunt> CreerTabEmprunt(){
    vector<Emprunt> TabEmprunt(1);
    TabEmprunt[0].NumE=TabEmprunt.size();
    TabEmprunt[0].PosE = 0;
    return TabEmprunt;
}

int AfficheTabEmprunt(vector<Emprunt> TabEmprunt){
    cout<<"["<<endl;
    for(auto element : TabEmprunt){
        cout<<"[ "<<element.NumE << ", "<<"{"<<element.DateE[0]<<'-'<<element.DateE[1]<<'-'<<element.DateE[2]<<'}'<<", "<<"{"<<element.DateR[0]<<'-'<<element.DateR[1]<<'-'<<element.DateR[2]<<'}'<<", "<<element.PosE<<"],"<<endl;
    }
    cout<<" ]"<<endl;
    return 0;
}

vector<Emprunt> AjoutEmprunt(vector<Emprunt> &TabEmprunt,Eleve* &TabEleve){
    string code_saisi;
    int date[3];
    bool existe = false;
    cout << "Entrez le code de l'eleve dont il faut ajouter l'emprunt : ";
    getline(cin,code_saisi);
    cout << endl;
    cout << "Entrez premiere date sous forme (yyyy;mm;dd;)"<<endl;
    cout  << "Date : annee : ";
    cin >> date[0];
    cout << endl << "Date : mois :";
    cin >> date[1];
    cout << endl << "Date : jour :";
    cin >> date[2];

    for(int i=0;i<500;i++){//On parcours tout les élèves
        if(TabEleve[i].CodeEl==code_saisi){//Si le code élève correspond au code saisi
            existe=true;//Alors l'élève existe
            TabEleve[i].NbreE+=1;
            Emprunt NvEmprunt;
            NvEmprunt.DateE[0]=date[0];
            NvEmprunt.DateE[1]=date[1];
            NvEmprunt.DateE[2]=date[2];
            if(date[2]+15>30){
                if(date[1]==12){
                    date[0]+=1;
                    date[1]=1;
                    date[2]=(date[2]+15)-30;
                }else{
                date[1]+=1;
                date[2]=(date[2]+15)-30;
                }
            }else{
                date[2]+=15;
            }
            NvEmprunt.DateR[0]=date[0];
            NvEmprunt.DateR[1]=date[1];
            NvEmprunt.DateR[2]=date[2];
            NvEmprunt.NumE=TabEmprunt.size()+1;
            NvEmprunt.PosE=i;
            TabEmprunt.push_back(NvEmprunt);
            }
        }
    if(!existe){
        cout<<"Cet eleve n existe pas"<<endl;
    }
    return TabEmprunt;
}

string NomClasseParDate(vector<Emprunt> TabEmprunt,Eleve* TabEleve){
    int date[3];
    cout << "Entrez premiere date sous forme (yyyy;mm;dd;)"<<endl;
    cout  << "Date : annee : ";
    cin >> date[0];
    cout << endl << "Date : mois :";
    cin >> date[1];
    cout << endl << "Date : jour :";
    cin >> date[2];
    for(auto element : TabEmprunt){
        if((element.DateR[0]<date[0]) || (element.DateR[0]==date[0] && element.DateR[1]<date[1] ) || ((element.DateR[0]==date[0] && element.DateR[1]==date[1]) && element.DateR[2]<date[2])){
            for(int i=0;i<500;i++){
                if(element.PosE==i){
                    cout << TabEleve[i].NomEl << " en " << TabEleve[i].ClassEl<<endl;
                }
            }
        }
        }
    }
