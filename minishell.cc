#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <assert.h>
#include <sys/wait.h>
#include <stdlib.h>
#define NUM  1024
char *args[NUM];
using namespace std;

char **CommandParse(char *str)
{
	assert(str);
	//char *args[NUM];
	int i = 0;
	args[i] = strtok(str, " ");
	while(args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " ");
			//cout << argv[i];
		}
	return args;
	//for(i=0; args[i] !=NULL; i++ ){
	//cout << args[i] << endl;
	//}
}
void ExecCommand(char **args)
{
	assert(args);

	pid_t id = fork();
	if(id < 0)
	{
		cerr << "fork error" << endl;
		return;
	}
	else if(id == 0)//child
	{
		execvp(args[0], args);
		cout << "command not found" << endl;
		//exit(1);
	}
	else//father
	{
		waitpid(id, NULL, 0);	
	}
}

int main ()
{
	char cmd[256];
	char **args;
	string tips="[ljw@localhost~]# ";
	for(;;)
	{
		cout<<tips;
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd)-1] = '\0';
		args = CommandParse(cmd);
		#ifdef DEBUG
		for(int i = 0; args[i] != NULL; i++)
		{
				cout << args[i] <<endl;
		}
		#endif
		ExecCommand(args);
	}
	 return 0;	
}	 
