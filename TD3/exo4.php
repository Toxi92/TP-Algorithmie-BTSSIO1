<?php
$totalmoyenne = 0;
$nbetudiant= 0;

do{
    $moyenne = 0;
    $nbnote = 0;
    do{
        do{
            print("Veuillez saisir une note entre 0 et 20 :");
            $note = trim(fgets(STDIN));
            if ($note < 0 || $note > 20){
                print ("Saisie incorrecte.\n");
            }
        }
        while($note < 0 || $note > 20);

        $nbnote++;  // Pareil que nbnote = nbnote + 1;
        $moyenne += $note;
        
        do{
            print("Voulez-vous continuer (o/n) : ");
            $choix = trim(fgets(STDIN));
            if ($choix != "o" && $choix != "n"){
                print("Saisie incorrecte.\n");
            }
        }
        while($choix != "o" && $choix != "n");
    }
    while($choix == "o" && $nbnote < 5);

    $moyenne /= $nbnote;
    print("La moyenne de l'etudiant est de $moyenne\n");

    $nbetudiant++;
    $totalmoyenne += $moyenne;
    do{
        print("Voulez-vous continuer (o/n) :");
        $choix = trim(fgets(STDIN));
        if ($choix != "o" && $choix != "n"){
            print("Saisie incorrecte.\n");
        }
    }
    while($choix != "o" && $choix != "n");
}
while($choix == "o" && $nbetudiant < 30);

$totalmoyenne/=$nbetudiant;
print ("La moyenne de la classe est de $totalmoyenne");
?>