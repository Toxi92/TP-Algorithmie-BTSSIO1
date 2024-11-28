<?php
$somme = 0;
$nbr_valeur = 0;

do{ // FAIRE TANT QUE $choix est différent de "n"
    print("Saisir entier : ");
    $valeur = trim(fgets(STDIN));
    $somme += $valeur;
    $nbr_valeur += 1;

    do{ // FAIRE TANT QUE $choix est différent de "o" et de "n"
        print("Voulez-vous continuer ? (o/n) : ");
        $choix = trim(fgets(STDIN));
        if ($choix != "o" && $choix != "n"){    // Si il appuie autre chose que "o" et "n", affiche un message d'erreur
            print("Saisie incorrecte.\n");
        }
    }
    while($choix != "o" && $choix != "n");
}
while($choix == "o");

$moyenne = $somme / $nbr_valeur;
print("La moyenne est de $moyenne");
?>