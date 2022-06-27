<?php


//question 2
    
 function  existeCompte($numero)
 {    
          $fcompte=fopen("../resources/Compte.txt","r");
          $trouve=0;
          
          while (!feof($fcompte) && (!$trouve ) )
          {
             $ligne=fgets($fcompte,255);
             $rowcompte=explode("|",$ligne);
             if (!isset($rowcompte[0])) break;
             if ((int)$rowcompte[0]==$numero)
               $trouve=1;  
             
          }
          return $trouve;
        }

//question 3

  function nouveauCompte ($numero,$montant,$cin)
  {
            if(existeClient($cin) && !existeCompte($numero))
            {
          $fcompte=fopen("../resources/Compte.txt","a");
          $ligne= $numero ."|" . $montant ."|". $cin;
          
          fputs($fcompte,$ligne."\r\n");
          fclose($fcompte);
            }  
  }


 

//question 5
function virement($numero,$valeur)
{
  $fcompte=fopen("../resources/Compte.txt","r");
  $texte="";
          
  while ( !feof($fcompte) )
    {
            
    $ligne=fgets($fcompte,255);
    $rowcompte=explode("|",$ligne);
      
    if ((int)$rowcompte[0]==$numero) $rowcompte[1]=(int)$rowcompte[1]+(int)$valeur;
    
    $texte=$texte.implode("|",$rowcompte);

    } 

    file_put_contents("../resources/Compte.txt",$texte);
    fclose($fcompte);
}


//question 8

function debiteurs()
{

        $fclient=fopen("../resources/Client.txt","r");
        $fcompte=fopen("../resources/Compte.txt","r");  
  
              while (!feof($fclient) && !feof($fcompte) )
               {
                      $ligne=fgets($fcompte,255);
                      $rowcompte=explode("|",$ligne);
                      $ligne=fgets($fclient,255);
                      $rowclient=explode("|",$ligne);
            
                  
                  if((int)$rowcompte[1]<0 && (int)$rowclient[3]==(int)$rowcompte[2] ) {
                       
                    $rowcompte[2]="";
                    $rowcompte[3]="";
                    echo implode(" ",$rowcompte);
                    echo "<br>";
                    
                 }        

          }

}


?>