#include "shell.h"

/**
 * main - creates a simple shell
 * @av: arg count
 * @ac: arg vector
 * @env: an arr of env variables
 *
 * Return: Always 0
 */
int main(int ac, char *av[], char **env)
{
int resp;
(void)ac;
write(1, "($) ", 4);
resp = _getline(av, env);

return (resp);
}

/**
 * _getline - get a line from stdin and set it to a command
 * @av: the arg vector
 * @env: the env variables
 *
 * Return: 0 on succes, -1 on error
 */
int _getline(char **av, char **env)
{
int read, envs, exec_stat;
size_t len;
char *line, **argv, **path_dirs, *value, *path, *cmd;
len = 0, line = NULL;
cmd = "tmp";
while ((read = getline(&line, &len, stdin) != -1))
{
cmd = alloc_char(line, _strlen(line));
argv = manage_line(line, cmd);
envs = check_env(argv[0]);
if (envs)
{
value = _getenv("PATH", env);
path_dirs = break_path(value);
path = check_dir_permission(path_dirs, argv[0]);
if (path != NULL)
{
argv[0] = path;
}
else
{
free_char(line, path, value, cmd);
free_char_mem(argv);
perror(av[0]);
exit(1);
}
}
exec_stat = execute(argv, av, env);
if (exec_stat < 0)
{
free_char(line, path, value, cmd);
free_char_mem(path_dirs);
}
write(1, "($) ", 4);
free_char_mem(argv);
}
return (0);
}
