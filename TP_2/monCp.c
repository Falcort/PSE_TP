#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char ** argv)
{
	if (argc  != 3)
	{
		perror("nombre d'arguments incorrects");
		return -1;
	}
	int dF1 = open (argv[1], O_RDONLY);
		if (dF1 == -1)
		{
			perror("Fichier source introuvable");
			return -1;
		}
	int dF2 = open (argv[2], O_WRONLY | O_CREAT);
	if (dF2 == -1)
	{
		perror("Fichier destination introuvable");
		if (close(dF1) == -1)
		{
			perror("problème de fermeture");
			return -1;
		}
		char data[10000];
		if (read(dF1, data, 9999) < 0)
		{
			perror("erreur de lecture");
			close (dF1);
			close (dF2);
			return -1;
		}
		if (write(dF2, data, strlen(data)) < 0)
		{
			perror("problème d’écriture");
			close (dF1);
			close (dF2);
			return -1;
		}
		close (dF1);
		close (dF2);
		return 0;
	}
}
