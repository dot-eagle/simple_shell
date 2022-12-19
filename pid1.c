#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char ch;
	printf("%u\n", getpid());
	ch = getchar();
	printf("%u\n", ch);
	return (0);
}
