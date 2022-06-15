#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
int _strlen(char *str);
char **alloc_char_mem(int len);
void free_char_mem(char **buff);
int _getline(char **av, char **env);
char **break_cmd(char **arg_mem, char *command);
int execute(char **argv, char **av, char **env);
int check_env(char *cmd);
char *_getenv(char *name, char **env);
char **break_path(char *path);
char *alloc_char(char *str, int len);
char *check_dir_permission(char **dir_arr, char *command);
char *concat_arg(char *path, char *cmd, char *buff);
char **manage_line(char *line, char *cmd_buf);
void free_char(char *line, char *path, char *value, char *cmd);
#endif /* SHELL_H */
