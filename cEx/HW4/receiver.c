//201835546_Hamgeonwook

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF	1024

int main(int argc, char* argv[])
{
pid_t pid;

	pid = fork();

	if (pid < 0)//error
	{
		printf("Fork Failed\n");
		return 1;
	}
	else if (pid == 0)// son process
	{
		printf("son made\n");
		execlp("/bin/ls", "ls", NULL);
	}
	else // parent process
	{
		//make dau process
		pid=fork();
	}

	// init global variable
	char ch, tch;
	int terminate = 0;

	// init named pipe
	char message[MAX_BUF];
	int file_desc_son;
	int file_desc_dau;
	int cnt;

	// open named fifo
	char* fifo_son = "/tmp/hw3_fifo_son";
	char* fifo_dau = "/tmp/hw3_fifo_dau";
	file_desc_son = open(fifo_son, O_RDONLY);
	file_desc_dau = open(fifo_dau, O_RDONLY);

	// unlink fifo
	unlink(fifo_son);
	unlink(fifo_dau);

	return 0;
}