#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NB_ELEMENTS 10000

int main (int argc, char ** argv)
{
	int src_desc_fic, dest_desc_fic;
	char tampon[NB_ELEMENTS];
	int nb_car_lu, nb_car_ecrit;
	if (argc  != 3)
	{
		perror("nombre d'arguments incorrects");
		return -1;
	}
	//src_desc_fic = dF1
	int dF1 = open (argv[1], O_RDONLY);
	if (dF1 == -1)
	{
		perror("Fichier source introuvable");
		return -1;
	}
	int dF2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 00600);
	if (dF2 == -1)
	{
		perror("Erreur");
		return -1;
	}
	do
	{
		nb_car_lu=read(dF1, tampon, NB_ELEMENTS);
		if (nb_car_lu<0)
		{
			perror("erreur de lecture du fichier source\n");
			return -1;
		}
		nb_car_ecrit=write(dF2, tampon, nb_car_lu);
		if(nb_car_ecrit != nb_car_lu)
		{
			perror("erreur d'écriture dans le fichier destination");
			return -1;
		}
	}
	while(nb_car_lu>0);

	close(dF1);
	close(dF2);

	return 0;
}
