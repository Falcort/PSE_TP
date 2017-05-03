#include <stdio.h> // fprintf(3), stderr(3), printf(3), scanf(3)
#include <stdlib.h> // exit(3)
#include <unistd.h>
#include <fcntl.h>

#define NB_ELEMENTS 30

typedef struct
{
  char nom[NB_ELEMENTS];
  char prenom[NB_ELEMENTS];
  int age;
}Identite;

void saisie_personne(Identite*);
Identite lecture_personne(int);
void affichage(char*);
void affichage_personne(char*);
void ajout_personne(char*);
void modification_personne(char*);
int verrouillage(int,int,int);
void deverrouillage(int,int);

int main(int argn,char** argv)
{
  int choix;

  if(argn<2)
  {
    fprintf(stderr,"Usage: ./%s nom_fichier\n",argv[0]);
    return 1;
  }

  do
  {
    printf("0-Quitter\n1-Affichage de l'ensemble des personnes\n2-Affichage d'une personne\n3-Ajout d'une personne\n4-Modification d'une personne\n");
    printf("Choix: ");
    scanf("%d",&choix);

    switch(choix)
    {
      case 0: printf("fin du programme\n");
      break;

      case 1: affichage(argv[1]);
      break;
      case 2: affichage_personne(argv[1]);
      break;
      case 3: ajout_personne(argv[1]);
      break;
      case 4: modification_personne(argv[1]);
      break;

      default: fprintf(stderr,"choix incorrect\n");
    }
  }while(choix!=0);

  return 0;
}

// procédure qui demande la saisie au clavier de l'identité d'une personne
void saisie_personne(Identite* personne)
{
  printf("nom de famille (trente caracteres au maximum) : ");
  scanf("%s",personne->nom);
  printf("prenom         (trente caracteres au maximum) : ");
  scanf("%s",personne->prenom);
  do
  {
    printf("age                                           : ");
    scanf("%d",&personne->age);
  }while(personne->age<0 || personne->age>150);
}

// fonction qui a en paramètre un descripteur de fichier
//  et qui renvoie une variable de type Identite, lue dans le fichier si elle existe, sinon la variable a un age égal a -1.
// La fonction lecture_personne utilise l'appel système read(2).
Identite lecture_personne(int fd)
{
  Identite personne;
  int nb_car_lu = read(fd, &personne, sizeof(Identite));
  if(nb_car_lu == 0)
  {
    persone.age = -1;
  }
  else
  if(nb_car_lu != sizeof(Identite))
  {
    perror("erreur de lecture du fichier|n");
    exit(1);
  }
  return personne;
}

// procédure qui a en paramètre un nom de fichier
// et qui affiche l'identité de l'ensemble des personnes contenues dans le fichier
// La procédure affichage utilise la fonction lecture_personne et les appels système open(2) et close(2).
void affichage(char* filename)
{
  Identite personne;
  int fd;
  fd = open(2, filename, RONLY);
  read(2, filename, sizeof(fd));
  close(fd);

}

// procédure qui a en paramètre un nom de fichier,
// qui demande la saisie au clavier du numéro d'une personne (numérotée à partir de 1)
// puis qui affiche l'identité de cette personne
// La procédure affichage_personne utilise la fonction lecture_personne et les appels système open(2) et close(2).
void affichage_personne(char* filename)
{
  Identite personne;
  int num_personne,i,fd;
  fd = personne;
  read(2, filename, sizeof(fd));
}

// procédure qui a en paramètre un nom de fichier
// et qui ajoute l'identité d'une personne en fin de fichier
// La procédure ajout_personne utilise la procédure saisie_personne et les appels système open(2), write(2) et close(2).
void ajout_personne(char* filename)
{
  Identite personne;
  int nb_car_ecrit,fd;
  saisie_personne(personne);
  int nb_car_ecrit = open(personne, O_WRONLY | O_APPEND);
   if (nb_car_ecrit < 0) {
       exit;
   }
  open(2, fd, O_APPEND | O_WRONLY);
  for (int i = 0; i < 2; i++) {
    write(2, fd, snb_car_ecrit);
  }
  close(2, fd);
}

// procédure qui a en paramètre un nom de fichier
// et qui modifie toute l'identité d'une personne dans le fichier
// La procédure modification_personne utilise la fonction lecture_personne, la procédure saisie_personne et les appels système open(2), write(2) et close(2).
void modification_personne(char* filename)
{
  Identite personne;
  int num_personne,i,nb_car_ecrit,fd;
}

// procédure qui a en paramètre un descripteur de fichier,
// qui verrouille le fichier en utilisant la fonction lockf(3)
// et qui renvoie la valeur 1 si un verrou a été posé, 0 sinon
// variante=1 : verrouillage bloquant
// variante=2 : verrouillage non bloquant
int verrouillage(int fd, int offset, int variante)
{
}

// procédure qui a en paramètre un descripteur de fichier
// et qui deverrouille un fichier en utilisant la fonction lockf(3)
void deverrouillage(int fd, int offset)
{
}

