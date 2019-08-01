#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo)
{
	printf("get a signal!\n");
	printf("signo is %d\n", signo);
	exit(1);
}

int main()
{
	struct sigaction act, oact;
	//int signo = 2;
	act.sa_handler = handler;
	sigaction(2, &act, &oact);
	while(1)
	{
		printf("witting signal...\n");
	}
}
