#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
int main(int argc, char * argv[])
{	
	int wstatus;
        if(argc!=2)
        {
                printf("\n Nie podano sciezki do pliku lub podano zbyt duza ilosc argumentow.\n");
                exit(1);
        }                                                                                                                                                                                                 char * path = argv[1];
        pid_t pid= fork();
	pid_t child_pid;
        if(pid == -1)
        {
        printf("\nTworzenie procesu zakonczone niepowodzeniem.\n");
        //return 1;
        }
        if(pid ==0)
        {
        //jeśli proces utworzony poprawnie
        printf("Proces utworzony poprawnie z nr %d\n", (int)getpid());
	
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC , 0007);
	if(fd==-1)
	printf("Wystapil problem podczas otwierania pliku %s",path);
	
	char buffer[50];
	int process, ssize;

	for(int i=1; i<11; i++)
	{
	process = (int)getpid();
	ssize=snprintf(buffer, sizeof(buffer), "Wywolanie nr %d. Numer procesu: %d\n",i,process);
	write(fd, buffer, ssize);

	}
	exit(10);
        }
	if(pid>0)
	{
		child_pid = wait(&wstatus);
		if(wstatus ==-1)
		{
		printf("Wystapil blad ");
		}
		if(WIFEXITED(wstatus))
		{
		printf("Zapis do pliku %s zakończony sukcesem",path);
		}
	}
        return 0;
}

