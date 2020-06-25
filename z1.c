#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DEST_SIZE 40


int main(int argc, char *argv[])
{
// przypisanie sciezki z podanego przy uruchamianiu argumentu 
	char *path = argv[1];	
	printf("Podana ścieżka %s\n",path);

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
//otwarcie pliku
	int fp = open(path, O_RDONLY, mode);
	unsigned long counter=0;	
	ssize_t read (int fd, void *buf, size_t len);
	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp);		
	printf("%i",sz);
//dopisanie .red do konca pliku
	
	strcat(path,".red");
	open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
	printf("Ścieżka wyjściowa utworzonego pliku: %s\n",path);


return 1;
}


