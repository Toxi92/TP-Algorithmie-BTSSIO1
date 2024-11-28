<?php
do{
    print("Voulez-vous calculer une factorielle (o/n) : ");
    $rep = trim(fgets(STDIN));
    if($rep != "o" && $rep != "n"){
        print("Saisie incorrecte.\n");
    }
}
while($rep != "o" && $rep != "n");

while($rep == "o"){ // TANT QUE $rep == "o" est VRAI
    print ("Veuillez saisir un entier : ");
    $entier = trim(fgets(STDIN));

    $factorielle = $entier;
    for($i = $entier - 1; $i > 0; $i--){
        $factorielle *= $i; // Pareil que $factorielle = $factorielle * $i
    }

    print("La factorielle de $entier vaut $factorielle.\n");

    do{
        print("Voulez-vous calculer une factorielle (o/n) : ");
        $rep = trim(fgets(STDIN));
        if($rep != "o" && $rep != "n"){
            print("Saisie incorrecte.\n");
        }
    }
    while($rep != "o" && $rep != "n");
}
?>