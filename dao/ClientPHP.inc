<?php


//question 1

     
 function  existeClient($cin)
 {    
          $fclient=fopen("../resources/Client.txt","r");
          $trouve=0;
          
          while (!feof($fclient) && !$trouve ) 
          {
            
             $ligne=fgets($fclient,255);
             $rowclient=explode("|",$ligne);
             if (!isset($rowclient[3])) break;
             if ((int)$rowclient[3]==$cin) $trouve=1;  
          
          }
          echo $trouve;
          return $trouve;
        }



//question 4

 function nouveauClient($nom,$prenom,$address,$numero,$montant,$cin)
 {

          $fclient=fopen("../resources/Client.txt","a");
            if(!existeClient($cin))
            {
          $ligne= $nom ."|" . $prenom ."|" . $address ."|" . $cin; 
          fputs($fclient,$ligne."\r\n");
          fclose($fclient);
         
            }  
          nouveauCompte($numero,$montant,$cin);

 }
 
//question 6

function infos($cin)
{
        $fclient=fopen("../resources/Client.txt","r");
        $fcompte=fopen("../resources/Compte.txt","r");  
         
          while (!feof($fclient) && !feof($fcompte))
          {
             $ligne=fgets($fclient,255);
             $rowclient=explode("|",$ligne);
             $ligne=fgets($fcompte,255);
             $rowcompte=explode("|",$ligne);
             
             if ((int)$rowclient[3]==$cin){
               $rowclient[2]="";
               $rowclient[3]="";
              echo implode(" ",$rowclient);
              echo "<br>";
             } 
             if ((int)$rowcompte[2]==$cin){
               $rowcompte[2]="";
              echo implode(" ",$rowcompte);
              echo "<br>";
             } 
          }
        
fclose($fcompte); 
fclose($fclient);
}

//question 7
function supprime($cin)
{
        $fclient=fopen("../resources/Client.txt","r");
        $fcompte=fopen("../resources/Compte.txt","r");  

        $texteclient="";
        $textecompte="";
            
          while (!feof($fclient) && !feof($fcompte))
          {
             $ligne=fgets($fclient,255);
             $rowclient=explode("|",$ligne);
              $ligne=fgets($fcompte,255);
             $rowcompte=explode("|",$ligne);
             
             if (!((int)$rowclient[3]==$cin)) $texteclient=$texteclient.implode("|",$rowclient);
             if (!((int)$rowcompte[2]==$cin)) $textecompte=$textecompte.implode("|",$rowcompte);

          }
          file_put_contents("../resources/Client.txt",$texteclient);
          file_put_contents("../resources/Compte.txt",$textecompte);

fclose($fcompte); 
fclose($fclient);

}



?>