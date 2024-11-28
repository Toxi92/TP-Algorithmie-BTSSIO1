<?php
$choix = 0;
define("TAUX", 0.86);

do{
    do{
        print("\n1- Conversion €/£\n2- Conversion £/€\nChoix (1 ou 2) : ");
        $choix = trim(fgets(STDIN));
        if($choix != 1 && $choix != 2){
            print("Saisie incorrecte.\n");
        }
    }
    while($choix != 1 && $choix != 2);

    print("Saisir la somme à convertir : ");
    $somme = trim(fgets(STDIN));

    if($choix == 1){
        $somme_convertie = $somme * TAUX;
        print("La somme convertie vaut $somme_convertie £\n");
    }
    else{
        $somme_convertie = $somme / TAUX;
        print("La somme convertie vaut $somme_convertie €\n");
    }
    
    do{
        print("Voulez-vous continuer ? (o/n) : ");
        $choix = trim(fgets(STDIN));
        if($choix != "o" && $choix != "n"){
            print("Saisie incorrecte.\n");
        }
    }
    while($choix != "o" && $choix != "n");
}
while($choix == "o");
?>