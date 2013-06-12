#include <stdio.h>
#include <unistd.h>

int worker_process(int cpuid)
{
	pid_t pid;

	pid = getpid();

	for(;;)
	{
		
	}

	return 0;
}

int start_worker_process(int cpuid)
{
	pid_t pid;

	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork");
			return -1;
		case 0:
			worker_process(cpuid);
			break;
		default:
			break;
	}

	return 0;
}

int master_process()
{
	int delay = 10;

	for(;;)
	{
		if(delay)
			sleep(delay);
	}

	return 0;
}

int start_master_process(int n)
{
	for(int i=0; i<n; i++)
	{
		start_worker_process(i);
	}

	master_process();
	return 0;
}
