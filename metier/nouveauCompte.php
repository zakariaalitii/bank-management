<?php
include "../dao/Compte.inc";
$a  = $_POST['numero'];
$b = $_POST['montant'];
$c = $_POST['cin'];


//question 3

nouveauCompte($a,$b,$c);

?>
