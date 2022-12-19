#include <stdio.h>

int main(int ac, char **av)
{
	int i;

	while (*av != NULL)
	{
		printf("%s\n", *av);
	} av++;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", *av);
	}
	return (0);
}
