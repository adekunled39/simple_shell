#include "shell.h"

/**
 * execute - executes a command
 * @argv: args vector
 * @av: the main program name
 * @env: an array of env vars
 *
 * Return: 0 on success, -1 on error
 */

int execute(char **argv, char **av, char **env)
{
pid_t child_pid;
int status;
child_pid = fork();
if (child_pid < 0)
{
perror("Error");
free_char_mem(argv);
return (-1);
}
if (child_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
{
free_char_mem(argv);
perror(av[0]);
return (-1);
}
}
else
{
wait(&status);
}
return (0);
}


/**
 * break_cmd - breaks cmd into array of str
 * @arg_mem: malloc'd mem
 * @command: the command to break
 *
 * Return: a pointer to the array
 */

char **break_cmd(char **arg_mem, char *command)
{
int i;
arg_mem[0] = strtok(command, " ");
i = 0;
while (arg_mem[i] != NULL)
{
i++;
arg_mem[i] = strtok(NULL, " ");
}
arg_mem[i] = NULL;
return (arg_mem);
}

/**
 * manage_line - set the line to an arr of cmd
 * @line: the imputed line
 * @cmd_buf: the buff to copy the cmd into
 *
 * Return: an array of str containing cmd
 */
char **manage_line(char *line, char *cmd_buf)
{
char *ex;
char **argv;
int i, j, stop;
ex = "exit\n";
if (line[0] == '\n')
{
free(cmd_buf);
free(line);
exit(-1);
}
for (i = 0; line[i]; i++)
{
if (line[i] == ex[i])
{
stop = 1;
}
else
{
stop = 0;
}
}
if (stop)
{
free(cmd_buf);
free(line);
exit(-1);
}
cmd_buf = alloc_char(line, (_strlen(line) + 1));
for (i = 0, j = _strlen(line); j > 0; j--, i++)
{
cmd_buf[i] = line[i];
}
argv = alloc_char_mem(_strlen(cmd_buf));
argv = break_cmd(argv, cmd_buf);
return (argv);
}
