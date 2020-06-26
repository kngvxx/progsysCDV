#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) //argc - ilosc podanych argumentow, argv - tablica wypelniona argumentami
{
//losowanie liczb 
	time_t t;
	int  tab[10];
	int n=10; //ilosc liczb do wygenerowania
	char *path = argv[1];
	printf("Podana ścieżka %s\n",path);
        int fd = open(path, O_CREAT | O_WRONLY , 00007);

	srand((unsigned) time(&t));

for(int k=0; k<n;k++)
{
	tab[k]=rand() %  100;
	printf("Wylosowana liczba nr %i o wartości %i\n",k+1,tab[k]);
}

//wymus wpisanie argumentow
if((argc==1) | (argc>2))
{
	printf("\nNie podano sciezki do pliku lub wprowadzono za duza ilosc argumentow.\n");
	exit(1);
}

// przypisanie sciezki z podanego przy uruchamianiu argumentu 
	if(fd==-1)
	{
		printf("Wystapil blad podczas otwierania pliku z lokalizacji %s",path);
	}
	else
	{
		printf("Plik został otwarty prawidłowo");
	}
// zapis
	write(fd,tab,sizeof(tab));
	close(fd);


	return 0;



}


