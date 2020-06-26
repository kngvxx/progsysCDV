#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *path = argv[1];
	int fd = open(path, O_RDONLY);
	int num;
	for(int i=0; i<10;i++)
	{
		read(fd, &num, sizeof(10));
		int multiply =  num*3;
		printf("Liczba %d razy 3 to %d\n",num, multiply);
		
	}
	return 0;
}
