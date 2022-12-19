#include "shell.h"

/**
 * add_cmdhist - add new command to the history linked list
 * @cmd: command to put into the history
 * @history: history linked list
 * Description: Adds the new command to the end of the linked
 * list, keeps count on how many entries there are in the list,
 * if the list execeeds, 4096, then the head will pop off
 */

void add_cmdhist(hist_t *history, char *cmd)
{
	static int hist_index = 1;
	char *new_cmd;
	int w, len;
	hist_t *temp;

	new_cmd = safe_malloc(sizeof(char) * _strlen(cmd) + 1);
	temp = history;

	if (hist_index == 1)
	{
		for (temp = history; temp != NULL; temp = temp->next)
		{
			hist_index++;
		}
	}
	len = _strlen(cmd);

	for (w = 0; w < len - 1; w++)
	{
		new_cmd[w] = cmd[w];
	}
	new_cmd[w] = '\0';

	if (len > 1)
	{
		add_history(history, new_cmd);
	}
	hist_index++;
	_free(new_cmd);
}

/**
 * write_history - writing the history linked list to the file
 * simple_shell_history
 * @history: history link list to find what to write in
 * @envp: environemental variable linked list to find the path of file
 *
 * Return: 0 if success and 1 if failed to find path for file
 */

int  write_history(env_t *envp, hist_t *history)
{
	char *path;
	int fd, count;
	hist_t *temp, *temp_c;

	count = 0;
	history = history->next;

	for (temp_c = history; temp_c != NULL; temp_c = temp_c->next)
		count++;
	if (count > 4096)
	{
		count = count - 4096;
		while (count > 0)
		{
			history = history->next;
			count--;
		}
	}
	path = safe_malloc(sizeof(char) * BUFSIZE);
	_memset(path, '\0', BUFSIZE);
	path = rm_vname(envp, "HOME=", BUFSIZE);
	if (path == NULL)
	{
		_write("Error: failed to find history file\n");
		_write("Cannot write history\n");
		return (1);
	}
	_strcat(path, "/.simple_shell_history");
	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	for (temp = history; temp != NULL; temp = temp->next)
	{
		write(fd, temp->cmd, _strlen(temp->cmd));
		write(fd, "\n", 1);
	}
	_free(history);
	close(fd);
	return (0);
}
