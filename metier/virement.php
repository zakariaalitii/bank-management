<?php
include "../dao/Compte.inc";
$a  = $_POST['numero'];
$b  = $_POST['valeur'];

//question 5

virement($a, $b);

?>