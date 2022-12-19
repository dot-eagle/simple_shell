#include <stdio.h>
#include <string.h>


int main(void)
{
	int i = 1, j;
	char str[] = "Whare are we going immediately after school?";
	char *arr[8];

	arr[0] = strtok(str, " ");
	while ((arr[i] = strtok(NULL, " ")) != NULL)
		i++;

	for (j = 0; j < 8; j++)
	{
		if (arr[j] == NULL)
			printf("(nil)\n");
		else
			printf("%s\n", arr[j]);
	}
	return (0);
}
