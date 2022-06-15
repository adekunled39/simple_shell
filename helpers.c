#include "shell.h"

/**
 * _strlen - checks the length of a string
 * @str: the string to check
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
int i;

i = 0;
while (str[i] != '\0' && str[i] != '\n')
{
i++;
}
return (i);
}

/**
 * alloc_char_mem - alloc mem for arr of str
 * @len: the length to alloc
 *
 * Return: a pointer to the new arr.
 */

char **alloc_char_mem(int len)
{
int i, size;
char **arr;

size = sizeof(char) * len;
arr = malloc(size);
if (arr == NULL)
{
return (NULL);
}
for (i = 0; i < len; i++)
{
arr[i] = malloc(sizeof(char));
if (arr[i] == NULL)
{
while (i >= 0)
{
free(arr[i]);
i--;
}
free(arr);
return (NULL);
}
}

return (arr);
}


/**
 * alloc_char - alloc mem for a pointer to string
 * @str: The string to alloc
 * @len: the length of str
 *
 * Return: a pointer to the new mem.
 */
char *alloc_char(char *str, int len)
{
str = malloc(sizeof(char) * len);
if (str == NULL)
{
free(str);
perror("malloc error");
return (NULL);
}
return (str);
}

/**
 * free_char_mem - frees a malloc'd buff
 * @buff: The buff to free
 *
 * Return: nothing
 */
void free_char_mem(char **buff)
{
unsigned int i;

for (i = 0; buff[i]; i++)
{
free(buff[i]);
}
free(buff);
}
/**
 * free_char - frees malloc'd char strings
 * @line: a buffer
 * @path: path buffer
 * @value: buffer
 * @cmd: command buff
 *
 * Return: nothing
 */
void free_char(char *line, char *path, char *value, char *cmd)
{
free(line);
free(path);
free(value);
free(cmd);
}
