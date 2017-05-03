#include <stdio.h>

int main (void)
{
	char c = 'Z';
	int n = 2690;
	float r = 18.415;

	printf("caractère = %c, taille = %d\n", c, sizeof(c));
	printf("entier = %d, taille = %d\n", n, sizeof(n));
	printf("reel = %f, taille = %d\n", r, sizeof(r));
	return 0;
}
