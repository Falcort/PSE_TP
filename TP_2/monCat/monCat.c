#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char result[1000];
	int tmp[1];
	int nb_char_ecrit = 0, nb_char_lu = 0;
	do
	{
		nb_char_lu = read(0, &tmp, 1);
		if(nb_char_lu == 0)
		{
			write(1, "\n", strlen("\n"));
			return 0;
		}
		nb_char_ecrit = write(1, tmp, nb_char_lu);
		if (nb_char_ecrit != nb_char_lu)
		{
			perror("Erreur");
			return -1;
		}
	}
	while(tmp[0] != '\n');
	return 0;
}
