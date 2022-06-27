<?php

require_once("connexion.inc") ;


//question 2
    
 function  existeCompte($numero)
 {    
       global $conn;
    
    $sql = "SELECT numero FROM compte WHERE numero = $numero ";

    $resultat=$conn->query($sql);
   
    $donnees = $resultat->fetchAll();
 
 foreach($donnees as $ligne) if($ligne["numero"]==$numero) return 1;

 return 0;
        
 }

//question 3

  function nouveauCompte($numero,$montant,$cin)
  {
    if(!existeCompte($numero))
    {

    
    global $conn;
    
    $sql = "INSERT INTO compte(numero, montant, cin) VALUES ($numero,$montant,$cin)";
    
    $conn->exec($sql);
  
   
    }
    
  }


 

//question 5

function virement($numero,$valeur)
{
    global $conn;
    
    $sql = "UPDATE compte SET montant=montant+$valeur where numero = $numero";
    
     $conn->exec($sql);
   
  
    

}


//question 8

function debiteurs()
{

   global $conn;
    
    $sql = "SELECT nom ,prenom FROM client INNER JOIN compte ON client.cin = compte.cin WHERE montant<0";
    
     $resultat=$conn->query($sql);
   
    $donnees = $resultat->fetchAll();
 
  foreach($donnees as $ligne)
 
  echo $ligne["nom"]." ".$ligne["prenom"]."<br>";
    


}


?>