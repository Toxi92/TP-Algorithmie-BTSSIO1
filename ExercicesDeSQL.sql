-- Exercice : Cas parcours du combattant

create table soldat(matricule varchar(20) primary key,nom varchar(30),prenom varchar(40));
create table niveau_difficulte(code_niveau char(5) primary key,libelle_niveau varchar(20),bonus numeric(6,3));
create table participation(n_participation INT primary key,matricule char(20),date DATE,constraint Fk_matricule foreign key(matricule) references soldat(matricule));
create table obstacle(nom_obstacle varchar(30) primary key,code_niveau char(5),note_mini numeric(4,2),constraint Fk_obstacle foreign key(code_niveau) references niveau_difficulte(code_niveau));
create table passer(nom_obstacle varchar(30),n_participation INT,note_instructeur numeric(4,2),temps DATE,constraint Fk_nom_obstacle foreign key(nom_obstacle) references obstacle(nom_obstacle),constraint Fk_n_participation foreign key(n_participation) references participation(n_participation),constraint Pk_double_passer primary key (nom_obstacle,n_participation));


-- Exercice : Cas Formule 1


create table circuit(
    NomCircuit varchar(40) primary key,
    Pays varchar(40),
    LgPiste INT,
    NbSpectateur INT
    )
create table Pneu(
    NomFournisseur varchar(40) primary key,
    DateAccreditation date,
)
create table Sponsor(
    NomEntreprise varchar(40) primary key,
    AdrSiege varchar(40)
)
create table Voiture(
    NumVoiture INT primary key,
    TypeVoiture varchar(40)
)
create table GrandPrix(
    NomGP varchar(40) primary key,
    NbTours INT,
    NbVoitures INT,
    NomCircuit varchar(40),
    constraint Fk_NomCircuit foreign key(NomCircuit) references circuit(NomCircuit)
);

create table Ecurie(
    NomEcurie varchar(40) primary key,
    AdrSiegeEcurie varchar(40),
    NomDirecteurSportif varchar(40),
    NomFournisseur varchar(40),
    constraint Fk_nom_fournisseur foreign key(NomFournisseur) references Pneu(NomFournisseur)
);

create table Pilote(
    NumPilote INT primary key,
    NomPilote varchar(40),
    PrenomPilote varchar(40),
    AgePilote INT,
    NumVoiture INT,
    NomEcurie varchar(40),
    constraint Fk_num_voiture foreign key(NumVoiture) references Voiture(NumVoiture),
    constraint Fk_nom_ecurie foreign key(NomEcurie) references Ecurie(NomEcurie)
);

create table qualifier(
    NomGP varchar(40),
    NumPilote INT,
    classement INT,
    constraint Fk_Nom_GP foreign key(NomGP) references GrandPrix(NomGP),
    constraint Fk_NumPilote foreign key(NumPilote) references Pilote(NumPilote),
    constraint PK_double primary key(NomGP,NumPilote)
    );

create table courir(
    NomGP varchar(40),
    NumPilote INT,
    NbPoints INT,
    constraint Fk_Nom_GP foreign key(NomGP) references GrandPrix(NomGP),
    constraint Fk_NumPilote foreign key(NumPilote) references Pilote(NumPilote),
    constraint PK_double primary key(NomGP,NumPilote)
)

create table soutenir(
    NomEcurie varchar(40),
    NomEntreprise varchar(40),
    constraint Fk_nom_ecurie_2 foreign key(NomEcurie) references Ecurie(NomEcurie),
    constraint Fk_nom_entreprise foreign key(NomEntreprise) references Sponsor(NomEntreprise),
    constraint Pk_double_2 primary key(NomEcurie,NomEntreprise)
);

create table Subventionner(
    NumPilote INT,
    NomEntreprise varchar(40),
    constraint Fk_NumPilote_2 foreign key(NumPilote) references Pilote(NumPilote),
    constraint Fk_nom_entreprise_2 foreign key(NomEntreprise) references Sponsor(NomEntreprise),
    constraint Pk_double_4 primary key(NumPilote,NomEntreprise)
);


--Exercice : Cas Entreprise de Formation


create table stage(
    NomStage varchar primary key,
    duree int
);
create table cours(
    NumCours int primary key,
    TrancheHorraire int,
    Contenu varchar(100)
);
create table entreprise(
    RefEntre varchar(40) primary key,
    NomEntreprise varchar(40),
    RespForm varchar(40)
);
create table formateur(
    NumForm INT primary key,
    NomForm varchar(40),
    AdrForm varchar(40)
);
create table session(
    NumSession INT primary key,
    DateDebut date,
    Sstage varchar(40),
    constraint Fk_Sstage_NomStage foreign key(Sstage) references stage(NomStage)
);
create table stagiaire(
    NumStagiaire int primary key,
    NomStagiaire varchar(40),
    AdrStagiaire varchar(40),
    StRefEntre varchar(40),
    constraint Fk_refentre foreign key(StRefEntre) references entreprise(RefEntre)
);
create table constituer(
    CNomStage varchar(40),
    CNumCours INT,
    constraint Fk_CNomStage foreign key(CNomStage) references stage(NomStage),
    constraint Fk_CNumCours foreign key(CNumCours) references cours(NumCours),
    constraint Pk_double primary key(CNomStage,CNumCours)
);
create table inscription(
    INumSession int,
    INumStagiaire int,
    DateInscription date,
    constraint Pk_double2 primary key(INumSession,INumStagiaire),
    constraint Fk_NumSession foreign key(INumSession) references session(NumSession),
    constraint Fk_Numstagiaire foreign key(INumStagiaire) references stagiaire(NumStagiaire)
);
create table presence(
    PNumSession int,
    PNumStagiaire int,
    DateInscription date,
    constraint Pk_double3 primary key(PNumSession,PNumStagiaire),
    constraint Fk_NumSession2 foreign key(PNumSession) references session(NumSession),
    constraint Fk_Numstagiaire2 foreign key(PNumStagiaire) references stagiaire(NumStagiaire)
);
create table intervention(
    INNumForm int,
    INNUmSession int,
    INNumCours int,
    Datess date,
    constraint Pk_double4 primary key(INNumForm,INNUmSession,INNumCours),
    constraint Fk_INNumForm foreign key(INNumForm) references formateur(NumForm),
    constraint Fk_INNumSession foreign key(INNUmSession) references session(NumSession),
    constraint Fk_INNumCours foreign key(INNumCours) references cours(NumCours)
);

--Exercice : Cas restaurant


create table contenant(
    ID_contenant int primary key,
    Nom_contenant varchar(20)
);

create table resto(
    ID_resto int primary key,
    Nom_resto varchar(40) unique,
    Adresse varchar(40),
    Telephone varchar(14),
    NomChef varchar(40),
    NbEtoile int default 0
);

create table menu(
    ID_menu int primary key,
    Entre varchar(40) not null,
    Plat varchar(40) not null,
    Dessert varchar(40) not null
);

create table MenuResto(
    ID_menu int,
    ID_resto int,
    Prix numeric(4,2),
    constraint Pk_double primary key(ID_menu,ID_resto),
    constraint Fk_id_menu foreign key(ID_menu) references menu(ID_menu),
    constraint Fk_id_resto foreign key(ID_resto) references resto(ID_resto)
);

create table boisson(
    ID_boisson int primary key,
    NomBoisson varchar(40) unique not null,
    Temperature int check(Temperature>0),
    DegreeAlcool int
);

create table BoissonServiLaVrai(
    ID_resto int,
    ID_boisson int,
    ID_contenant int,
    Prix numeric(4,2),
    constraint Pk_triple primary key(ID_resto,ID_boisson,ID_contenant),
    constraint Fk_id_resto2 foreign key(ID_resto) references resto(ID_resto),
    constraint Fk__id_boisson foreign key(ID_boisson) references boisson(ID_boisson) on update cascade,
    constraint Fk_id_contenant foreign key(ID_contenant) references contenant(ID_contenant)
);

alter table boissonservi drop constraint fk_id_contenant;
alter table boissonservilavrai drop constraint fk_id_contenant2;
drop table contenant;
alter table menu add column cafe int;
alter table menu add constraint CafeOuPas check(cafe=0 or cafe=1);
alter table resto alter column nbetoile drop default;
alter table resto drop nbetoile;
alter table resto alter column nom_resto TYPE varchar(30);
alter table resto alter cafe set default 0;

-- Exercice Cas Loue Auto

-- Table Vehicule

CREATE TABLE Vehicule (
    immatriculation VARCHAR(120) PRIMARY KEY,
    modele VARCHAR(150),
    marque VARCHAR(150),
    etat VARCHAR(150),
    kilometrage INT
);

-- Table Client
CREATE TABLE Client (
    reference INT PRIMARY KEY,
    nom VARCHAR(150),
    prenom VARCHAR(150),
    adresseRue VARCHAR(100),
    adresseVille VARCHAR(150),
    adresseCodePostal VARCHAR(10)
);

-- Table Location
CREATE TABLE Location (
    numero INT PRIMARY KEY,
    immatriculationVehicule VARCHAR(150),
    date DATE,
    kmDebut INT,
    kmFin INT,
    commentaires TEXT,
    referenceClient INT,
    nbJours INT,
    FOREIGN KEY (immatriculationVehicule) REFERENCES Vehicule(immatriculation),
    FOREIGN KEY (referenceClient) REFERENCES Client(reference)
);

-- Remplir Vehicule
INSERT INTO Vehicule VALUES ('123ASZ93', 'clio', 'Renault', 'rayure porte arrière gauche', 10235);
INSERT INTO Vehicule VALUES ('4561FR93', 'clio', 'Renault', null, 9654);
INSERT INTO Vehicule VALUES ('7895EZ93', 'AX', 'Citroen', 'pare-choc avant droit ; porte avant gauche', 4789);

-- Remplir Client
INSERT INTO Client VALUES (2, 'Bounard', 'Hamed', '23, rue des peti', 'Aulnay', 93600);
INSERT INTO Client VALUES (3, 'Baltazard', 'Farid', '56, rue Arnaud', 'Montreuil', 93100);
INSERT INTO Client VALUES (4, 'Fermi', 'Jean', '1, rue de Paris', 'Romainville', 93230);
INSERT INTO Client VALUES (5, 'Valmont', 'Yann', '23, rue des Merl', 'Montreuil', 93100);
INSERT INTO Client VALUES (6, 'Roualt', 'Martine', '18, rue des Per', 'Aulnay', 93600);
INSERT INTO Client VALUES (11, 'Raqui', 'Sophie', '89, rue Ménard', 'Aulnay', 93600);

-- Remplir Location
INSERT INTO Location VALUES (21, '123ASZ93', '2009-08-01', 9425, 9512, 'ras', 2, 1);
INSERT INTO Location VALUES (22, '4561FR93', '2009-08-02', 8521, 8645, 'ras', 11, 1);
INSERT INTO Location VALUES (24, '4561FR93', '2009-08-04', 9645, 9021,  'ras', 5, 2);
INSERT INTO Location VALUES (42, '123ASZ93', '2009-08-02', 9512, 9628, 'rayure porte arrière gauche', 5, 1);
INSERT INTO Location VALUES (43, '123ASZ93', '2009-08-04', 9628, 10235, 'ras', 4, 2);

/*
La marque de la voiture louée durant la location numéro 24. => Renault

Le nom du client qui a loué cette voiture pour cette location. => Valmont Yann

Expliquer pourquoi les attributs kmDebut et kmFin figurent dans la relation Location plutôt que dans la relation Vehicule.

Car cela permet de connaitre le nombre de kilomètre effectué pendant une location.

Expliquer quand la valeur de l'attribut kilometrage dans la relation Vehicule pourra être mise à jour dans la base de données.

Quand la valeur kilomètre fin d'une location sera entrée.

*/

select nom,adresseville from client,location where client.reference = location.referenceclient and location.date='2009-08-15';

select modele from vehicule,location where vehicule.immatriculation=location.immatriculationvehicule and nbjours>=2;

select nom from client,location where client.reference=location.referenceclient and location.kmfin-location.kmdebut>300;


--Exercice Représentation Musicale

CREATE DATABASE login_repMus;

CREATE TABLE representation(
numRepresentation INTEGER PRIMARY KEY,
titre_representation VARCHAR,
lieu VARCHAR);

CREATE TABLE musicien(
nom VARCHAR PRIMARY KEY,
numRepresentation INTEGER,
CONSTRAINT fk_numRepMus FOREIGN KEY (numRepresentation) REFERENCES representation(numRepresentation)
);

CREATE TABLE programmer(
date DATE,
numRepresentation INTEGER,
tarif FLOAT,
CONSTRAINT pk_prog PRIMARY KEY (date, numRepresentation),
CONSTRAINT fk_numRepProg FOREIGN KEY (numRepresentation) REFERENCES representation(numRepresentation)
);

INSERT INTO representation VALUES(
1, 'Carmen', 'opera Bastille'),
(2, 'Figaro', 'théâtre Marigny'),
(3, 'Le Lac des Cygnes', 'theatre Michel'),
(4, 'Carmen','theâtre Mogador'),
(5, 'Mme Butterfly', 'theatre Moliere'),
(6, 'Carmen', 'Opéra Garnier');

INSERT INTO musicien VALUES(
'Marvel Comics', 1),(
'Super Man', 5),(
'Spider Man', 2),(
'Herr Man', 3),(
'Bat Man', 4
);

INSERT INTO programmer VALUES(
'09-09-2012', 1, 15),(
'12-12-2012', 2, NULL),(
'04-04-2012', 3, 7.5),(
'06-06-2012', 4, 9.7),(
'07-07-2012', 5, 10),(
'08-08-2012', 5, 11.90),(
'01-06-2012', 5, 12.10),(
'10-10-2012', 3, 7.50);

select titre_representation from representation;

select titre_representation from representation where lieu='opera Bastille';

select lieu from representation where lieu like '%p%ra%';

select nom,titre_representation from musicien,representation where musicien.numrepresentation = representation.numrepresentation;

select titre_representation,lieu,tarif from representation,programmer where representation.numrepresentation = programmer.numrepresentation and programmer.date='2012-09-14';

select distinct nom from musicien,representation where musicien.numrepresentation = representation.numrepresentation and representation.titre_representation='Carmen';

select representation.numrepresentation,titre_representation,lieu from representation,programmer where representation.numrepresentation=programmer.numrepresentation and tarif<15;

select titre_representation from representation,programmer where representation.numrepresentation = programmer.numrepresentation and '2012-04-01'<=programmer.date and programmer.date<='2012-04-30';

select date,numrepresentation from programmer where tarif is null;

select nom from musicien,representation where musicien.numrepresentation = representation.numrepresentation and lieu like 'th%tre %';

--Exercice Représentation musicale Chapitre 6

select count(*) from representation;

select distinct count(date) from programmer;

select nom from musicien,representation where musicien.numrepresentation = representation.numrepresentation and representation.lieu like '%asilique %t %ermin' order by musicien.nom ASC;

select avg(tarif) from programmer;

select numrepresentation,count(*) from programmer GROUP BY numrepresentation order by numrepresentation DESC;

select numrepresentation,max(tarif) from programmer where tarif>15 GROUP BY numrepresentation;

select representation.numrepresentation,titre_representation from representation,musicien where musicien.numrepresentation = representation.numrepresentation GROUP BY representation.numrepresentation  ORDER BY count(representation.titre_representation);
-- ( probablement faux )

-- dernière question pas faite 