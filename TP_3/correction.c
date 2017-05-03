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
      			case 0:
				printf("fin du programme\n");
      				break;

      			case 1:
				affichage(argv[1]);
      				break;
      			case 2:
				affichage_personne(argv[1]);
      				break;
      			case 3:
				ajout_personne(argv[1]);
      				break;
      			case 4:
				modification_personne(argv[1]);
      				break;
			default:
				fprintf(stderr,"choix incorrect\n");
    		}
  	}
	while(choix!=0);
  	return 0;
}

Identite lecture_personne(int fd)
{
	Identite personne;
  	int nb_car_lu = read(fd, &personne, sizeof(Identite));
  	if(nb_car_lu == 0)
  	{
    		personne.age = -1;
  	}
  	else
	{
		if(nb_car_lu != sizeof(Identite))
  		{
    			perror("erreur de lecture du fichier|n");
    			exit(1);
  		}
	}
  	return personne;
}

void ajout_personne(char* filename)
{
	Identite personne;
	int nb_car_ecrit, fd = open(filename, O_CREAT|O_WRONLY|O_APPEND,00600);

	if (fd>0)
	{
		saisie_personne($personne);
		nb_car_ecrit = write(fd, $personne, sizeof(Identite));
		if(nb_car_ecrit != sizeof(Identite))
		{
			perror("Erreur de l'apell systeme write (2)");
		}
		close(fd);
	}
	else
	{
		perror("erreur d'ouverture en mise a jour du fichier\n");
	}
}
