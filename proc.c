#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
	char bar[102];
	int i = 0;
	char lable[4] = "|/-\\";
	memset(bar, '\0', sizeof(bar));
	while(i < 101)
	{
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
		fflush(stdout);
		bar[i]='*';
		i++;
		usleep(10000);
	}
	printf("\n");
	return 0;
}
