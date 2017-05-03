#include <string.h>
#include <stdio.h>

int main(int argn, char** argv)
{
	int i;
	if (argn > 1)
	{
		for(i=1; i < argn; i++)
		{
			if(write(1, argv[i], strlen(argv[i])) == -1)
			{	
				perror("Erreur");
				return -1;
			}
			if(i != argn-1)
			{
				if(write(1, " ", 1) == -1)
				{
					perror("Erreur");
					return -1;
				}
			}
		}
	}
	if(write(1, "\n", 1) == -1)
	{
		perror("Erreur");
		return -1;
	}
	return 0;
}
