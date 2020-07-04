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
        if(argc!=2)
        {
		printf("\n Nie podano sciezki do pliku lub podano zbyt duza ilosc argumentow.\n");
                exit(1);
	}                                                                                                                                                                                                                             }                                                                                                                                                                                                                                            char * path = argv[1];
        pid_t pid = fork();
	if(pid == -1)
	{
	printf("\nTworzenie procesu zakonczone niepowodzeniem.\n");
	return 1;
	}
	if(pid ==0)
	{
	//jeśli proces utworzony poprawnie
	printf("Proces utworzony poprawnie z nr %d", (int)getpid());
	}
        return 0;
}
