<?php


require_once("connexion.inc") ;

//question 1

     
 function  existeClient($cin)
 {    
           global $conn;
    
    $sql = "SELECT cin FROM client WHERE cin = $cin ";

    $resultat=$conn->query($sql);
   
    $donnees = $resultat->fetchAll();
 
 foreach($donnees as $ligne) if($ligne["cin"]==$cin) return 1;
 
 return 0; 
   
        }



//question 4

 function nouveauClient($nom,$prenom,$address,$numero,$montant,$cin)
 {
             if(!existeClient($cin))
    {

     global $conn;
    
     $sql = "INSERT INTO client(nom, prenom, addresse ,cin) VALUES (\"$nom\",\"$prenom\",\"$address\",\"$cin\")";

     $conn->exec($sql);
    

    nouveauCompte($numero,$montant,$cin);
    

    }


 }
 
//question 6

function infos($cin)
{

   global $conn;
    
    $sql = "SELECT nom ,prenom,numero,montant FROM client INNER JOIN compte ON client.cin = compte.cin where client.cin = $cin";
    
     $resultat=$conn->query($sql);
   
    $donnees = $resultat->fetchAll();
 
  foreach($donnees as $ligne)
 
  echo $ligne["nom"]." ".$ligne["prenom"]." ".$ligne["numero"]." ".$ligne["montant"]."<br>";
    

 
}

//question 7
function supprime($CIN)
{
      if( existeClient($CIN) )

      {  
              global $conn;
                
              $sql = "SELECT * FROM client INNER JOIN compte ON client.cin = compte.cin;DELETE FROM client WHERE cin = $cin;";

               $conn->exec($sql);
    
      }
}



?>