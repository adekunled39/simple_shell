#include "shell.h"

/**
 * break_path - breaks the path env into an array of strings
 * @path: the path env var;
 *
 * Return: the dirs in the path
 */

char **break_path(char *path)
{
char **token;
int i, p_len;
i = 0;
if (!path)
{
return (NULL);
}
p_len = _strlen(path);
token = alloc_char_mem(p_len);
token[0] = strtok(path, ":");
while (token[i])
{
i++;
token[i] = strtok(NULL, ":");
}
return (token);
}


/**
 * concat_arg - concats path with command
 * @path: the path arg
 * @cmd: the command to add
 * @buff: the buff to concat into
 *
 * Return: a pointer to the buff
 */
char *concat_arg(char *path, char *cmd, char *buff)
{
int i, j;

i = 0;
while (path[i])
{
buff[i] = path[i];
i++;
}
buff[i] = '/';
i += 1;
for (j = 0; cmd[j]; j++, i++)
{
buff[i] = cmd[j];
}
return (buff);
}


/**
 * check_dir_permission - checks if a dir exists and contain a file
 * @dir_arr: an arr of dir to check
 * @command: the file to look for
 *
 * Return: the path if found, null on error
 */
char *check_dir_permission(char **dir_arr, char *command)
{
char *path_buf;
int i, dir_len, cmd_len, ok_f = 0, ok_x = 0;
cmd_len = _strlen(command);
for (i = 0; dir_arr[i]; i++)
{
dir_len = _strlen(dir_arr[i]);
path_buf = alloc_char(path_buf, (cmd_len + dir_len + 1));
path_buf = concat_arg(dir_arr[i], command, path_buf);
ok_f = access(path_buf, F_OK);
ok_x = access(path_buf, X_OK);
if (ok_f == 0 && ok_x == 0)
{
return (path_buf);
}
}
free(path_buf);
free(dir_arr);
return (NULL);
}
