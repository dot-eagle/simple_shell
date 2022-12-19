#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	int x;
	char av[] = {"/usr/bin/ls", "-l", "-h", "a", env, NULL};
	
	x =  execve(argv[0], argv, env);
	if (x == -1)
		printf("execve failed\n");
	else
		printf("This doesnt print\n");
	return (0);
}
