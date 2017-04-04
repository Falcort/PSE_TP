#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

#define NB_ELEMENTS 10000

int main(int argn, char** argv)
{
	int nb_car_lu, dF1, dF2, nb_car_ecrit;
    	char buffer[NB_ELEMENTS];
	if(!(argn == 3))
    	{
   		perror("Erreur nombre arguments\n");
   	 	return -1;
    	}
     	if((dF1 = open(argv[1],O_RDONLY)) == -1)
    	{
   	 	perror("Erreur sur fichier source\n");
   	 	return -1;
    	}
    	if((dF2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
	{
		perror("Erreur de lecture\n");
		return -1;
	}
    	do
	{
   	 	if((nb_car_lu = read(dF1, buffer, NB_ELEMENTS)) == -1)
   	 	{
   		 	perror ("erreur de lecture du fichier source \n");
   		 	return -1;
   	 	}
   	 	if((nb_car_ecrit = write (dF2, buffer, nb_car_lu))== -1)
   	 	{
   		 	perror ("erreur d'ecriture dans le fichier destination \n");
   		 	return -1;
   	 	}
	}
	while (nb_car_lu != 0);
    	if(close (dF1) || close (dF2))
	{
		perror("Erreur de fermeture\n");
		return -1;
	}
    	return 0;
}
