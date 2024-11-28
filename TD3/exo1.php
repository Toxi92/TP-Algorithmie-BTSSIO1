<?php
$somme = 0;

for($i = 0; $i < 3; $i++){  // POUR (Instruction de départ; Condition de fin de boucle; Incrémentation)
    print("[$i] - Saisir entier : ");
    $entier = trim(fgets(STDIN));
    $somme += $entier;  // Pareil que $somme = $somme + $entier;
}
print("La somme vaut $somme.");
?>