<?php
do{
    print("Est-ce que tu veux utiliser la calculatrice ? (o/n) : ");
    $rep = trim(fgets(STDIN));
    if($rep != "o" && $rep != "n"){
        print("Saisie incorrecte.\n");
    }
}
while($rep != "o" && $rep != "n");

while($rep == "o"){
    print("Saisir valeur 1 : ");
    $valeur1 = trim(fgets(STDIN));

    print("Saisir opérateur : ");
    $operateur = trim(fgets(STDIN));

    print("Saisir valeur 2 : ");
    $valeur2 = trim(fgets(STDIN));

    switch($operateur){
        case "+":
            $resultat = $valeur1 + $valeur2;
            break;
        case '-':
            $resultat = $valeur1 - $valeur2;
            break;
        case '*':
            $resultat = $valeur1 * $valeur2;
            break;
        case '/':
            $resultat = $valeur1 / $valeur2;
            break;
        default:
            print("Opérateur inconnu\n");
            $resultat = "ERREUR";
    }
    print("Le résultat est $resultat\n\n");

    do{
        print("Est-ce que tu veux continuer ? (o/n) : ");
        $rep = trim(fgets(STDIN));
        if($rep != "o" && $rep != "n"){
            print("Saisie incorrecte.\n");
        }
    }
    while($rep != "o" && $rep != "n");
}
?>