#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define DEST_SIZE 40


int main(int argc, char *argv[]) //argc - ilosc podanych argumentow, argv - tablica wypelniona argumentami
{
//wymus wpisanie argumentow
if((argc==1) | (argc>2))
{
	printf("\nNie podano sciezki do pliku lub wprowadzono za duza ilosc argumentow.\n");
	exit(1);
}
// przypisanie sciezki z podanego przy uruchamianiu argumentu 
	char *path = argv[1];	
	printf("Podana ścieżka %s\n",path);
	int i,j=0;	
	int *ptr;
	ptr = &j;
	int fd;
	int fd2;
	char buffer[1000]; 
	ssize_t fBytes;
	char text[5];

//sprawdzenie czy plik otwiera sie poprawnie
	fd = open(path, O_CREAT | O_RDONLY, 00007);
	if(fd==-1)
	{
		printf("\nWystapil blad podczas otwierania pliku.");
	}
//odczytanie zawartości pliku

	fBytes = read(fd,buffer,1000);
	buffer[999]='\0';
	close(fd);

//zapisanie co trzeciego znaku do nowego pliku
	for(int i=0; i<fBytes;i++)
	{
		if(i%3==0)
		{
			text[j]=buffer[i];
			j++;
		}
	}

//dopisanie .red do konca pliku
	
	strcat(path,".red");
	fd2 = open(path,O_RDWR | O_CREAT ,00007);
	printf("Ścieżka wyjściowa utworzonego pliku: %s\n",path);
	write(fd2,text,*ptr);
	close(fd2);
	return 0;


}


