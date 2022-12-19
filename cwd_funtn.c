#include "shell.h"

/**
 * cd_path - function to return the path to change directory
 * @arg_list: arg list given by user (directory to change to)
 * @buf_size: size of the buffer
 * @envp: environemental linked list to find HOME and OLDPWD
 *
 * Return: returns the path to change,
 * returns NULL if HOME or OLDPWD is not found
 */

char *cd_path(char **arg_list, env_t *envp, int buf_size)
{
	int e, g;
	char *path;

	path = safe_malloc(sizeof(char) * buf_size);
	_memset(path, '\0', buf_size);
	e = g = 1;

	if (arg_list[1] != NULL)
	{
		e = _strcmp(arg_list[1], "~");
		g = _strcmp(arg_list[1], "-");
	}
	if (arg_list[1] == NULL || e == 0)
	{
		path = get_env_value(envp, "HOME=");
		if (path == NULL)
		{
			_write("Error: variable Home not found\n");
			return (NULL);
		}
	}
	else if (arg_list[1] != NULL && g == 0)
	{
		path = get_env_value(envp, "OLDPWD=");
		if (path == NULL)
		{
			_write("Error: variable OLDPWD not found\n");
			return (NULL);
		}
		_write(path), _write("\n");
	}
	else if (arg_list[1][0] == '/')
		path = arg_list[1];
	else
	{
		getcwd(path, buf_size);
		_strcat(path, "/");
		_strcat(path, arg_list[1]);
	}
	return (path);
}
