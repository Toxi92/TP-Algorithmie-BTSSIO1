<?php
#Question codées du TP 2 du B1
// print("Entrez une la somme à convertir : ");
// $somme=trim(fgets(STDIN));
// print("Entrez votre devise 'euros' ou 'livres' : ");
// $devise=trim(fgets(STDIN));
// switch($devise){
//   case 'euros':$somme=$somme*0.84;
//     print("Votre somme en Euros fait ".$somme.'£');
//     break;
//   case 'livres':$somme=$somme*1.18;
//     print("Votre somme en Livres fait ".$somme.'€');
//     break;
// }

/*
print("Premier chiffre : ");
$c1=trim(fgets(STDIN));
print("Opération (+ - * /) : ");
$op=trim(fgets(STDIN));
print("Deuxieme chiffre : ");
$c2=trim(fgets(STDIN));
switch($op){
  case '+':print($c1.$op.$c2.' = '.$c1+$c2);
    break;
  case '-':print($c1.$op.$c2.' = '.$c1-$c2);
    break;
  case '*':print($c1.$op.$c2.' = '.$c1*$c2);
    break;
  case '/':
    if($c2==0){print('Pas de division par 0')}
    else{
      print($c1.$op.$c2.' = '.$c1/$c2);
      break;
    }
    break;
  default:
    print('Opérateur inconnu');
}
*/
/*
$lim1=2000;
$lim2=10000;
$lim3=20000;
$tx1=0.05;
$tx2=0.1;
$tx3=0.25;
$prime=0;
print("Entrez le chiffre d'affaire : ");
$ca=trim(fgets(STDIN));
switch($ca){
  case $ca>=$lim3:
    $prime=($tx1*($ca-$lim1))+($tx2*($ca-$lim2))+$tx3*($ca-$lim3);
    print("La prime de l'employé est de ".$prime."€");
    break;
  case $ca>=$lim2:
    $prime=($tx1*($ca-$lim1))+($tx2*($ca-$lim2));
    print("La prime de l'employé est de ".$prime."€");
    break;
  case $ca>=$lim1:
    $prime=$tx1*($ca-$lim1);
    print("La prime de l'employé est de ".$prime."€");
    break;
  case $ca<$lim1:print("Pas de prime");break;
}
*/
