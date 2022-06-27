<?php


include "../dao/Client.inc";
include "../dao/Compte.inc";


$a = $_POST['nom'];
$b = $_POST['prenom'];
$c = $_POST['address'];
$d = $_POST['numero'];
$e = $_POST['montant'];
$f = $_POST['cin'];




//question 4

nouveauClient($a,$b,$c,$d,$e,$f);


?>