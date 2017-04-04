#include<unistd.h>
#include<stdio.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define NB_ELEMENTS 10000

int main(int argn, char** argv)
{
    int f1, f2;
    int nb_car_lu, nb_car_ecrit;
    char tampon [NB_ELEMENTS];

    if(argn != 3)
    {
   	 perror("Erreur nombre arguments");
   	 return 1;
    }
    
     f1 = open(argv[1],O_RDONLY);
    if(f1 == -1)
    {
   	 perror("Erreur sur fichier source");
   	 return 1;
    }

    f2 = open(argv[2],O_WRONLY);

    if(f2 != -1)
    {
   	 close(f2);
   	 f2 = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,00600);
   	 if(f2 == -1)
   	 {
   		 perror("Erreur sur l'appel système write(2)");
   		 return 1;
   	 }
    }
    else
    {
   	 f2 = open(argv[2],O_CREAT|O_WRONLY,00600);
   	 if(f2 == -1)
   	 {
   		 perror("Erreur sur l'appel système write(2)");
   		 return 1;
   	 }
    }
    
    do {
   	 nb_car_lu = read (f1, tampon, NB_ELEMENTS);

   	 if (nb_car_lu<0)
   	 {
   		 perror ("erreur de lecture du fichier source \n");
   		 return 11;
   	 }

   	 nb_car_ecrit = write (f2, tampon, nb_car_lu);

   	 if (nb_car_ecrit != nb_car_lu)
   	 {
   		 perror ("erreur d'ecriture dans le fichier destination \n");
   		 return 21;
   	 }
    	} while ( nb_car_lu>0);

   	 
    close (f1);
    close (f2);
    return 0;
}
