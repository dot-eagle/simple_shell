#include <stdio.h>

int main()
{
	char str[80], ch;

	scanf("%s", str);
	getchar();
	ch = getchar();

	printf("%s\n", str);
	printf("%d\n", ch);
	printf("%s\n", ch);
	printf("%d\n", str);

	return (0);
}
