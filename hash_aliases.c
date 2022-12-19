#include "shell.h"

/**
 * hsh_alias - builtin for alias function
 * @env_p: env list
 * @mode: Execution mode for the program, 0 or !0
 * @argv: argument vector
 * Description: Complicated parent function for the alias functionality
 * of hsh. Uses two modes to allow it being called from
 * multiple points from within our program.
 *
 * Return: 0 on success, 2 on failure.
 */

int hsh_alias(char **argv, env_t *env_p, int mode)
{
	int retrn;
	static alias list = {NULL, NULL, NULL};
	(void) env_p;

	if (mode == 0)
	{
		argv[0] = hsh_alias_search(&list, argv[0]);
		return (0);
	}
	else
	{
		if (argv[1] == NULL)
			retrn = hsh_alias_printall(&list);
		else if (argv[2] != NULL)
		{
			_write("Error. Too many arguments.");
			return (2);
		}
		else
		{
			retrn = hsh_alias_print(&list, argv);

			if (retrn == 1)
				retrn = hsh_alias_add(&list, argv);
		}
	}
	return (retrn);
}

/**
 * hsh_alias_search - find alias values matching their key
 * @arg: alias to search for
 * @list: alias linked list
 *
 * Return: matching alias value, or NULL
 */

char *hsh_alias_search(alias *list, char *arg)
{
	while (list != NULL && list->key != NULL)
	{
		if (_str_match_strict(arg, list->key))
			return (list->value);
		list = list->next;
	}
	return (NULL);
}

/**
 * hsh_alias_printall - printout the full alias list
 * @list: alias linked list
 *
 * Return: Always 0
 */

int hsh_alias_printall(alias *list)
{
	while (list != NULL && list->key != NULL)
	{
		_write("alias ");
		_write(list->key);
		_write("='");
		_write(list->value);
		_write("'\n");
		list = list->next;
	}
	return (0);
}

/**
 * hsh_alias_print - print out an alias if match found
 * @argv: argument vector
 * @list: alias linked list
 *
 * Return: 1 if no match needed, 2 on alias not found, 0 on success
 */

int hsh_alias_print(alias *list, char **argv)
{
	char *value;

	value = _strstr(argv[1], "=");

	if (value != NULL)
	{
		return (1);
	}

	value = hsh_alias_search(list, argv[1]);

	if (value == NULL)
	{
		_write("alias not found\n");
		return (2);
	}
	else
	{
		_write("alias ");
		_write(argv[1]);
		_write("='");
		_write(value);
		_write("'\n");
	}
	return (0);
}

/**
 * hsh_alias_add - add, edit, or print alias in the list
 * @list: alias linked list
 * @argv: argument vector
 *
 * Return: Always 0
 */

int hsh_alias_add(alias *list, char **argv)
{
	char *key, *value;
	int b, v;
	alias *newnode;

	value = _strstr(argv[1], "=");

	if (value != NULL)
		value += 1;

	value = _strdup(value);

	for (b = 0; argv[1][b] != '='; b++)
		;
	key = safe_malloc(sizeof(char) * (b + 1));

	for (v = 0; v < b; v++)
		key[v] = argv[1][v];
	key[v] = '\0';

	while (list->next != NULL && !_str_match_strict(key, list->key))
		list = list->next;

	if (list->key == NULL || _str_match_strict(key, list->key))
	{
		list->key = key;
		list->value = value;
	}
	else if (list->next == NULL)
	{
		newnode = safe_malloc(sizeof(alias));
		newnode->key = key;
		newnode->value = value;
		newnode->next = NULL;
		list->next = newnode;
	}
	else
		list->value = value;
	return (0);


}
