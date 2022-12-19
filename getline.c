#include <stdio.h>

int main()
{
	char *lineptr = NULL;
	size_t n = 0;

	printf("$ ");
	getline(&lineptr, &n, stdin);
	printf("%s ", lineptr);

	return (0);
}
