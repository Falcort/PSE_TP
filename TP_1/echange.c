#include <stdio.h>

void echange (int *p, int *q)
{
	int tmp;
	printf("Dans la fcontion, avant la permutatin des variables p=%d q=%d\n", *p, *q);
	tmp=*p;
	*p=*q;
	*q=tmp;
	printf("dans la fonction, apres permutation de variables p=%d q=%d\n",*p, *q); 
}


int main (void)
{
	int x = 3, y = 5;
	printf("Dans le programme principal, avant l'appel de la fonction x=%d y=%d\n", x, y);
	echange (&x,&y);
	printf("dans le programme principal, apres l'appel de la fonction x=%d y=%d\n", x, y);
	return 0;
}
