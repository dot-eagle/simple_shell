
#include "shell.h"

/**
 * _memcpy - copies n bytes form the memory area
 * src to memory area dest
 * @src: source code to copy
 * @n: how many bytes to copy
 * @dest: destination to copy to
 *
 * Return: dest;
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _memset - sets first n bytes of the memory area
 * @b: what to set it to
 * @n: first n bytes
 * @s: array to set
 *
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _strcat - appends strings
 * @src: what to append
 * @dest: destination to append
 *
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncat - concatenates one string
 * (number of byte given) to another
 * @n: how many bytes to
 * @src: string to concatenate
 * @dest: where to concatenate
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strstr - finds the first occurence of the substring needle
 * needle in the string haystack
 * @haystack: string to search
 * @needle: string to find
 *
 * Return: pointer to the beginning of the located substring
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *beginning = haystack;
		char *pattern = needle;

		while (*pattern == *haystack && *pattern != '\0'
				&& *haystack != '\0')
		{
			haystack++;
			pattern++;
		}

		if (*pattern == '\0')
		{
			return (beginning);
		}
		haystack = beginning + 1;
	}
	return (NULL);
}
