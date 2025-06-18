#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

typedef struct data{
char nom[50] ;
char prenom[50];
int  Age ;
char sport[66];
int result;
}data ;
typedef struct listp{
data particpant ;
struct listp * next;
struct listp * prev;
}listp ;


typedef struct Date{
int jour ;
int mois ;
int annee ;
}Date ;
typedef struct data_event{
char nom_ev[50] ;
Date date;
char Type_spr[66];
listp *list_paricipant ;
}data_event ;
typedef struct list_ev{
data_event evenement;
struct list_ev * next;
struct list_ev * prev;
}list_ev ;

listp * sais_partcipant(){
listp *p ;
p =(listp *)malloc(sizeof(listp));
if(p==NULL){
    perror("Erreur d'allocation  !!");
    exit(0);
    }
     printf("\n (^-^)-->Saisir les  informations de nouveau participant : \n");
     printf("Nom : ");
     scanf(" %[^\n]s",&p->particpant.nom);

     printf("Prenom : ");
     scanf(" %[^\n]s",&p->particpant.prenom);

     printf("Age : ");
    scanf("%d",&p->particpant.Age);

     printf("Sport : ");
    scanf(" %[^\n]s",&p->particpant.sport);
    p->particpant.result=0;
     printf("\n");

p->next=p->prev=NULL ;
return p ;
}
listp *  Ajout_participant(listp *debut){

listp* tmp =debut ;
listp* cel ;
cel=sais_partcipant() ;

if(debut==NULL){
 debut= cel;
 return debut ;
}

while(tmp->next!=NULL)
   tmp=tmp->next ;

cel->prev=tmp ;
tmp->next=cel;

return debut ;
}

listp * Participant_event(listp *debut,listp *partc_ev,char * spr_ev){

listp * tmp = debut ;
listp * tmp2  ;

if(debut==NULL){
 printf("!!-->ERREUR:la liste des participants est vide !!!");
 return ;
 }


 if(debut==NULL){
 printf("!!-->ERREUR:la liste des participants est vide !!!");
 return debut ;
 }

while(tmp!=NULL){

  if (strcmp(tmp->particpant.sport,spr_ev ) == 0 ){

listp * p_ev ;
p_ev=(listp *)malloc(sizeof(listp));
if(p_ev==NULL){
    perror("\n Erreur d'allocation  !! \n ");
    exit(0);
    }

p_ev->next=p_ev->prev=NULL ;
strcpy(p_ev->particpant.nom,tmp->particpant.nom) ;
 strcpy(p_ev->particpant.prenom,tmp->particpant.prenom);
 p_ev->particpant.Age=tmp->particpant.Age ;
 strcpy(p_ev->particpant.sport,tmp->particpant.sport) ;
  p_ev->particpant.result= 0 ;

 if(partc_ev==NULL)
 partc_ev = p_ev;

else {
tmp2=partc_ev ;
//int cmp=0 ;
while(tmp2->next!=NULL)
    tmp2=tmp2->next ;


p_ev->prev=tmp2 ;
tmp2->next=p_ev;

}
}
//tmp2=p_ev ;
 tmp=tmp->next ;
  }
return partc_ev ;
}

list_ev * sais_Event(listp * debut){
list_ev *ev ;
ev =(list_ev *)malloc(sizeof(list_ev));
if(ev==NULL){
    perror("Erreur d'allocation  !!");
    exit(0);
    }
     printf("\n (^-^)-->Saisir les  informations de nouvel evenement : \n");
     printf("Nom de l'evenement : ");
     scanf(" %[^\n]s",&ev->evenement.nom_ev);

     printf(" Date de l'evenement : \n");
     printf("-->Jour : ") ;
     scanf(" %d",&ev->evenement.date.jour);
     printf("-->Mois : ") ;
     scanf(" %d",&ev->evenement.date.mois);
     printf("-->Annee : ") ;
     scanf(" %d",&ev->evenement.date.annee);

     printf(" (!!</d'apres ma comprehension du programme> -->je prend 'type de sport' comme sport et que tous les participant qui ont faire cette sport sont participee a ce evenement !!)\n Type de sport : ");
     scanf(" %[^\n]s",&ev->evenement.Type_spr);
     printf("\n");

    ev->evenement.list_paricipant=NULL ;
    ev->evenement.list_paricipant=Participant_event(debut,ev->evenement.list_paricipant,ev->evenement.Type_spr) ;


ev->next=ev->prev=NULL ;
return ev;
}
list_ev *  Ajout_Event(list_ev *debut,listp *start){

list_ev * tmp =debut ;
list_ev * cel ;
cel=sais_Event(start) ;

if(debut==NULL){
 debut= cel;
 return debut ;
}

while(tmp->next!=NULL)
   tmp=tmp->next ;

cel->prev=tmp ;
tmp->next=cel;

return debut ;
}

void afficher_ListeEvent(list_ev *debut){

list_ev *tmp=debut;
listp * tmp2;
int cmp =0 ,cmt=0 ;
if (debut==NULL){
    perror("\n!-->ERREUR : la liste des evenements est vide (-_-) \n");
    return ;
}
     printf("\n (^_^)==>Voici les informations des evenements .\n \n") ;
     while(tmp!=NULL){
     cmp++ ;
     printf("\n --------------------les informations de l'evenement : %d --------------------------------------\n",cmp);
     printf(" Nom de l'evenement est : %s \n",tmp->evenement.nom_ev);
     printf(" Date de l'evenement est (JJ/MM/AA): %d/%d/%d \n",tmp->evenement.date.jour,tmp->evenement.date.mois,tmp->evenement.date.annee);
     printf(" Type de sport  : %s \n",tmp->evenement.Type_spr);

     tmp2=tmp->evenement.list_paricipant ;
      printf("\n******** Voici  les informations des participants de l'evenement %d : ********\n",cmp) ;
     while(tmp2!=NULL){
     cmt++ ;
     printf(" -->les informations de participant  %d : \n",cmt) ;
     printf(" Nom : %s \n",tmp2->particpant.nom);
     printf(" Prenom : %s \n",tmp2->particpant.prenom);
     printf(" Age : %d \n",tmp2->particpant.Age);
     printf(" Sport : %s \n",tmp2->particpant.sport);
     printf(" Resultat : %d \n",tmp2->particpant.result);

     tmp2=tmp2->next ;
     }
     printf("-------------------------------------------------------------------------------------------------") ;
     printf("\n");

        tmp=tmp->next ;
     }
     printf("\n");
    }


void Sauvegarde_Event(char *f_event,list_ev *debut ){
FILE *fw;
list_ev * tmp =debut ;
listp *tmp2 ;
int cmt = 0 , cmp=0;

fw= fopen(f_event,"a");
if(fw==NULL){
   printf("Erreur d'ouverture de fichier '%s' .!",f_event);
   return ;
}

     while(tmp!=NULL){
     cmp++ ;
     fprintf(fw,"\n\n ------------------------Les informations de l'evenement %d :-----------------------\n",cmp) ;
     fprintf(fw," Nom de l'evenement  : %s \n",tmp->evenement.nom_ev);
     fprintf(fw," Date de l'evenement  (JJ/MM/AA): %d/%d/%d \n",tmp->evenement.date.jour,tmp->evenement.date.mois,tmp->evenement.date.annee);
     fprintf(fw," Type de sport  : %s \n",tmp->evenement.Type_spr);

     tmp2=tmp->evenement.list_paricipant ;
      fprintf(fw,"\n\n ************** les informations des participants de l'evenement %d : *************\n",cmp) ;
      cmt=0;
     while(tmp2!=NULL){
     cmt++ ;
     fprintf(fw," -->les informations de participant  %d :\n",cmt) ;
     fprintf(fw," Nom : %s \n",tmp2->particpant.nom);
     fprintf(fw," Prenom : %s \n",tmp2->particpant.prenom);
     fprintf(fw," Age : %d \n",tmp2->particpant.Age);
     fprintf(fw," Sport : %s \n",tmp2->particpant.sport);
     fprintf(fw," Resultat : %d \n",tmp2->particpant.result);

     tmp2=tmp2->next ;
     }
     fprintf(fw,"\n-------------------------------------------------------------------------------- \n\n") ;

        tmp=tmp->next ;
     }

 printf("\n (^_^) !!--> Sauvegarde avec success .\n") ;
  fclose(fw);
}

void Charge_Event(char *f_Event){

FILE *ev;
char aff_event[555];

ev= fopen(f_Event, "r");
  if(ev==NULL){
   printf("Erreur d'ouverture de fichier '%s'  !",f_Event);
   return ;
  }
     while(fscanf(ev," %[^\n]s",aff_event)==1 ) {
         printf(" %s \n\n",aff_event);
     }

    fclose(ev);
}

list_ev * Update_result(list_ev * debut,char * nom ,char *prenom ,char *nom_ev ){

  list_ev * tmp = debut ;
  listp * tmp2 =NULL;
 if(debut==NULL){
 printf("\n!!-->ERREUR:la liste des evenements  est vide !!!\n");
 return debut;
 }

while(tmp!=NULL){
  if(strcmp(tmp->evenement.nom_ev,nom_ev)==0 ) {

  tmp2 = tmp->evenement.list_paricipant ;

  if(tmp2==NULL){
    printf("!!-->ERREUR:la liste des participants de l'evenemet '%s'  est vide !!!",nom_ev);
    return debut;
 }
  while(tmp2!=NULL){
  if(strcmp(tmp2->particpant.nom,nom)==0 && strcmp(tmp2->particpant.prenom,prenom)==0 ) {
    printf("\n---->Inserer le resultat de '%s %s' :\n",nom,prenom) ;
     printf("Resultat  : ");
    scanf(" %d",&tmp2->particpant.result);
     printf("\n");
     printf("\n  mettre a jour de resultat avec success .\n");
    return debut ;
  }
  tmp2=tmp2->next ;

  }
  if(tmp2==NULL){
    printf("\n !ERREUR: Ce participant n'existe pas dans la liste des participants de l'evenemet '%s'  \n \n!!",nom_ev);
   return debut ;
  }
  break ;
}
 tmp=tmp->next ;
}
   if(tmp==NULL)
    printf("\n !ERREUR: Ce evenement '%s' n'existe pas dans la liste des evenement . \n \n!!",nom_ev);

    return debut ;
}
#endif
