#include "shell.h"

/**
 * _str_match - See if two strings are matching
 * Description: Returns a match if either string reaches '\0' or space
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if match, 0 if not match
 */

int _str_match(char *s1, char *s2)
{
	int u;

	if (s1 == NULL || s2 == NULL)
		return (0);

	for (u = 0; s1[u] == s2[u]; u++)
	{
		if (s1[u] == '\0' || s2[u] == '\0')
		{
			return (1);
		}
		if (_is_whitespace(s1[u]) || _is_whitespace(s2[u]))
		{
			return (1);
		}
	}
	if (s1[u] == '\0' || s2[u] == '\0')
	{
		return (1);
	}
	if (_is_whitespace(s1[u]) || _is_whitespace(s2[u]))
	{
		return (1);
	}
	return (0);
}

/**
 * string_match - Find if strings match, w multiple delims to stop the match
 * Description: '\0' is ALWAYS a condition to stop the match and return true.
 * Argument 'delim' gives the function additional chars to
 * stop the matching and return true with.
 * @delim: delimiters to stop the match on
 * @s1: string on
 * @s2: string two
 *
 * Return: 1 if match, 0 if no match.
 */

int string_match(char *s1, char *s2, char *delim)
{
	int a;

	if (s1 == NULL || s2 == NULL || delim == NULL)
		return (0);

	for (a = 0; s1[a] == s2[a]; a++)
	{
		if (char_match(s1[a], delim))
		{
			return (1);
		}
	}

	if (char_match(s1[a], delim) || char_match(s2[a], delim))
	{
		return (1);
	}
	return (0);
}


/**
 * char_match - Find if char matches any given needles
 * Description: Returns true if char 'c' is a match fo any charactr in needles,
 * including \0. Therefore it is always a match if 'c' is \0. By design.
 * @needles: string to search for matching char
 * @c: char to match
 *
 * Return: 1 if match, 0 if no match.
 */

int char_match(char c, char *needles)
{
	if (needles == NULL)
	{
		return (0);
	}

	do {
		if (c == *needles)
		{
			return (1);
		}
	} while (*needles++);

	return (0);
}
