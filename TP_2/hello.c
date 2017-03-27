#include <unistd.h>
#include <stdio.h>

int main(void)
{
	if(write(1, "Hello world\n", 12) == -1)
	{
		perror("Erreur d'affichage");
		return -1;
	}
	return 0;
}
