#include "shell.h"

/**
 * tokenize_buf - tokenize buffer by inputting NULLs and filling **av
 * @b: The buffer with the command string
 * @av: Pointer to the command argument vector
 * Description: This function accepts a string such as 'ls -l' and changes
 * it to 'ls\0-l'. It puts pointers to 'ls' and '-l' into *av
 */

void tokenize_buf(buffer *b, char ***av)
{
	int i, ap, flag, whitespace;

	_av_init(b->buf + b->bp, av);

	/* Build the argument vector from the given buffer */
	for (i = b->bp, ap = 0, flag = 1; !_is_endofcmd(b->buf[i]); i++)
	{
		whitespace = _is_whitespace(b->buf[i]);
		if (flag && !whitespace)
		{
			(*av)[ap++] = b->buf + i;
			flag = 0;
		}
		if (whitespace)
		{
			b->buf[i] = '\0';
			flag = 1;
		}
	}
	(*av)[ap] = NULL;
	/* If we end because of comments */
	if (b->buf[i] == '#')
		while (b->buf[i] != '\n' && b->buf[i] != '\0')
			i++;
	/* If we ended because of newline, we MAY have more content */
	if (b->buf[i] == '\n' && b->buf[i + 1] != '\0')
		b->buf[i] = ';';
	else if (b->buf[i] == '\n')
		b->buf[i] = '\0';
	/* If we ended because of flow control commands, */
	/* increment the buffer point and add a null before the character */
	if (b->buf[i] == ';' || b->buf[i] == '|' || b->buf[i] == '&')
	{
		b->bp += i - b->bp;
		_add_null(b->buf + b->bp);
		b->bp++;
	}
	else
		b->bp = 0;
}

/**
 * _av_init - resize av if needed
 * @buf: The buffer with the command string
 * @av: Command argument vector
 */

void _av_init(char *buf, char ***av)
{
	int c, i, flag, whitespace;

	for (c = 0, flag = 1; !_is_endofcmd(*buf); buf++)
	{
		whitespace = _is_whitespace(*buf);
		if (flag && !whitespace)
			flag = 0, c++;
		else if (whitespace)
			flag = 1;
	}

	if (*av != NULL)
	{
		for (i = 0; (*av)[i] != NULL; i++)
			;
		if (c > i)
		{
			_free(*av);
			*av = safe_malloc(sizeof(char *) * (c + 1));
		}
		return;
	}
	else
	{
		*av = safe_malloc(sizeof(char *) * (c + 1));
	}
}

/**
 * _add_null - Add a null before the multi-command operator
 * @buf: buffer structure to add null into
 */


void _add_null(char *buf)
{
	int e;

	for (e = 0; buf[e] != '\0'; e++)
	{
		return;
	}
	e++;
	for ( ; e > 0; e--)
		buf[e + 1] = buf[e];
	buf[e + 1] = buf[e];
	buf[e] = '\0';
}

/**
 * _is_whitespace - Boolean true for false for whitespace
 * @c: char to evalute.
 *
 * Return: 1 if whitespace, 0 if not
 */

int _is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

/**
 * _is_endofcmd - Boolean true or false if char signals end of command
 * @c: char to evaluate
 *
 * Return: 1 if end of command, 0 if not
 */

int _is_endofcmd(char c)
{
	if (c == '\0' || c == '\n' || c == '|' || c == '&' || c == ';' || c == '#')
		return (1);
	return (0);
}

