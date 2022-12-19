#include "shell.h"

/**
 * hsh_env - builtin command hsh_env, mimics sh builtin envp
 * @envp: environmental variables to print
 * @arg_list: arguement list vectors
 *
 * Return: 0 if success
 */

int hsh_env(char **arg_list, env_t *envp)
{
	int h;

	if (arg_list[1] == NULL)
	{
		print_env(envp);
		return (0);
	}

	for (h = 1; arg_list[h] != NULL; h++)
	{
		arg_list[h - 1] = arg_list[h];
	}
	arg_list[h - 1] = arg_list[h];
	return (1);
}

/**
 * hsh_env_help - builtin help printout for envp
 *
 * Return: Always 0
 */

int hsh_env_help(void)
{
	_write("env usage: env\n    Prints out the current envirornment.\n");
	return (0);
}
