<?php
define("LIM1", 2000);
define("LIM2", 10000);
define("LIM3", 20000);

define("TX1", 0.05);
define("TX2", 0.1);
define("TX3", 0.25);
$somme_prime = 0;

for($i = 1; $i <= 5; $i++){
    print("\n--Commercial $i--");

    print("\nSaisir chiffre d'affaire : ");
    $ca = trim(fgets(STDIN));

    if ($ca < LIM1){
        $prime = 0;
    }
    else if ($ca < LIM2){
        $prime = TX1 * ($ca - LIM1);
    }
    else if ($ca < LIM3){
        $prime = TX2 * ($ca - LIM2) + TX1 * (LIM2 - LIM1);
    }
    else{
        $prime = TX3 * ($ca - LIM3) + TX2 * (LIM3 - LIM2) + TX1 * (LIM2 - LIM1);
    }

    print("\nPrime à toucher (Commercial $i) = $prime €");
    $somme_prime = $somme_prime + $prime;
}

$moyenne_prime = $somme_prime / 5;
print("\n\nMontant total des primes distribués : $somme_prime €");
print("\nMoyenne des primes : $moyenne_prime €");
?>