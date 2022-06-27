 <?php

// préparation des informations nécessaires 

define("DSN","mysql:host=localhost;dbname=Banque"); 
define("USER","root");
define("MDP","");

 // création d'un objet PDO et connexion 
try {
$conn=new PDO(DSN,USER,MDP);

} catch (Exception $erreur) {
echo "Erreur : "; 
exit();
}
?> 
