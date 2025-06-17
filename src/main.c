#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"events.h"

int main()
{

char f_Event[55];
int num;
char nom_ev [50] ;
char nom [50] ;
char pren[50] ;
list_ev *debut =NULL ;
listp *start =NULL ;

while(num!=7){
        printf("------------------------------MENU:-------------------------------------------\n\n");
printf("\t\t   1. Inscription d'un participant .\n");
printf("\t\t   2. Ajout d'un evenement.\n");
printf("\t\t   3. Enregistrement des resultats . \n");
printf("\t\t   4. Affichage des evenements et participants :.\n");
printf("\t\t   5. Sauvegarde des informations dans un fichier .\n");
printf("\t\t   6. Chargement des informations depuis un fichier .\n");
printf("\t\t   7. Terminer . \n");
printf("----------------------------------------------------------------------------------\n\n");

 printf("-->Veuillez saisir un numero a partir de MENU (1,2...,7) :");
 scanf("%d",&num);
 printf("\n\n");
  switch(num){
    case 1:start=Ajout_participant(start) ;
    break;
    case 2:debut=Ajout_Event(debut,start) ;

    break;
    case 3:
           printf("-->Veuillez saisir le nom de l'evenement :");
           scanf(" %[^\n]s",&nom_ev);
           printf("-->Veuillez saisir le nom de participant :");
           scanf(" %[^\n]s",&nom);
           printf("-->Veuillez saisir le prenom de participant :");
           scanf(" %[^\n]s",&pren);
           debut=Update_result(debut,nom,pren,nom_ev) ;
    break;
    case 4: afficher_ListeEvent(debut);

    break;
    case 5:printf("-->Veuillez saisir le fichier pour sauvegarde les  informations des evenements :");
           scanf(" %[^\n]s",&f_Event);
           printf("\n");
           Sauvegarde_Event(f_Event,debut) ;
    break;
    case 6:printf("-->Veuillez saisir le fichier pour le Chargement des informations  :");
           scanf(" %[^\n]s",&f_Event);
           printf("\n");
           Charge_Event(f_Event) ;
    break;

    case 7:printf("----------------Au Revoir ;)!------------------\n") ;
    break;
    default :printf("\n (-_-)-->Ce numero n'existe pas dans le MENU \n\n") ;
  }
}
    return 0;
}
