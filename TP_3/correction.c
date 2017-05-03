Identite lecture_personne(int fd)
{
	Identite personne;
  	int nb_car_lu = read(fd, &personne, sizeof(Identite));
  	if(nb_car_lu == 0)
  	{
    		persone.age = -1;
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
	int nb_car_ecrit, fd = open(filename, 0_CREAT|O_WRONLY|O_APPEND,00600);

	if (fd>0)
	{
		saisie_personne($personne);
		nb_car_ecrit = write(fd, $personne, siezof(Identite));
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
